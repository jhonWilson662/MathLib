cmake_minimum_required(VERSION 3.10)
project(MathLib)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(math_test 
    src/Matrix.cpp 
    test/test_matrix.cpp
)