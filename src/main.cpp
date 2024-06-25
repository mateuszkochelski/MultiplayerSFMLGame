#include "config.h"
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <sys/socket.h>
int main() {
  auto server_fd = socket(AF_INET, SOCK_DGRAM, 0);
  auto server_address{
      sockaddr_in{AF_INET, htobe16(8080), inet_addr("127.0.0.1")}};
  bind(server_fd, reinterpret_cast<sockaddr *>(&server_address),
       sizeof(server_address));
  auto window = sf::RenderWindow{{1920u, 1080u}, "CMake SFML Project"};
  auto x = socklen_t(sizeof(server_address));
  char napis[20];
  strcpy(napis, "KOMUNICATION\0");
  printf("%s", napis);
  auto err = sendto(server_fd, &napis, sizeof(napis), 0,
                    reinterpret_cast<sockaddr *>(&server_address), x);
  window.setFramerateLimit(144);
  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    window.clear();
    window.display();
  }
}
