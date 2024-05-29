cmake_minimum_required(VERSION 3.5)

project(ChatServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Network REQUIRED)

add_executable(server
    main.cpp
    server.cpp
    server.h
)

target_link_libraries(server PRIVATE Qt5::Core Qt5::Network)
