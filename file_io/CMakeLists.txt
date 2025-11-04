cmake_minimum_required(VERSION 3.28)
project(file_io)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.c")

add_executable(file_io ${SOURCES})