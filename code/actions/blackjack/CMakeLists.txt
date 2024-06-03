set(CHILDREN_MODULE_NAME blackjack)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/DoubleAndReturnPlayersBetAction.cpp
        src/DoublePlayersBetAction.cpp
        src/GetBetFromPlayerAction.cpp
        src/PlayerSplitsAction.cpp
        src/ReturnHalfOfPlayerBetAction.cpp
        src/ReturnPlayerBetAction.cpp
        src/BlackjackRestartAction.cpp
        )


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/DoubleAndReturnPlayersBetAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/DoublePlayersBetAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/GetBetFromPlayerAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerSplitsAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/ReturnHalfOfPlayerBetAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/ReturnPlayerBetAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/BlackjackRestartAction.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
        wgs_edges
        wgs_components
        )