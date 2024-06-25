#include "../config.h"
#include "Connection.h"

class Server : public Connection {
private:
  std::vector<sockaddr_in> clients_address;

public:
  Server(const char *address, const size_t port) : Connection(address, port){};
  void Communicate();

private:
  void SendGameState();
  void ReceiveUserInput();
};
