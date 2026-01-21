cmake_minimum_required(VERSION 4.0)

project(test3)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(test3 show.cpp
        tools.h)

target_link_libraries( test3 ${OpenCV_LIBS} )
