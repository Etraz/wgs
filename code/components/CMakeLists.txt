set(MODULE_NAME components)

set(SOURCES
        src/ChipsComponent.cpp
        src/Component.cpp
        src/ComponentProvider.cpp
        src/ConnectionComponent.cpp
        src/HandsComponent.cpp
        src/PlayerComponent.cpp
        src/cards/CardDeck.cpp
        src/cards/CardHolder.cpp
        src/cards/PlayingCard.cpp
        src/BridgeAuctionComponent.cpp
        src/cards/BridgeCall.cpp src/BridgeTricksComponent.cpp)


set(HEADERS
        include/${MODULE_NAME}/ChipsComponent.hpp
        include/${MODULE_NAME}/Component.hpp
        include/${MODULE_NAME}/ComponentProvider.hpp
        include/${MODULE_NAME}/ConnectionComponent.hpp
        include/${MODULE_NAME}/HandsComponent.hpp
        include/${MODULE_NAME}/PlayerComponent.hpp
        include/${MODULE_NAME}/cards/Card.hpp
        include/${MODULE_NAME}/cards/CardDeck.hpp
        include/${MODULE_NAME}/cards/CardHolder.hpp
        include/${MODULE_NAME}/cards/PlayingCard.hpp
        include/${MODULE_NAME}/BridgeAuctionComponent.hpp
        include/${MODULE_NAME}/cards/BridgeCall.hpp
        include/${MODULE_NAME}/BridgeTricksComponent.hpp)

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(wgs_${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include PRIVATE src)

target_link_libraries(${MODULE_NAME}
        PUBLIC
        wgs_connection
        )