set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_library(service
    iendurox_service.cpp
    router_service.cpp
    balance_service.cpp
)

if (NOT COMPILE_COMMANDS)
    link_directories(${CMAKE_SOURCE_DIR}/src/ecpg_database)

    target_link_libraries(service ecpg_database)
endif()
