cmake_minimum_required(VERSION 3.20)

project(PollCallback)

file(GLOB_RECURSE SOURCES
    src/*.c
)

add_executable(poll_callback ${SOURCES})