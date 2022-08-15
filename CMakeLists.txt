cmake_minimum_required (VERSION 3.1)
project("Supper Mega Bank")

set(CMAKE_CXX_STANDARD 20)

if (NOT DEFINED COMPILE_COMMANDS)
    set(COMPILE_COMMANDS OFF CACHE BOOL "enable EXPORT_COMMANDS functionality")
else()
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    include_directories(${CMAKE_SOURCE_DIR}/system_include)
endif()

include_directories(${CMAKE_SOURCE_DIR}/ubftab)
add_subdirectory(src)
