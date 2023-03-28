cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 17)

project(typespeed_iu)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c"
        )

add_executable(typespeed_iu ${all_SRCS})

target_link_libraries(typespeed_iu ${CURSES_LIBRARY})