#include "Server.h"
#include <sys/socket.h>

void Server::SendGameState() {
  // MOCK DATA
  char buffor[10];
  strcpy(buffor, "TEST");
}
void Server::Receive() {
  // MOCK DATA
  char buffor[10];
  sockaddr_in client_address;

  recvfrom(socket_fd, &buffor, sizeof(buffor), 0, &client_address,
           &server_address_len);
}
void Server::Communicate() {
  pid_t receiver = fork();
  if (receiver == 0) {
    while (true) {
      ReceiveUserInput();
    }
  } else {
    while (true) {
      SendGameState();
    }
  }
}
