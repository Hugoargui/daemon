#include "TCPserver.hpp"

using asio::ip::tcp;

TCPserver::TCPserver(asio::io_context& io_context)
    : m_ioContext(io_context),
      TCPacceptor(io_context, tcp::endpoint(tcp::v4(), PORT)) {
  start_accept();
}

void TCPserver::start_accept() {
  auto new_connection = TCPconnection::create(m_ioContext);

  TCPacceptor.async_accept(
      new_connection->socket(),
      std::bind(&TCPserver::handle_accept, this, new_connection,
                asio::placeholders::error));
}

void TCPserver::handle_accept(std::shared_ptr<TCPconnection> new_connection,
                              const std::error_code& error) {
  if (!error) {
    new_connection->handle_client();
    // TODO: here we enter infinite loop so we can't handle more than one client.
    // Use either detached threads per client (assmuning we won't have many clients)
    // Or go the async way and have just a vector of clients and handle them in non blocking way
  }

  this->start_accept();
}
