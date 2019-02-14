cmake_minimum_required(VERSION 3.5)

project(server)
message(STATUS "Compiling Network Function : ${PROJECT_NAME}")
set(CMAKE_CXX_STANDARD 11)

message(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

# set a build diractory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#set a bin directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# add all necessary libs
add_subdirectory(../utility_library bin_utility)


# add all include paths
# include_directories(${PROJECT_SOURCE_DIR})
include_directories(../utility_library/)


add_executable(${PROJECT_NAME} src/server.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g")

target_link_libraries(${PROJECT_NAME} libUTIL)
