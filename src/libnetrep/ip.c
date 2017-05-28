#include "ip.h"
#include <netinet/ip.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <inttypes.h>


void print_iphdr(struct iphdr *iph) {
    // todo (@kris-nova) dynamically size this and make more resilient
    printf("\n");
    printf("\n");
    printf("----------------------- [ IP HEADER ] ---------------------------");
    printf("\n");
    printf("\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|   %d  |   %d  |       %d       |                %d               |\n", iph->version, iph->ihl, iph->tos, iph->tot_len);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|             %d          |     |             %d           |\n", htonl(1), 0);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|      %d    |        %d        |              %d             |\n", 255, IPPROTO_TCP, iph->check);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|                          %"PRIu32"                             |\n", iph->saddr);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|                        %"PRIu32"                             |\n", iph->daddr);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("|                         %d                     |               |\n", 0);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\n");
    printf("\n");
}

