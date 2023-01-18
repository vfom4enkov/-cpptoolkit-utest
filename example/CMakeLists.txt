cmake_minimum_required(VERSION 3.05)

file(GLOB SOURCES "*.cpp")
add_executable(cpptoolkit-test-example ${SOURCES})
target_link_libraries(cpptoolkit-test-example cpptoolkit-test)

