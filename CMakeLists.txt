cmake_minimum_required(VERSION 3.20)

project(cpptoolkit-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_library(cpptoolkit-test ${HEADERS} ${SOURCES})
target_include_directories(cpptoolkit-test PUBLIC "${PROJECT_SOURCE_DIR}/include")
set_target_properties(cpptoolkit-test PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory("example")

