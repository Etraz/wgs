cmake_minimum_required(VERSION 3.22)
project(wgs)

set(CMAKE_CXX_STANDARD 20)

add_executable(server server.cpp
        src/Components/Cards/CardHolder.cpp
        src/Components/Cards/PlayingCard.cpp
        src/Components/Cards/DeckComponent.cpp
        src/Edges/Edge.cpp
        src/Edges/Conditions/BlackjackAtLeastXCondition.cpp
        src/Components/ComponentProvider.cpp
        src/Edges/Conditions/HandSizeUnderXCondition.cpp
        src/Edges/Actions/PlayerDrawsCardAction.cpp
        src/Edges/Conditions/AndCondition.cpp
        src/Components/ChipsComponent.cpp
        src/PlayerConnection.cpp
        src/Components/HandsComponent.cpp
        src/Components/ConnectionComponent.cpp
        src/Edges/Actions/GetBetFromPlayerAction.cpp
        src/Edges/Conditions/AlwaysTrueCondition.cpp
        src/Edges/Actions/DoublePlayersBetAction.cpp
        src/Edges/Actions/DoubleAndReturnPlayersBetAction.cpp
        src/Edges/Actions/PlayerDrawsReversedCardAction.cpp
        src/Graph.cpp
        src/Game.cpp
        src/Edges/Conditions/PlayerCanDoubleBetCondition.cpp
        src/Edges/Conditions/NotCondition.cpp
        src/Edges/Actions/EmptyAction.cpp
        src/Edges/Actions/ShowDealersCardsAction.cpp
        src/Edges/Conditions/RelationBetweenPlayerAndDealerHandCondition.cpp
        src/Edges/Actions/EndGameAction.cpp
        src/Edges/Actions/SendMessageAction.cpp
        src/Edges/Actions/RestartAction.cpp
        src/Edges/Actions/ReturnPlayerBetAction.cpp
        src/Edges/Conditions/PlayerCanBetCondition.cpp
        src/Server/ConnectionManager.cpp
        src/Server/LocalConnectionManager.cpp
        src/Server/LocalConnectionManager.cpp
        src/Edges/Actions/RestartAction.cpp
        src/Edges/Actions/ReturnPlayerBetAction.cpp
        src/Edges/Conditions/PlayerCanBetCondition.cpp
        src/Components/Component.cpp
        src/Components/Cards/Card.cpp
        src/TempSender.cpp src/Edges/Actions/MultiAction.cpp src/Components/PlayerComponent.cpp src/Edges/Actions/GoToNextPlayerAction.cpp src/Edges/Actions/PlayerSplitsAction.cpp src/Edges/Conditions/PlayerCanSplitCondition.cpp src/Edges/Actions/ReturnHalfOfPlayerBetAction.cpp src/Edges/Conditions/CurrentPlayerIsXCondition.cpp src/Edges/Conditions/OrCondition.cpp src/Edges/Conditions/PlayerHaveNon0BetCondition.cpp
        src/Server/UDPManager.cpp
        include/Server/UDPManager.hpp
        src/BJSendRec.cpp
        include/BJSendRec.hpp)

add_executable(local local.cpp
        src/Components/Cards/CardHolder.cpp
        src/Components/Cards/PlayingCard.cpp
        src/Components/Cards/DeckComponent.cpp
        src/Edges/Edge.cpp
        src/Edges/Conditions/BlackjackAtLeastXCondition.cpp
        src/Components/ComponentProvider.cpp
        src/Edges/Conditions/HandSizeUnderXCondition.cpp
        src/Edges/Actions/PlayerDrawsCardAction.cpp
        src/Edges/Conditions/AndCondition.cpp
        src/Components/ChipsComponent.cpp
        src/PlayerConnection.cpp
        src/Components/HandsComponent.cpp
        src/Components/ConnectionComponent.cpp
        src/Edges/Actions/GetBetFromPlayerAction.cpp
        src/Edges/Conditions/AlwaysTrueCondition.cpp
        src/Edges/Actions/DoublePlayersBetAction.cpp
        src/Edges/Actions/DoubleAndReturnPlayersBetAction.cpp
        src/Edges/Actions/PlayerDrawsReversedCardAction.cpp
        src/Graph.cpp
        src/Game.cpp
        src/Edges/Conditions/PlayerCanDoubleBetCondition.cpp
        src/Edges/Conditions/NotCondition.cpp
        src/Edges/Actions/EmptyAction.cpp
        src/Edges/Actions/ShowDealersCardsAction.cpp
        src/Edges/Conditions/RelationBetweenPlayerAndDealerHandCondition.cpp
        src/Edges/Actions/EndGameAction.cpp
        src/Edges/Actions/SendMessageAction.cpp
        src/Edges/Actions/RestartAction.cpp
        src/Edges/Actions/ReturnPlayerBetAction.cpp
        src/Edges/Conditions/PlayerCanBetCondition.cpp
        src/Edges/Actions/RestartAction.cpp
        src/Edges/Actions/ReturnPlayerBetAction.cpp
        src/Edges/Conditions/PlayerCanBetCondition.cpp
        src/Components/Component.cpp
        src/Components/Cards/Card.cpp
        src/Edges/Actions/MultiAction.cpp src/Components/PlayerComponent.cpp include/Edges/Actions/GoToNextPlayerAction.hpp src/Edges/Actions/GoToNextPlayerAction.cpp src/Edges/Actions/PlayerSplitsAction.cpp src/Edges/Conditions/PlayerCanSplitCondition.cpp src/Edges/Actions/ReturnHalfOfPlayerBetAction.cpp src/Edges/Conditions/CurrentPlayerIsXCondition.cpp src/Edges/Conditions/OrCondition.cpp src/Edges/Conditions/PlayerHaveNon0BetCondition.cpp)
