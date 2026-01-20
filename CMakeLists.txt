cmake_minimum_required(VERSION 4.0)

project(test1)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(test1 show.cpp)

target_link_libraries( test1 ${OpenCV_LIBS} )

