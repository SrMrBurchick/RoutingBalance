add_library(
    ecpg_database
    ecpg_database.cpp
)

if (NOT COMPILE_COMMANDS)
    message("HERE WE GO ${COMPILE_COMMANDS}")
    set(PGSQL_CMD "/usr/pgsql-14/bin/ecpg")
    set(PGSQL_ARG "ecpg_sql.pgc")
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/ecpg_sql.c
        COMMAND ${PGSQL_CMD} ${PGSQL_ARG}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${PGSQL_ARG}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

    include_directories(/usr/pgsql-14/include)

    add_library(ecpg_lib
        ecpg_sql.c
    )

    find_package(PostgreSQL REQUIRED)
    target_link_libraries(ecpg_lib ecpg pq)
    target_link_libraries(ecpg_database ecpg_lib)
endif()
