cmake_minimum_required(VERSION 3.5)

project(ClientTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Test Network)

add_executable(ClientTest
    client.cpp
    client.h
    test_client.cpp
    test_client.h
    ui_client.h
)

target_link_libraries(ClientTest Qt5::Core Qt5::Widgets Qt5::Test Qt5::Network)

