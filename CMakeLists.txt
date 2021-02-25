cmake_minimum_required(VERSION 3.2...3.16)

project(Geometry)

set(CMAKE_CXX_STANDARD 17)

add_library(ShapeParser ShapeParser.cpp ShapeParser.h)

add_executable(Geometry main.cpp)
INCLUDE_DIRECTORIES(include ${CMAKE_SOURCE_DIR}/*.h)
target_link_libraries(Geometry ShapeParser)