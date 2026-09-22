import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.*;

public class PrettyFw extends GhidraScript {

    static final long BASE = 0x287A0L, SIZE = 125030L;
    final Map<Address,String> strAt = new HashMap<>();   // string address -> content

    public void run() throws Exception {
        String outDir = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp";

        for (int i = 0; i < 6; i++) if (sweepCallTargets() == 0) break;
        println("PrettyFw: thumb sweep +" + sweepThumb());

        collectAndRenameStrings();
        println("PrettyFw: " + strAt.size() + " strings labelled with their contents");
        println("PrettyFw: named " + nameFromStrings() + " functions from strings");
        println("PrettyFw: labelled " + nameRomStubs() + " ROM entry points");
        println("PrettyFw: printf candidates -> " + detectPrintf());

        dump(outDir);
    }

    /* ---------- discovery ---------- */
    private int sweepCallTargets() throws Exception {
        Listing lst = currentProgram.getListing();
        List<Address> t = new ArrayList<>();
        for (Instruction ins : iter(lst.getInstructions(true))) {
            if (!ins.getMnemonicString().toLowerCase().startsWith("bl")) continue;
            for (Address a : ins.getFlows()) if (getFunctionContaining(a) == null) t.add(a);
        }
        int n = 0;
        for (Address a : t) {
            if (getFunctionContaining(a) != null) continue;
            try {
                if (lst.getInstructionAt(a) == null) disassemble(a);
                if (lst.getInstructionAt(a) != null && createFunction(a, null) != null) n++;
            } catch (Exception ignored) { }
        }
        return n;
    }

    private int sweepThumb() throws Exception {
        Memory mem = currentProgram.getMemory();
        Listing lst = currentProgram.getListing();
        AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Register tm = currentProgram.getRegister("TMode");
        int n = 0;
        for (long off = 0; off + 2 <= SIZE; off += 2) {
            Address a = sp.getAddress(BASE + off);
            if (lst.getInstructionAt(a) != null || lst.getDefinedDataAt(a) != null) continue;
            if (getFunctionContaining(a) != null) continue;
            int hw;
            try { hw = mem.getShort(a) & 0xFFFF; } catch (Exception e) { continue; }
            if ((hw & 0xFF00) != 0xB500) continue;
            try {
                if (tm != null) currentProgram.getProgramContext().setValue(tm, a, a.add(1), BigInteger.ONE);
                disassemble(a);
                if (lst.getInstructionAt(a) != null && createFunction(a, null) != null) n++;
            } catch (Exception ignored) { }
        }
        return n;
    }

    /* ---------- strings: label each with its own text ---------- */
    private void collectAndRenameStrings() throws Exception {
        Set<String> used = new HashSet<>();
        for (Data d : iter(currentProgram.getListing().getDefinedData(true))) {
            String s = null;
            try {
                StringDataInstance sd = StringDataInstance.getStringDataInstance(d);
                if (sd != null) s = sd.getStringValue();
            } catch (Exception ignored) { }
            if (s == null || s.trim().length() < 2) continue;
            strAt.put(d.getAddress(), s);
            String nm = "str_" + sanitize(s, 44);
            for (int i = 2; !used.add(nm); i++) nm = "str_" + sanitize(s, 40) + "_" + i;
            try { createLabel(d.getAddress(), nm, true); } catch (Exception ignored) { }
        }
    }

    private static String sanitize(String s, int max) {
        StringBuilder b = new StringBuilder();
        boolean us = false;
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) { b.append(c); us = false; }
            else if (!us && b.length() > 0) { b.append('_'); us = true; }
            if (b.length() >= max) break;
        }
        String r = b.toString().replaceAll("_+$", "");
        if (r.isEmpty()) r = "s";
        if (Character.isDigit(r.charAt(0))) r = "s" + r;
        return r;
    }

    /* ---------- function names from debug strings ---------- */
    private static final Pattern IDENT = Pattern.compile("^[A-Za-z_][A-Za-z0-9_]{3,}");

    private int nameFromStrings() throws Exception {
        ReferenceManager rm = currentProgram.getReferenceManager();
        Map<Function,Map<String,Integer>> votes = new HashMap<>();
        for (var e : strAt.entrySet()) {
            Matcher m = IDENT.matcher(e.getValue().trim());
            if (!m.find()) continue;
            String cand = m.group();
            if (cand.length() < 4 || isNoise(cand)) continue;
            for (Reference r : rm.getReferencesTo(e.getKey())) {
                Function f = getFunctionContaining(r.getFromAddress());
                if (f != null) votes.computeIfAbsent(f, k -> new HashMap<>()).merge(cand, 1, Integer::sum);
            }
        }
        Set<String> used = new HashSet<>();
        int n = 0;
        for (var e : votes.entrySet()) {
            Function f = e.getKey();
            if (!f.getName().startsWith("FUN_")) continue;
            String best = null; int bv = -1;
            for (var c : e.getValue().entrySet()) {
                int v = c.getValue() * 100 + c.getKey().length();
                if (v > bv) { bv = v; best = c.getKey(); }
            }
            if (best == null) continue;
            String nm = best;
            for (int i = 2; !used.add(nm); i++) nm = best + "_" + i;
            try { f.setName(nm, SourceType.ANALYSIS); n++; } catch (Exception ignored) { }
        }
        return n;
    }

    private static boolean isNoise(String s) {
        String l = s.toLowerCase();
        return l.equals("aqirys") || l.startsWith("bbbb") || l.equals("entry")
            || l.equals("address") || l.equals("alert") || l.equals("null")
            || l.equals("true") || l.equals("false");
    }

    /* ---------- ROM entry points below the image ---------- */
    private int nameRomStubs() throws Exception {
        int n = 0;
        for (Function f : iter(currentProgram.getFunctionManager().getFunctions(true))) {
            long a = f.getEntryPoint().getOffset();
            if (a < BASE && f.getName().startsWith("FUN_")) {
                try { f.setName(String.format("rom_%05X", a), SourceType.ANALYSIS); n++; } catch (Exception ignored) { }
            }
        }
        return n;
    }

    /* ---------- which function is the debug printf? ---------- */
    private String detectPrintf() throws Exception {
        Map<Function,Integer> score = new HashMap<>();
        Listing lst = currentProgram.getListing();
        for (Instruction ins : iter(lst.getInstructions(true))) {
            if (!ins.getMnemonicString().toLowerCase().startsWith("bl")) continue;
            Function callee = null;
            for (Address a : ins.getFlows()) { callee = getFunctionAt(a); if (callee != null) break; }
            if (callee == null) continue;
            Instruction p = ins;
            for (int k = 0; k < 6 && p != null; k++) {
                p = p.getPrevious();
                if (p == null) break;
                boolean hit = false;
                for (Reference r : p.getReferencesFrom())
                    if (strAt.containsKey(r.getToAddress())) { hit = true; break; }
                if (hit) { score.merge(callee, 1, Integer::sum); break; }
            }
        }
        List<Map.Entry<Function,Integer>> top = new ArrayList<>(score.entrySet());
        top.sort((x, y) -> y.getValue() - x.getValue());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Math.min(3, top.size()); i++) {
            Function f = top.get(i).getKey();
            int c = top.get(i).getValue();
            if (c < 15) break;
            String nm = i == 0 ? "dbg_printf" : "dbg_printf_" + (i + 1);
            sb.append(nm).append("=").append(f.getName()).append("(").append(c).append(" sites) ");
            if (f.getName().startsWith("FUN_") || f.getName().startsWith("rom_")) {
                try { f.setName(nm, SourceType.ANALYSIS); } catch (Exception ignored) { }
            }
        }
        return sb.length() == 0 ? "none" : sb.toString();
    }

    /* ---------- emit ---------- */
    private void dump(String outDir) throws Exception {
        new File(outDir).mkdirs();
        DecompInterface di = new DecompInterface();
        DecompileOptions op = new DecompileOptions();
        op.setMaxWidth(100);
        di.setOptions(op);
        di.toggleCCode(true);
        di.openProgram(currentProgram);

        PrintWriter c = new PrintWriter(new BufferedWriter(new FileWriter(outDir + "/firmware.c"), 1 << 20));
        PrintWriter meta = new PrintWriter(new BufferedWriter(new FileWriter(outDir + "/meta.tsv")));
        meta.println("addr\tname\tsize\tcallers\tcallees\tstrings");

        List<Function> fns = new ArrayList<>();
        for (Function f : iter(currentProgram.getFunctionManager().getFunctions(true))) fns.add(f);
        println("PrettyFw: decompiling " + fns.size());

        int done = 0;
        for (Function f : fns) {
            if (monitor.isCancelled()) break;
            List<String> callers = new ArrayList<>(), callees = new ArrayList<>(), strs = new ArrayList<>();
            for (Function x : f.getCallingFunctions(monitor)) callers.add(x.getName());
            for (Function x : f.getCalledFunctions(monitor)) callees.add(x.getName());
            for (Address a : f.getBody().getAddresses(true)) {
                Instruction ins = currentProgram.getListing().getInstructionAt(a);
                if (ins == null) continue;
                for (Reference r : ins.getReferencesFrom()) {
                    String s = strAt.get(r.getToAddress());
                    if (s != null && !strs.contains(s)) strs.add(s);
                }
            }
            Collections.sort(callers); Collections.sort(callees);

            String body = null;
            try {
                DecompileResults r = di.decompileFunction(f, 60, monitor);
                if (r != null && r.getDecompiledFunction() != null) body = r.getDecompiledFunction().getC();
            } catch (Exception ignored) { }

            c.println("/* " + rep('=', 74));
            c.println(" * " + f.getName() + "   @ 0x" + f.getEntryPoint()
                      + "   (" + f.getBody().getNumAddresses() + " bytes)");
            if (!callers.isEmpty()) c.println(" * called by : " + join(callers, 6));
            if (!callees.isEmpty()) c.println(" * calls     : " + join(callees, 6));
            for (String s : strs) c.println(" * string    : \"" + s.replace("\n", "\\n").replace("\r", "\\r") + "\"");
            c.println(" */");
            c.println(body == null ? "/* decompilation failed */" : body);
            c.println();

            meta.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + f.getBody().getNumAddresses()
                         + "\t" + String.join(";", callers) + "\t" + String.join(";", callees)
                         + "\t" + String.join(" | ", strs)
                               .replace("\t", " ").replace("\n", "\\n").replace("\r", "\\r"));
            if (++done % 250 == 0) println("PrettyFw:   " + done + "/" + fns.size());
        }
        c.close(); meta.close(); di.dispose();
        println("PrettyFw: wrote " + done + " functions");
    }

    private static String rep(char ch, int n) { return String.valueOf(ch).repeat(n); }

    private static String join(List<String> l, int max) {
        if (l.size() <= max) return String.join(", ", l);
        return String.join(", ", l.subList(0, max)) + ", ... (+" + (l.size() - max) + " more)";
    }

    private static <T> Iterable<T> iter(Iterator<T> it) { return () -> it; }
}
