cmake_minimum_required(VERSION 3.20)

project(cpptoolkit-utest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

add_library(cpptoolkit-utest ${HEADERS} ${SOURCES})
target_include_directories(cpptoolkit-utest PUBLIC "${PROJECT_SOURCE_DIR}/include")
set_target_properties(cpptoolkit-utest PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory("example")

