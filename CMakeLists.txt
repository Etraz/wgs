cmake_minimum_required(VERSION 3.22)
project(wgs)

set(CMAKE_CXX_STANDARD 20)

add_executable(wgs main.cpp
        src/Components/PlayingCard.cpp
        src/Components/PlayingCardsDeck.cpp
        src/Edges/Edge.cpp
        src/Edges/Conditions/BlackjackAtLeastXCondition.cpp
        src/Components/ComponentProvider.cpp
        src/Edges/Conditions/HandSizeUnderXCondition.cpp
        src/Edges/Actions/PlayerDrawsCardAction.cpp
        src/Edges/Actions/ChangeToDealerAction.cpp
        src/Edges/Conditions/AndCondition.cpp
        src/Components/ChipsComponent.cpp
        src/PlayerConnection.cpp
        src/Components/HandsComponent.cpp
        src/Components/ConnectionComponent.cpp
        src/Edges/Actions/GetBetFromPlayerAction.cpp
        src/Edges/Conditions/AlwaysTrueCondition.cpp
        src/Edges/Actions/DoublePlayersBetAction.cpp
        src/Edges/Actions/PlayerWonAction.cpp
        src/Edges/Actions/ChangeToPlayerAction.cpp
        src/Edges/Actions/PlayerDrawsReversedCardAction.cpp
        src/Edges/Actions/SendHandsAction.cpp
        src/Graph.cpp
        src/Game.cpp
        src/Edges/Conditions/PlayerCanDoubleBetCondition.cpp
        src/Edges/Conditions/NotCondition.cpp
        src/Edges/Actions/EmptyAction.cpp
        src/Edges/Actions/ShowDealersCardsAction.cpp
        src/Edges/Conditions/PlayerWonCondition.cpp
        src/Edges/Actions/EndGameAction.cpp
        src/Edges/Actions/SendMessageAction.cpp
        src/Edges/Actions/ClearHandsAction.cpp)
