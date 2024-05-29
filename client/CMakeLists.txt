cmake_minimum_required(VERSION 3.14)
project(ChatClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Network REQUIRED)

add_executable(client
    main.cpp
    client.cpp
    encryption/hamming.cpp
)

target_link_libraries(client Qt5::Widgets Qt5::Network)

add_subdirectory(tests)
