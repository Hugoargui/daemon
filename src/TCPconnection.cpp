#include "TCPconnection.hpp"
#include <sys/socket.h>
#include <ctime>
#include <iostream>
#include <string>
#include "asio/streambuf.hpp"

std::string createResponse(const std::string& command) {
  if (command == "ram") {
    return "THIS IS MY RAM";
  } else if (command == "cpu") {
    return "THIS IS MY CPU";
  } else {
    return "unknown command";
  }
}

std::shared_ptr<TCPconnection> TCPconnection::create(
    asio::io_context& io_context) {
  return std::shared_ptr<TCPconnection>(new TCPconnection(io_context));
}

void TCPconnection::handle_client() {

  while (true) {

    // std::cout << "received connection from client" << std::endl;

    asio::streambuf received_data;
    // std::cout << "waiting to read data from client" << std::endl;
    asio::read_until(m_socket, received_data, "\n");
    // std::cout << "received some data" << std::endl;
    std::istream input(&received_data);
    std::string received_command;
    std::getline(input, received_command);
    // std::cout << "received data: " << received_command << std::endl;

    m_message = createResponse(received_command);
    std::cout << "sending response " << m_message << std::endl;
    asio::async_write(m_socket, asio::buffer(m_message),
                      std::bind(&TCPconnection::handle_write,
                                shared_from_this(), asio::placeholders::error,
                                asio::placeholders::bytes_transferred));
  }
}

void TCPconnection::handle_write(const std::error_code& error,
                                 size_t bytes_transferred) {
  std::cout << "inside handle write";
}
