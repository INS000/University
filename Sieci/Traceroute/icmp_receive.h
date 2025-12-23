// Maksymilian Kochan - 340213


void print_as_bytes (unsigned char* buff, ssize_t length);

long long count_time(struct timespec start, struct timespec end);

int receive_icmp(int sock_fd, int ttl, int pid, char ip_list[3][INET_ADDRSTRLEN], long long times[3]);
