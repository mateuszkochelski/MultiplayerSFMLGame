#include "../config.h"
#pragma once

class Connection {
private:
  sockaddr_in server_address;
  int socket_fd;
  socklen_t server_address_len;

public:
  Connection(const char *address, const size_t port);
  virtual void Send(const char *message) const = 0;
  virtual void Receive(char *message) const = 0;
  ~Connection();
};
