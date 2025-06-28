#include "TCPserver.hpp"
#include <iostream>

void foo() {
  std::cout << "hello from server\n";
}

int main(int argc, char* argv[]) {
  foo();
  return 0;
}
