cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(APPLICATION_NAME voting_booth)

project(${APPLICATION_NAME})

add_executable(${APPLICATION_NAME} "main.cpp")
target_link_libraries(${APPLICATION_NAME} LINK_PUBLIC voting)
#target_compile_options(${APPLICATION_NAME} PUBLIC
#	-pedantic -Wall -Wextra -Wconversion -g)
set_target_properties(${APPLICATION_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

