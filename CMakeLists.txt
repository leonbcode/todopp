cmake_minimum_required(VERSION 3.22)
project(todopp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(todopp src/main.cpp src/task.cpp src/todo.cpp)

install(TARGETS todopp)