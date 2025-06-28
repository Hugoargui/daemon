#include "TCPclient.hpp"
#include <iostream>

void bar() {
  std::cout << "hello from client\n";
}

int main(int argc, char* argv[]) {
  bar();
  return 0;
}
