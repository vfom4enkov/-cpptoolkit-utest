cmake_minimum_required(VERSION 3.05)

project(cpptoolkit-test)

option(INCLUDE_EXAMPLE "Build the example" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB HEADERS "include/cpptoolkit/test/*.h" "include/cpptoolkit/test/tool/*.h")
file(GLOB SOURCES "src/*.cpp")

add_library(cpptoolkit-test ${HEADERS} ${SOURCES})
target_include_directories(cpptoolkit-test PUBLIC "${PROJECT_SOURCE_DIR}/include")
set_target_properties(cpptoolkit-test PROPERTIES LINKER_LANGUAGE CXX)

if (INCLUDE_EXAMPLE)
    add_subdirectory("example")
endif (INCLUDE_EXAMPLE)
