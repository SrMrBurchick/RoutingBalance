set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/service)

add_subdirectory(service)
add_executable(${ROUTER} router.c)
add_executable(${BALANCE} balance.c)

add_library(services services.cpp)

if (NOT COMPILE_COMMANDS)
    target_link_libraries(services service)

    target_link_libraries(${ROUTER} atmisrv atmi ubf nstd rt dl m services)
    target_link_libraries(${BALANCE} atmisrv atmi ubf nstd rt dl m services)
endif()
