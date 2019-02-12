cmake_minimum_required(VERSION 3.5)

include_directories(include/)

file(GLOB UTIL_SRC src/*.cpp)

add_library(libUTIL STATIC ${UTIL_SRC})
