set(CHILDREN_MODULE_NAME common)
set(MODULE_NAME ${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME})

set(SOURCES
        src/AlwaysTrueCondition.cpp
        src/AndCondition.cpp
        src/NotCondition.cpp
        src/OrCondition.cpp
        src/HandSizeUnderXCondition.cpp
        )


set(HEADERS
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/AlwaysTrueCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/AndCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/NotCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/OrCondition.hpp
        include/${PARENT_MODULE_NAME}/${CHILDREN_MODULE_NAME}/HandSizeUnderXCondition.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${PARENT_MODULE_NAME}_${CHILDREN_MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
            wgs_edges
            wgs_components
        )