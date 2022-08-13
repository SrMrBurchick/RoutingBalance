cmake_minimum_required (VERSION 3.1)
project("Balance DB")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(system_include)
include_directories(ubftab)
add_library(server ${CMAKE_SOURCE_DIR}/../src/banksv/banksv.c)
