cmake_minimum_required(VERSION 3.10)
project("LoginSystem")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

add_executable("${PROJECT_NAME}" ${SOURCES})
