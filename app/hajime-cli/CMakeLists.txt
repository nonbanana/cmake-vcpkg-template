project(hajime-cli LANGUAGES CXX VERSION 0.1.0)

cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(hajime-cli
    main.cpp
)
target_link_libraries(hajime-cli PRIVATE
    hajime::hajime
    spdlog::spdlog
    CLI11::CLI11
)