cmake_minimum_required(VERSION 3.26)
project(pp_forth)

set(CMAKE_CXX_STANDARD 17)

add_executable(pp_forth main.cpp
        Reader.cpp
        Writer.cpp
        NormalMode.cpp
        SecretMode.cpp)
