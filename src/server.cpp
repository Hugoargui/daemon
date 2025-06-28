#include <asio.hpp>
#include <iostream>
#include "TCPserver.hpp"

int main() {
  using asio::ip::tcp;

  try {
    asio::io_context io_context;
    TCPserver server(io_context);
    io_context.run();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
