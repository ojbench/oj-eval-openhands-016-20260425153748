
cmake_minimum_required(VERSION 3.10)
project(FileStorageBPT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Werror")

add_executable(code src/main.cpp src/bptree.cpp)
target_include_directories(code PRIVATE src)
