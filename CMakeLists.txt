cmake_minimum_required(VERSION 3.0)
project(treadmill-t2-biomodel CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

file(GLOB_RECURSE sources include/**.cpp)
file(GLOB_RECURSE headers include/**.h)

add_library(bioModel ${sources} ${headers})

add_executable(parser ${CMAKE_CURRENT_SOURCE_DIR}/source/parser.cc)
target_link_libraries(parser bioModel)
