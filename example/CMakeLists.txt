cmake_minimum_required(VERSION 3.20)

file(GLOB SOURCES "*.cpp")
add_executable(cpptoolkit-utest-example ${SOURCES})
target_link_libraries(cpptoolkit-utest-example cpptoolkit-utest)

