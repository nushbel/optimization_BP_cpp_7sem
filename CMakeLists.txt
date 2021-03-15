cmake_minimum_required(VERSION 3.16)
project(optimization_BP)

set(CMAKE_CXX_STANDARD 14)

add_executable(optimization_BP main.cpp Function.cpp Function.h stopCrit.cpp stopCrit.h area.cpp area.h gradientDescent.cpp gradientDescent.h optimizationMethod.cpp optimizationMethod.h randomSearch.cpp randomSearch.h)