set(ROUTER "ROUTER_SERVICE")
set(BALANCE "BALANCE_SERVICE")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ecpg_database)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/servers)

add_subdirectory(ecpg_database)
add_subdirectory(servers)
