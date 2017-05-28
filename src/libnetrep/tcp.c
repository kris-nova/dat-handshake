#include "tcp.h"
#include <netinet/tcp.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <inttypes.h>

void print_tcphdr_rfc793(struct tcphdr *tcph) {

printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|          Source Port          |       Destination Port        |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|                        Sequence Number                        |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|                    Acknowledgment Number                      |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|  Data |           |U|A|P|R|S|F|                               |\n");
printf("| Offset| Reserved  |R|C|S|S|Y|I|            Window             |\n");
printf("|       |           |G|K|H|T|N|N|                               |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|           Checksum            |         Urgent Pointer        |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|                    Options                    |    Padding    |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
printf("|                             data                              |\n");
printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
}