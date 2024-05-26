set(CHILDREN_MODULE_NAME bridge)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/AuctionToContinueCondition.cpp
        src/CurrentTricksIsFullCondition.cpp
        )


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/AuctionToContinueCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/CurrentTricksIsFullCondition.hpp)

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_edges
            wgs_components
        )