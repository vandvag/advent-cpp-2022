cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(advent-cpp-2022 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(advent-cpp-2022 main.cpp
    src/Day01.cpp
    src/Day01.hpp
    src/Day02.cpp
    src/Day02.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
