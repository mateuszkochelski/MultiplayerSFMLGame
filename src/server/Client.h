#include "../config.h"
#include "Connection.h"

class Client : public Connection {
private:
  Client(const char *address, const size_t port) : Connection(address, port){};
};
