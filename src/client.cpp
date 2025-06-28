#include "TCPserver.hpp"

#include <array>
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

int main(int argc, char* argv[]) {
  try {
    asio::io_context io_context;

    tcp::resolver resolver(io_context);
    constexpr int port = 13;
    auto endpoints = resolver.resolve("localhost", std::to_string(port));

    tcp::socket socket(io_context);
    asio::connect(socket, endpoints);

    while (true) {
      std::array<char, 128> buf;
      std::error_code error;

      const size_t len = socket.read_some(asio::buffer(buf), error);

      if (error == asio::error::eof)
        break;  // Connection closed cleanly by host.
      else if (error)
        throw std::system_error(error);  // Some other error.

      std::cout.write(buf.data(), len);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
