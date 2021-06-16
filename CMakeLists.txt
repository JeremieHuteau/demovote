cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(best_project_name)

include(CTest)

add_subdirectory(voting)
add_subdirectory(booth)

