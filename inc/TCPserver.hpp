#pragma once

#include <asio.hpp>
#include <memory>

#include "TCPconnection.hpp"

using asio::ip::tcp;

class TCPserver {
 public:
  TCPserver(asio::io_context& io_context);

 private:
  void start_accept();

  void handle_accept(std::shared_ptr<TCPconnection> new_connection,
                     const std::error_code& error);

  asio::io_context& m_ioContext;
  tcp::acceptor TCPacceptor;

  static constexpr size_t PORT = 13;
};
