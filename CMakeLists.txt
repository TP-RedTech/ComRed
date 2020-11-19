cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(Utils)
add_subdirectory(ServerApplication)
add_subdirectory(HTTPServer)
add_subdirectory(DB)
