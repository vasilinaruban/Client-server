cmake_minimum_required(VERSION 3.5)

project(Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Network Widgets Test REQUIRED)

# Основной клиент
set(CLIENT_SOURCES
    client.cpp
    main.cpp
)

set(CLIENT_UI
    client.ui
)

qt5_wrap_ui(UI_HEADERS ${CLIENT_UI})

add_executable(Client
    ${CLIENT_SOURCES}
    ${UI_HEADERS}
)

target_link_libraries(Client Qt5::Core Qt5::Network Qt5::Widgets)

# Тесты клиента
set(TEST_SOURCES
    test_client.cpp
)

qt5_wrap_cpp(MOC_SOURCES ${TEST_SOURCES})

add_executable(ClientTest
    ${TEST_SOURCES}
    ${UI_HEADERS}
    ${MOC_SOURCES}
)

target_link_libraries(ClientTest Qt5::Core Qt5::Network Qt5::Widgets Qt5::Test)

# Для автоматической генерации MOC файлов
set_target_properties(ClientTest PROPERTIES AUTOMOC ON)

