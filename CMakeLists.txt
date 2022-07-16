cmake_minimum_required(VERSION 3.10)
project("LoginSystem")

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

add_executable("${PROJECT_NAME}" ${SOURCES})
