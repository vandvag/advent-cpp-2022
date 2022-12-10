cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
project(advent-cpp-2022 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(advent-cpp-2022 main.cpp
    src/Utils.cpp
    src/Utils.hpp
        src/Grid.cpp
        src/Grid.hpp
    src/Day01.cpp
    src/Day01.hpp
    src/Day02.cpp
    src/Day02.hpp
    src/Day03.cpp
    src/Day03.hpp
    src/Day04.cpp
    src/Day04.hpp
    src/Day05.cpp
    src/Day05.hpp
    src/Day06.cpp
    src/Day06.hpp
    src/Day07.cpp
    src/Day07.hpp
        src/Day08.hpp
        src/Day08.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
