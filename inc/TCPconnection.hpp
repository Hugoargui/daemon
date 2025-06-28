#pragma once

#include <asio.hpp>
#include <memory>
#include <string>

using asio::ip::tcp;

std::string createResponse();

class TCPconnection : public std::enable_shared_from_this<TCPconnection> {
 public:
  static std::shared_ptr<TCPconnection> create(asio::io_context& io_context);

  void start();

  tcp::socket& socket() { return m_socket; }

 private:
  TCPconnection(asio::io_context& io_context) : m_socket(io_context) {}

  void handle_write(const std::error_code& error, size_t bytes_transferred) {}

  tcp::socket m_socket;
  std::string m_message;
};
