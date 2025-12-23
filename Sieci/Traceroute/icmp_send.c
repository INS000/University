// Maksymilian Kochan - 340213

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdint.h>
#include <unistd.h>

#include "icmp_checksum.h"
#include "icmp_send.h"




void send_icmp(int ttl, int sockfd, struct sockaddr_in recipient, pid_t pid)
{
    int i = 3 * ttl;

    int socket = setsockopt (sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
    if( socket < 0 )
    {
        ERROR("Blad setsockopt");
    }

    for(int j = i; j < i + 3; j++)
    {
        struct icmp header;
        header.icmp_type = ICMP_ECHO;
        header.icmp_code = 0;
        header.icmp_hun.ih_idseq.icd_id = htons(pid & 0xffff);
        header.icmp_hun.ih_idseq.icd_seq = htons(j);
        header.icmp_cksum = 0;
        header.icmp_cksum = compute_icmp_checksum ((u_int16_t*)&header, sizeof(header));

        ssize_t bytes_sent = sendto (
            sockfd,
            &header,
            sizeof(header),
            0,
            (struct sockaddr*)&recipient,
            sizeof(recipient)
        );

        if(bytes_sent < 0)
        {
            ERROR("Blad sendto");
        }
    }
}


