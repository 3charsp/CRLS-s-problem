cmake_minimum_required(VERSION 3.0)

project(RANDIXSORT)

include_directories(include)

add_executable(main main.c src/radix_sort.c)