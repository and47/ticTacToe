cmake_minimum_required(VERSION 3.10)

project(ticTacToe_my_no_AI)

add_executable(ticTacToe_my_no_AI main.cpp funs.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_compile_features(ticTacToe_my_no_AI PRIVATE cxx_std_17)

enable_testing()

add_subdirectory(test)

add_library(ticTacToe STATIC funs.cpp funs.hpp)
