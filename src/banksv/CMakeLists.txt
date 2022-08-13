project(${BANKSV})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/ubftab)
add_executable(${PROJECT_NAME} banksv.c)
target_link_libraries(${PROJECT_NAME} atmisrv atmi ubf nstd rt dl m)

