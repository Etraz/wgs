set(MODULE_NAME edges)

set(SOURCES
        src/Edge.cpp
        )


set(HEADERS
        include/${MODULE_NAME}/Edge.hpp
        include/${MODULE_NAME}/Condition.hpp
        include/${MODULE_NAME}/Action.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
        wgs_components
        )