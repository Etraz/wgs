set(MODULE_NAME factories)

set(SOURCES
        src/BlackjackFactory.cpp
        )


set(HEADERS
        include/${MODULE_NAME}/BlackjackFactory.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})
add_dependencies(${MODULE_NAME} wgs_connection)

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_connection
            wgs_game
        )