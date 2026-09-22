import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.lang.Register;
import java.math.BigInteger;

public class PreFw extends GhidraScript {
    public void run() throws Exception {
        long BASE = 0x287A0L;
        var mem = currentProgram.getMemory();
        var af  = currentProgram.getAddressFactory().getDefaultAddressSpace();

        // Regions the image references but does not contain.
        addBlk(mem, af, "FLASH_LOW", 0x00000000L, 0x287A0L);   // bootloader / lower flash
        addBlk(mem, af, "RAM",       0x00400000L, 0x00020000L); // SRAM (copy-table targets)
        addBlk(mem, af, "PERIPH",    0x00800000L, 0x00100000L); // peripheral window

        // Vector table is ARM; make sure TMode=0 across the stub.
        Register tmode = currentProgram.getRegister("TMode");
        Address vt = af.getAddress(BASE);
        if (tmode != null) {
            currentProgram.getProgramContext().setValue(
                tmode, vt, af.getAddress(BASE + 0xFF), BigInteger.ZERO);
        }
        disassemble(vt);
        createFunction(vt, "_vector_table");
        addEntryPoint(vt);

        // Reset handler, from vector[0]'s literal at +0x20.
        long reset = mem.getInt(af.getAddress(BASE + 0x20)) & 0xFFFFFFFFL;
        println("PreFw: reset handler = 0x" + Long.toHexString(reset));
        Address ra = af.getAddress(reset);
        if (tmode != null) {
            currentProgram.getProgramContext().setValue(tmode, ra, ra.add(0x200), BigInteger.ZERO);
        }
        disassemble(ra);
        createFunction(ra, "Reset_Handler");
        addEntryPoint(ra);

        // The seven B-stubs at +0x40 are ARM too.
        for (int i = 0; i < 7; i++) {
            Address a = af.getAddress(BASE + 0x40 + 4L * i);
            disassemble(a);
            createFunction(a, "_exc_stub_" + i);
        }
        // Let the ARM analyzer work harder at finding stray Thumb code.
        try {
            setAnalysisOption(currentProgram, "ARM Aggressive Instruction Finder", "true");
            setAnalysisOption(currentProgram, "Aggressive Instruction Finder", "true");
            setAnalysisOption(currentProgram, "Decompiler Switch Analysis", "true");
        } catch (Exception e) { println("PreFw: analysis opts: " + e.getMessage()); }
        println("PreFw: setup done");
    }

    private void addBlk(ghidra.program.model.mem.Memory mem,
                        ghidra.program.model.address.AddressSpace af,
                        String name, long start, long len) {
        try {
            MemoryBlock b = mem.createUninitializedBlock(name, af.getAddress(start), len, false);
            b.setRead(true); b.setWrite(true); b.setExecute(true);
            println("PreFw: block " + name + " @ 0x" + Long.toHexString(start));
        } catch (Exception e) {
            println("PreFw: block " + name + " skipped: " + e.getMessage());
        }
    }
}
