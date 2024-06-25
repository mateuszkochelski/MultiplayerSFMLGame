#include <arpa/inet.h>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>
#define CHECK(expr, x)                                                         \
  ({                                                                           \
    int result = (expr);                                                       \
    if (result == x) {                                                         \
      perror(#expr);                                                           \
      exit(1);                                                                 \
    }                                                                          \
    result;                                                                    \
  })
