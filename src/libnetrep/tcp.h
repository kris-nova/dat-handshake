#include <netinet/tcp.h>

#ifndef LIBNETREP_TCP
#define LIBNETREP_TCP

void print_tcphdr_rfc793(struct tcphdr *tchp);

#endif