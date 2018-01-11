cmake_minimum_required(VERSION 3.8)
project(Assignment2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES1 Task2a.c cmake-build-debug/Task2btest.c)
add_executable(Assignment2a ${SOURCE_FILES1})

set(SOURCE_FILES2 Task2b.c)
add_executable(Assignment2b ${SOURCE_FILES2})

set(SOURCE_FILES3 Task2bTest.c)
add_executable(Assignment2c ${SOURCE_FILES3})
