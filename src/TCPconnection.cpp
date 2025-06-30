#include "TCPconnection.hpp"
#include <sys/socket.h>
#include <ctime>
#include <iostream>
#include <string>
#include "asio/streambuf.hpp"
#include "cpu_ram_calculator.hpp"

std::string createResponse(const std::string& command) {
  if (command == "ram") {
    return calculateRAM();
  } else if (command == "cpu") {
    return calculateCPU();
  } else {
    return "Unknown command";
  }
}

std::shared_ptr<TCPconnection> TCPconnection::create(
    asio::io_context& io_context) {
  return std::shared_ptr<TCPconnection>(new TCPconnection(io_context));
}

void TCPconnection::handle_client() {

  while (true) {

    asio::streambuf received_data;
    // TODO: make this async
    std::error_code ec;
    auto result = asio::read_until(m_socket, received_data, "\n", ec);

    // To gracefully handle client disconnection
    if (ec == asio::error::eof) {
      break;
    } else if (ec) {
      throw std::runtime_error("client terminated abnormally");
    }

    std::istream input(&received_data);
    std::string received_command;
    std::getline(input, received_command);

    m_message = createResponse(received_command);
    asio::async_write(m_socket, asio::buffer(m_message),
                      std::bind(&TCPconnection::handle_write,
                                shared_from_this(), asio::placeholders::error,
                                asio::placeholders::bytes_transferred));
  }
}

void TCPconnection::handle_write(const std::error_code& error,
                                 size_t bytes_transferred) {}
