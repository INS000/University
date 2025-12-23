// Maksymilian Kochan - 340213

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include <time.h>
#include <unistd.h>

#include "icmp_checksum.h"


void print_as_bytes(unsigned char *buff, ssize_t length)
{
    for (ssize_t i = 0; i < length; i++, buff++)
        printf("%.2x ", *buff);
}

long long count_time(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
}

int receive_icmp(int sock_fd, int ttl, int pid, char ip_list[3][INET_ADDRSTRLEN], long long times[3])
{
    struct pollfd fds = {sock_fd, POLLIN, 0};
    struct sockaddr_in sender;
    socklen_t sender_len = sizeof(sender);
    u_int8_t buffer[IP_MAXPACKET];
    int received = 0;

    struct timespec start, end, acttime, deadline;

    clock_gettime(CLOCK_MONOTONIC, &start);
    deadline.tv_sec = start.tv_sec + 1;
    deadline.tv_nsec = start.tv_nsec;

    while (received < 3)
    {
        clock_gettime(CLOCK_MONOTONIC, &acttime);
        int poll_res = poll(&fds, 1, count_time(acttime, deadline));
        if (poll_res > 0)
        {
            ssize_t packet_len = recvfrom(sock_fd, buffer, IP_MAXPACKET, 0, (struct sockaddr *)&sender, &sender_len);
            if (packet_len < 0)
                ERROR("Blad recvfrom");

            struct ip *ip_header = (struct ip *)buffer;
            ssize_t ip_header_len = 4 * (ssize_t)(ip_header->ip_hl);
            struct icmphdr *icmp_header = (struct icmphdr *)(buffer + ip_header_len);

            u_int16_t id, seq;
            if (icmp_header->type == ICMP_ECHOREPLY)
            {
                id = ntohs(icmp_header->un.echo.id);
                seq = ntohs(icmp_header->un.echo.sequence);
                if (id == (pid & 0xffff) && seq >= 3 * ttl && seq < 3 * ttl + 3)
                {
                    inet_ntop(AF_INET, &(sender.sin_addr), ip_list[seq - 3 * ttl], INET_ADDRSTRLEN);
                    received++;
                    clock_gettime(CLOCK_MONOTONIC, &end);
                    times[seq - 3 * ttl] = count_time(start, end);
                }
            }
            if (icmp_header->type == ICMP_TIME_EXCEEDED)
            {
                struct ip *ip_header_inner = (struct ip *)(buffer + ip_header_len + 8);
                ssize_t ip_header_len_inner = 4 * (ssize_t)(ip_header_inner->ip_hl);
                struct icmphdr *icmp_header_inner = (struct icmphdr *)((u_int8_t *)ip_header_inner + ip_header_len_inner);
                id = ntohs(icmp_header_inner->un.echo.id);
                seq = ntohs(icmp_header_inner->un.echo.sequence);
                if (id == (pid & 0xffff) && seq >= 3 * ttl && seq < 3 * ttl + 3)
                {
                    inet_ntop(AF_INET, &(sender.sin_addr), ip_list[seq - 3 * ttl], INET_ADDRSTRLEN);
                    received++;
                    clock_gettime(CLOCK_MONOTONIC, &end);
                    times[seq - 3 * ttl] = count_time(start, end);
                }
            }
        }
        else if (poll_res == 0)
        {
            break;
        }
        else
        {
            ERROR("Blad poll");
        }
    }
    return received;
}
