cmake_minimum_required(VERSION 3.1)

project(app)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall")
set(CMAKE_C_FLAGS "-g -O0 -Wall")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})