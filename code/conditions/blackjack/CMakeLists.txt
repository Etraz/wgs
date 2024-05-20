set(CHILDREN_MODULE_NAME blackjack)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/CurrentPlayerIsXCondition.cpp
        src/HandScoreAtLeastXCondition.cpp
        src/HandSizeUnderXCondition.cpp
        src/PlayerCanBetCondition.cpp
        src/PlayerCanDoubleBetCondition.cpp
        src/PlayerCanSplitCondition.cpp
        src/PlayerHaveNon0BetCondition.cpp
        src/RelationBetweenPlayerAndDealerHandCondition.cpp
        )


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/CurrentPlayerIsXCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/HandScoreAtLeastXCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/HandSizeUnderXCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerCanBetCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerCanDoubleBetCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerCanSplitCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/PlayerHaveNon0BetCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/RelationBetweenPlayerAndDealerHandCondition.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_edges
            wgs_components
        )