cmake_minimum_required(VERSION 3.5)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp "heads/No309_Best Time to Buy and Sell Stock with Cooldown.h")

add_executable(LeetCode ${SOURCE_FILES})