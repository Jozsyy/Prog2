cmake_minimum_required(VERSION 3.20)
project(merge_quick_sort C)

set(CMAKE_C_STANDARD 99)

add_executable(merge_quick_sort main.c functions.c functions.h)
