set(CHILDREN_MODULE_NAME bridge)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/GetNextCallFromPlayerAction.cpp
        src/EndTrickAction.cpp
        src/CurrentPlayerPlaysCardAction.cpp
        src/CurrentPlayerStartsNewTrickAction.cpp
        src/BridgeDealAction.cpp
        src/BridgeRestartAction.cpp
        src/SendAfterGameInfoAction.cpp src/EndAuctionAction.cpp)


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/GetNextCallFromPlayerAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/EndTrickAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/CurrentPlayerPlaysCardAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/CurrentPlayerStartsNewTrickAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/BridgeDealAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/BridgeRestartAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/SendAfterGameInfoAction.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/EndAuctionAction.hpp)

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
        wgs_edges
        wgs_components
        )