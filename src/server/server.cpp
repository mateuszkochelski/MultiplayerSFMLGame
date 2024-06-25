#include "../config.h"
#include <cstdio>
#include <sys/socket.h>

int main() {

  auto server_fd = CHECK(socket(AF_INET, SOCK_DGRAM, 0), -1);
  auto server_address =
      sockaddr_in{AF_INET, htobe16(8080), inet_addr("127.0.0.1")};
  CHECK(bind(server_fd, reinterpret_cast<sockaddr *>(&server_address),
             sizeof(server_address)),
        -1);
  socklen_t x = sizeof(server_address);

  char message[20];
  while (true) {
    recvfrom(server_fd, &message, sizeof(char[20]), 0,
             reinterpret_cast<sockaddr *>(&server_address), &x);
    printf("DUPA:%s\n", message);
    fflush(stdout);
  }
  return 0;
}
