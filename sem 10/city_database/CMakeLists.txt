cmake_minimum_required(VERSION 3.22)
project(city_database)

set(CMAKE_CXX_STANDARD 17)

add_executable(city_database main.c
                             hash_table.h)