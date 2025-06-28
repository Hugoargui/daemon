cmake_minimum_required(VERSION 3.10)

project(daemon
        VERSION 0.0.1
        DESCRIPTION "Simple daemon to get CPU ussage and RAM"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works


add_executable(server)
add_executable(client)

target_sources(
    server
  PRIVATE
    # server.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCPserver.cpp
  )

target_sources(
    client
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TCPclient.cpp
    )
target_include_directories(
    server
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  )

target_include_directories(
    client
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
  )
