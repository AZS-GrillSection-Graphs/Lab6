cmake_minimum_required(VERSION 3.10)
project(PageRank)
set(EXECUTABLE_NAME "PageRank")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra")

include_directories(include/)

file(GLOB SOURCES "src/*.cpp")
add_executable(${EXECUTABLE_NAME} ${SOURCES})