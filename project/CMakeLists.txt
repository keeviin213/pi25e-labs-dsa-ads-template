cmake_minimum_required(VERSION 3.16)
project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(dsa INTERFACE)
target_include_directories(dsa INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(project main.cpp)
target_link_libraries(project PRIVATE dsa)

add_executable(project_tests tests.cpp)
target_link_libraries(project_tests PRIVATE dsa)