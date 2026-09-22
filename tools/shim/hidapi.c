/* Logging hidapi replacement: fakes an AQIRYS Zephyr so the vendor Update.exe
 * runs its real flashing sequence with nothing plugged in. Every call is
 * logged; responses are synthesised from our reconstructed protocol, so if the
 * tool runs to completion the reconstruction is confirmed. */
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define EXPORT __declspec(dllexport)

struct hid_device_info {
    char *path; unsigned short vendor_id, product_id;
    wchar_t *serial_number; unsigned short release_number;
    wchar_t *manufacturer_string, *product_string;
    unsigned short usage_page, usage; int interface_number;
    struct hid_device_info *next;
};

static FILE *L;
static void lg_open(void){ if(!L){ L=fopen("hidlog.txt","w"); setvbuf(L,NULL,_IONBF,0);} }
static void hexdump(const char *tag, const unsigned char *b, int n){
    lg_open(); fprintf(L, "%s len=%d\n  ", tag, n);
    for(int i=0;i<n;i++){ fprintf(L,"%02x",b[i]); if((i&15)==15&&i+1<n) fprintf(L,"\n  "); else fprintf(L," "); }
    fprintf(L,"\n");
}

static unsigned char last_cmd[4096];
static int last_len = 0, last_is_write = 0;
static unsigned int last_addr = 0;

EXPORT int hid_init(void){ lg_open(); fprintf(L,"hid_init\n"); return 0; }
EXPORT const char* hid_version(void){ return "0.14.0"; }

static struct hid_device_info *mk(unsigned short vid, unsigned short pid,
                                  unsigned short up, unsigned short us){
    struct hid_device_info *d = calloc(1,sizeof *d);
    d->path = strdup("fake"); d->vendor_id=vid; d->product_id=pid;
    d->usage_page=up; d->usage=us; d->release_number=0x0114; d->next=NULL;
    return d;
}

EXPORT struct hid_device_info* hid_enumerate(unsigned short vid, unsigned short pid){
    lg_open(); fprintf(L,"hid_enumerate(vid=0x%04x, pid=0x%04x)\n", vid, pid);
    if(vid==0x1D57 && pid==0xFA61){
        struct hid_device_info *a = mk(vid,pid,0x0001,0x0002);   /* the mouse TLC  */
        a->next = mk(vid,pid,0x000B,0x0000);                     /* the config TLC */
        return a;
    }
    if(vid==0xA745 && pid==0x0033) return mk(vid,pid,0,0);
    return NULL;
}
EXPORT void hid_free_enumeration(struct hid_device_info *d){ (void)d; }

EXPORT void* hid_open_path(const char *p){
    lg_open(); fprintf(L,"hid_open_path(%s) -> handle\n", p?p:"(null)");
    return (void*)0x1234;
}

EXPORT int hid_send_feature_report(void *dev,const unsigned char *data,size_t len){
    (void)dev; hexdump("FEATURE >>", data,(int)len); return (int)len;
}

EXPORT int hid_write(void *dev,const unsigned char *data,size_t len){
    (void)dev; hexdump("WRITE   >>", data,(int)len);
    /* reassemble: reports carry [0x00][64 bytes of the HCI stream] */
    if(len>=2){
        const unsigned char *p = data+1;
        if(p[0]==0x01 && p[1]==0xE0 && p[2]==0xFC){ last_len=0; }
        if(last_len + 64 <= (int)sizeof last_cmd){ memcpy(last_cmd+last_len,p,64); last_len+=64; }
        if(last_cmd[0]==0x01&&last_cmd[1]==0xE0&&last_cmd[2]==0xFC){
            if(last_cmd[3]==0xFF){                       /* long form */
                unsigned char cmd = last_cmd[6+1-1+1];   /* 01 E0 FC FF F4 ll ll cmd */
                cmd = last_cmd[7];
                last_is_write = (cmd==0x07);
                if(cmd==0x07) memcpy(&last_addr,last_cmd+8,4);
                else          memcpy(&last_addr,last_cmd+9,4);
            }
        }
    }
    return (int)len;
}

EXPORT int hid_read(void *dev,unsigned char *data,size_t len){
    (void)dev; memset(data,0,len);
    unsigned char cmd = (last_cmd[3]==0xFF)? last_cmd[7] : last_cmd[4];
    if(cmd==0x0F){            /* erase: 04 0E FF 01 E0 FC F4 07 00 0F <op> <addr32> */
        /* ..0F | status | opcode | addr32 : the tool checks [11] and [12..15] */
        unsigned char r[]={0x04,0x0E,0xFF,0x01,0xE0,0xFC,0xF4,0x07,0x00,0x0F,0x00,last_cmd[8],0,0,0,0};
        memcpy(r+12,&last_addr,4); memcpy(data,r,sizeof r);
    } else if(cmd==0x07){     /* write: 04 0E FF 01 E0 FC F4 06 00 07 <addr32> */
        /* ..07 | status | addr32 : the tool checks [11..14] */
        unsigned char r[]={0x04,0x0E,0xFF,0x01,0xE0,0xFC,0xF4,0x06,0x00,0x07,0x00,0,0,0,0};
        memcpy(r+11,&last_addr,4); memcpy(data,r,sizeof r);
    } else if(cmd==0x10){     /* crc: 04 0E 08 01 E0 FC 10 <crc32> */
        unsigned char r[]={0x04,0x0E,0x08,0x01,0xE0,0xFC,0x10,0xAA,0xBB,0xCC,0xDD};
        memcpy(data,r,sizeof r);
    }
    hexdump("READ    <<", data, 16);
    return (int)len;
}

EXPORT void hid_close(void *d){ (void)d; }
EXPORT int hid_exit(void){ lg_open(); fprintf(L,"hid_exit\n"); return 0; }
