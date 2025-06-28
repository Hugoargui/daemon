#include "TCPconnection.hpp"
#include <ctime>
#include <string>

//- TODO: move to lambda
std::string createResponse() {
  std::time_t now = std::time(0);
  return std::ctime(&now);
}

std::shared_ptr<TCPconnection> TCPconnection::create(
    asio::io_context& io_context) {
  return std::shared_ptr<TCPconnection>(new TCPconnection(io_context));
}

void TCPconnection::start() {
  m_message = createResponse();

  asio::async_write(m_socket, asio::buffer(m_message),
                    std::bind(&TCPconnection::handle_write, shared_from_this(),
                              asio::placeholders::error,
                              asio::placeholders::bytes_transferred));
}
