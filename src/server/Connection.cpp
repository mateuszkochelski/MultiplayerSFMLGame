#include "Connection.h"
Connection::Connection(const char *address, const size_t port) {
  socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
  server_address = sockaddr_in{AF_INET, htobe16(port), inet_addr(address)};
  server_address_len = sizeof(server_address);
}
