set(MODULE_NAME connection)

set(SOURCES
        #src/ConcreteSendRec.cpp
        src/LocalSendRec.cpp
        )


set(HEADERS
        include/${MODULE_NAME}/AbstractSendRec.hpp
        #include/${MODULE_NAME}/ConcreteSendRec.hpp
        include/${MODULE_NAME}/LocalSendRec.hpp
        )

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

#target_link_libraries(${MODULE_NAME}
#        PUBLIC
#            wgs_server
#        )