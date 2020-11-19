cmake_minimum_required(VERSION 3.10)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

include_directories("${PROJECT_SOURCE_DIR}/include")

<<<<<<< HEAD
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

=======
>>>>>>> e0035f28fff63db6beec71f00e41ee078ad3f621
file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        )

<<<<<<< HEAD
file(GLOB test_source
        "${PROJECT_SOURCE_DIR}/test/*.cpp"
        )

add_library(ServerApplication STATIC ${sources} src/Editor.cpp include/EditorManagerDelegate.h include/EditorListener.h)

add_executable(gtest ${test_source})
target_link_libraries(gtest  ServerApplication ${GTEST_LIBRARIES})
target_link_libraries(gtest -lgmock pthread)
=======
add_executable(backend main.cpp ${sources} src/Editor.cpp include/EditorManagerDelegate.h include/EditorListener.h)
>>>>>>> e0035f28fff63db6beec71f00e41ee078ad3f621
