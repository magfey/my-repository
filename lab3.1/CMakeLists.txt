cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME lab3.1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 20)

add_executable("${PROJECT_NAME}" main.cpp f.hpp f.cpp)

add_library(my_lib STATIC src/my_lib.cpp)

target_include_directories(my_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/inc)

target_link_libraries("${PROJECT_NAME}" my_lib)

target_include_directories("${PROJECT_NAME}" PRIVATE ${CMAKE_CURRENT_BINARY_DIR})