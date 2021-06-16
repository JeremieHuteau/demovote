cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIBRARY_NAME voting)

project(${LIBRARY_NAME})

set(SRC_DIR     "${CMAKE_CURRENT_LIST_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

file(GLOB SRC_FILES 
	CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")
file(GLOB HEADER_FILES 
	CONFIGURE_DEPENDS "${INCLUDE_DIR}/${LIBRARY_NAME}/*.hpp")

add_library(${LIBRARY_NAME} ${SRC_FILES} ${HEADER_FILES})
target_include_directories(${LIBRARY_NAME} 
	PRIVATE ${INCLUDE_DIR}/${LIBRARY_NAME})
target_include_directories(${LIBRARY_NAME} 
	PUBLIC ${INCLUDE_DIR})


###############################################################################
### TEST
###############################################################################

set(TEST_DIR "${CMAKE_CURRENT_LIST_DIR}/test")
file(GLOB TEST_FILES 
	CONFIGURE_DEPENDS "${TEST_DIR}/*_test.cpp")

include(FetchContent)
# googletest 1.10 release
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/703bd9caab50b139428cea1aaff9974ebee5742e.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_EXECUTABLE_NAME run_tests)
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_FILES})

target_link_libraries(${TEST_EXECUTABLE_NAME} gtest_main pthread ${LIBRARY_NAME})
target_include_directories(${TEST_EXECUTABLE_NAME} 
	PRIVATE ${INCLUDE_DIR} ${GTEST_INCLUDE_DIRS})
set_target_properties(${TEST_EXECUTABLE_NAME}
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_test(NAME TestSuite
	COMMAND ${TEST_EXECUTABLE_NAME})

