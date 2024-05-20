set(MODULE_NAME server)

set(SOURCES
        src/ConnectionManager.cpp
        src/LocalConnectionManager.cpp
        src/UDPManager.cpp
        )

set(HEADERS
        include/${MODULE_NAME}/ConnectionManager.hpp
        include/${MODULE_NAME}/LocalConnectionManager.hpp
        include/${MODULE_NAME}/UDPManager.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)