set(MODULE_NAME game)

set(SOURCES
        src/Game.cpp
        src/Graph.cpp
        )


set(HEADERS
        include/${MODULE_NAME}/Game.hpp
        include/${MODULE_NAME}/Graph.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_edges
            wgs_actions_blackjack
            wgs_actions_common
            wgs_actions_bridge
            wgs_components
            wgs_conditions_blackjack
            wgs_conditions_common
            wgs_conditions_bridge
            wgs_connection
        )