// Maksymilian Kochan - 340213

#include <stdlib.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/socket.h>
#include <poll.h>

#include "icmp_send.h"
#include "icmp_receive.h"
#include "icmp_checksum.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        ERROR("Podane polecenie niezgodne ze specyfikacja");
    }

    struct sockaddr_in recipient;
    memset(&recipient, 0, sizeof(recipient));
    recipient.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &recipient.sin_addr) <= 0)
    {
        ERROR("Niepoprawny adres IP");
    }

    pid_t pid = getpid();
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock_fd < 0)
    {
        ERROR("Blad socket");
    }

    short if_last_ip = 0;

    for (int ttl = 1; ttl <= 30; ttl++)
    {
        char ip_list[3][INET_ADDRSTRLEN];
        long long times[3];
        send_icmp(ttl, sock_fd, recipient, pid);

        int received = receive_icmp(sock_fd, ttl, pid, ip_list, times);

        printf("%d. ", ttl);
        if (received == 0)
        {
            printf("*\n");
        }
        else
        {
            for (int j = 0; j < received; j++)
            {
                if (strcmp(ip_list[j], inet_ntoa(recipient.sin_addr)) == 0)
                {
                    if_last_ip = 1;
                }
                if (j > 0)
                {
                    if (strcmp(ip_list[j], ip_list[j - 1]) == 0 || strcmp(ip_list[j], ip_list[0]) == 0)
                    {
                        continue;
                    }
                }
                printf("%s ", ip_list[j]);
            }
            if (received < 3)
            {
                printf("???\n");
            }
            else
            {
                int avg = (times[0] + times[1] + times[2]) / 3;
                printf(" %dms\n", avg);
            }
        }

        if (if_last_ip)
        {
            break;
        }
    }
    close(sock_fd);
    return 0;
}
