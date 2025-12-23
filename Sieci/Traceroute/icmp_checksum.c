// Maksymilian Kochan - 340213

#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "icmp_checksum.h"


u_int16_t compute_icmp_checksum(const void *buff, int length)
{
    const u_int16_t* ptr = buff;
    u_int32_t sum = 0;
    assert (length % 2 == 0);
    for (; length > 0; length -= 2)
        sum += *ptr++;
    sum = (sum >> 16U) + (sum & 0xffffU);
    return ~(sum + (sum >> 16U));
}

void ERROR(const char *str)
{
    fprintf(stderr, "%s: %s\n", str, strerror(errno)); // NOLINT(*-err33-c)
    exit(EXIT_FAILURE);
}
