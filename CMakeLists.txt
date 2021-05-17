CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
add_compile_options(-Wall -std=c++11)
PROJECT(homework2)
add_executable(homework2 src/homework2.cpp)
target_include_directories(homework2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

