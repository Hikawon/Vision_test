cmake_minimum_required(VERSION 4.0)

project(test2)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(test2 show.cpp)

target_link_libraries( test2 ${OpenCV_LIBS} )
