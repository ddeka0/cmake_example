#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>

int read_stream(int, uint8_t *, int);
int write_stream(int, uint8_t *, int);