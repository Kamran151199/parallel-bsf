cmake_minimum_required(VERSION 3.10)
project(parallel-bfs)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(parallel-bfs OpenMP::OpenMP_CXX)
endif()

add_executable(parallel-bfs main.cpp)
include_directories(/usr/local/include)
include_directories(/opt/homebrew/Cellar/gcc/14.1.0_2/include/)
