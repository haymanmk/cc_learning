cmake_minimum_required(VERSION 3.28.1)

add_library(Lib1 lib/lib_1.c)
add_library(Lib2 lib/lib_2.c)

add_executable(CommonSection main.c)

target_link_libraries(CommonSection Lib1 Lib2)

target_include_directories(CommonSection PUBLIC lib)