cmake_minimum_required(VERSION 3.21)
project(graph C)

set(CMAKE_C_STANDARD 99)

add_executable(graph main.c graph_header.h graph_lib.c)
