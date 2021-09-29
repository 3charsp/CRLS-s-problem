cmake_minimum_required(VERSION 3.0)

project(KSORT)

include_directories(include)

add_executable(main main.c src/k_sort.c)