cmake_minimum_required(VERSION 3.10)

project(daemon
        VERSION 0.0.1
        DESCRIPTION "Simple daemon to get CPU ussage and RAM"
        LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

add_executable(server)
add_executable(client)

add_library(asio INTERFACE)
# target_compile_options(asio INTERFACE ASIO_STANDALONE)
target_include_directories(asio INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/lib/asio-1.30.2/include)


target_sources(
    server
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCPserver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCPconnection.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/server.cpp
)
target_include_directories(
    server
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(
      server
      asio
)

target_sources(
    client
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCPclient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/client.cpp
)
target_include_directories(
    client
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(
      client
      asio
)

