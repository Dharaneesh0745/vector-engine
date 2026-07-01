cmake_minimum_required(VERSION 3.15)
project(vector_engine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vector_engine
    src/main.cpp
    src/vector_store.cpp
)

target_include_directories(vector_engine PRIVATE include)
