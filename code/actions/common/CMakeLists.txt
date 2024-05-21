set(CHILDREN_MODULE_NAME common)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/EmptyAction.cpp
        src/EndGameAction.cpp
        src/GoToNextPlayerAction.cpp
        src/MultiAction.cpp
        src/PlayerDrawsCardAction.cpp
        src/RestartAction.cpp
        src/SendMessageAction.cpp
        src/ShowPlayersHandAction.cpp
        )


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/EmptyAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/EndGameAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/GoToNextPlayerAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/MultiAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerDrawsCardAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/RestartAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/SendMessageAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/ShowPlayersHandAction.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_edges
            wgs_components
        )