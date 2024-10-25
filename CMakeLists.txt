cmake_minimum_required(VERSION 3.29)
project(c_task)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE LIB_SOURCES "lib/*.cpp" "lib/*.c" "lib/*.h")
add_library(c_task_lib ${LIB_SOURCES})
add_executable(c_task main.cpp)
target_link_libraries(c_task c_task_lib)

#Include GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_a test/test_a.cpp)
target_link_libraries(test_a gtest_main c_task_lib)
add_test(NAME test_a COMMAND test_a)


add_executable(test_task_graph test/test_task_graph.cpp)
target_link_libraries(test_task_graph gtest_main c_task_lib)
add_test(NAME TEST_TASK_GRAPH COMMAND TEST_TASK_GRAPH)
