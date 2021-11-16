cmake_minimum_required(VERSION 3.20)
project(bsi_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(bsi_exercise main.cpp headers/operations.h probability_insulators.cpp headers/probability_insulators.h operations.cpp manual_switches.cpp headers/manual_switches.h constant_failure_rate.cpp headers/constant_failure_rate.h)
