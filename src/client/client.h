#include <sys/types.h>

#ifndef TCP_CLIENT
#define TCP_CLIENT

char* localip();
char* remoteip();
unsigned short csum(unsigned short *ptr, int nbytes);

static char* NIVENLY_IP = "52.88.124.76";

struct tcp_header {
    u_int32_t source_address;
    u_int32_t dest_address;
    u_int8_t placeholder;
    u_int8_t protocol;
    u_int16_t tcp_length;
};

#endif