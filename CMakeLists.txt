cmake_minimum_required(VERSION 3.28)
project(Cursach0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cursach0 main.cpp
        Workload.cpp
        Workload.h
        Position.cpp
        Position.h
        Subject.cpp
        Subject.h
        center.cpp
        center.cpp
        center.h)
target_link_libraries(Cursach0 ${CMAKE_EXE_LINKER_FLAGS})
