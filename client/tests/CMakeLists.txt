cmake_minimum_required(VERSION 3.14)
project(ClientTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Test REQUIRED)

add_executable(client_tests
    client_tests.cpp
)

target_link_libraries(client_tests Qt5::Test)
