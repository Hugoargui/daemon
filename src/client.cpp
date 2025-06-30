#include "TCPserver.hpp"
#include "asio/streambuf.hpp"

#include <array>
#include <asio.hpp>
#include <iostream>

using asio::ip::tcp;

int main(int argc, char* argv[]) {
  try {
    asio::io_context io_context;

    tcp::resolver resolver(io_context);
    constexpr int port = 9191;
    auto endpoints = resolver.resolve("localhost", std::to_string(port));

    tcp::socket socket(io_context);
    asio::connect(socket, endpoints);

    while (true) {

      std::cout << "\nenter command to send (cpu or ram)\n > ";
      std::string data;
      std::cin >> data;

      std::system_error ec;
      auto result = asio::write(socket, asio::buffer(data + "\n"));

      std::array<char, 128> buf;
      std::error_code error;
      const size_t len = socket.read_some(asio::buffer(buf), error);

      if (error == asio::error::eof) {
        std::cout << "connection closed cleanly by host" << std::endl;
        break;  // Connection closed cleanly by host.
      } else if (error) {
        std::cerr << "connection NOT clossed cleanly by host" << std::endl;
        throw std::system_error(error);  // Some other error.
      }

      std::cout << "host reply: ";
      std::cout.write(buf.data(), len);
      std::cout << std::endl;
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
