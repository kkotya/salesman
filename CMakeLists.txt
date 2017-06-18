cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Salesman)

enable_testing()

set(CMAKE_BUILD_TYPE Release)

include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)