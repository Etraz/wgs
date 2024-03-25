#include <iostream>
#include <random>
#include <chrono>
#include "include/Game.hpp"
#include "include/Edges/Actions/GetBetFromPlayerAction.hpp"
#include "include/Edges/Actions/PlayerDrawsCardAction.hpp"
#include "include/Edges/Actions/ChangeToDealerAction.hpp"
#include "include/Edges/Actions/ChangeToPlayerAction.hpp"
#include "include/Edges/Actions/PlayerDrawsReversedCardAction.hpp"
#include "include/Edges/Actions/SendHandsAction.hpp"
#include "include/Edges/Actions/EmptyAction.hpp"
#include "include/Edges/Actions/DoublePlayersBetAction.hpp"
#include "include/Edges/Actions/ShowDealersCardsAction.hpp"
#include "include/Edges/Actions/PlayerWonAction.hpp"
#include "include/Edges/Actions/EndGameAction.hpp"
#include "include/Edges/Actions/SendMessageAction.hpp"
#include "include/Edges/Actions/ClearHandsAction.hpp"
#include "include/Edges/Conditions/AlwaysTrueCondition.hpp"
#include "include/Edges/Conditions/HandSizeUnderXCondition.hpp"
#include "include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"
#include "include/Edges/Conditions/AndCondition.hpp"
#include "include/Edges/Conditions/BlackjackAtLeastXCondition.hpp"
#include "include/Edges/Conditions/NotCondition.hpp"
#include "include/Edges/Conditions/PlayerWonCondition.hpp"


int main(int, char**){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    HandsComponent handsComponent{};
    PlayingCardsDeck playingCardsDeck{e};
    ChipsComponent chipsComponent{1000};
    PlayerConnection playerConnection{};
    ConnectionComponent connectionComponent{playerConnection};

    ComponentProvider componentProvider{handsComponent,
                                        playingCardsDeck,
                                        chipsComponent,
                                        connectionComponent};
    std::vector<std::vector<Edge>> edges;
    edges.resize(21);

    GetBetFromPlayerAction getBetFromPlayerAction{};
    PlayerDrawsCardAction playerDrawsCardAction{};
    ChangeToDealerAction changeToDealerAction{};
    ChangeToPlayerAction changeToPlayerAction{};
    PlayerDrawsReversedCardAction playerDrawsReversedCardAction{};
    SendHandsAction sendHandsAction{};
    EmptyAction emptyAction{};
    DoublePlayersBetAction doublePlayersBetAction{};
    ShowDealersCardsAction showDealersCardsAction{};
    PlayerWonAction playerWonAction{};
    SendMessageAction playerLostAction{"YOU LOST\n"};
    EndGameAction endGameAction{};
    ClearHandsAction clearHandsAction{};

    AlwaysTrueCondition alwaysTrueCondition{};
    HandSizeUnderXCondition handSizeUnder3Condition{3};
    PlayerCanDoubleBetCondition playerCanDoubleBetCondition{};
    AndCondition canDoubleCondition(dynamic_cast<Condition&>(handSizeUnder3Condition), dynamic_cast<Condition&>(playerCanDoubleBetCondition));
    BlackjackAtLeastXCondition playerBustedCondition{22};
    NotCondition playerDidntBustedCondition(dynamic_cast<Condition&>(playerBustedCondition));
    BlackjackAtLeastXCondition dealerToEndDrawingCondition{18};
    NotCondition dealerToDrawCondition(dynamic_cast<Condition&>(dealerToEndDrawingCondition));
    PlayerWonCondition playerWonCondition{};
    NotCondition playerLostCondition(dynamic_cast<Condition&>(playerWonCondition));


    edges[0].push_back(Edge{"", getBetFromPlayerAction, alwaysTrueCondition, 1});
    edges[1].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 2});
    edges[2].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 3});
    edges[3].push_back(Edge{"", changeToDealerAction, alwaysTrueCondition, 4});
    edges[4].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 5});
    edges[5].push_back(Edge{"", playerDrawsReversedCardAction, alwaysTrueCondition, 6});
    edges[6].push_back(Edge{"", changeToPlayerAction, alwaysTrueCondition, 7});
    edges[7].push_back(Edge{"",  changeToPlayerAction, alwaysTrueCondition, 19});
    edges[19].push_back(Edge{"", sendHandsAction, alwaysTrueCondition, 8});
    edges[8].push_back(Edge{"HIT ", playerDrawsCardAction, alwaysTrueCondition, 9});
    edges[8].push_back(Edge{"DOUBLE ", doublePlayersBetAction, canDoubleCondition, 11});
    edges[8].push_back(Edge{"STAY ", emptyAction, alwaysTrueCondition, 10});
    edges[11].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 12});
    edges[12].push_back(Edge{"", playerLostAction, playerBustedCondition, 17});
    edges[12].push_back(Edge{"", emptyAction, playerDidntBustedCondition, 10});
    edges[9].push_back(Edge{"", playerLostAction, playerBustedCondition, 17});
    edges[9].push_back(Edge{"", emptyAction, playerDidntBustedCondition, 19});
    edges[10].push_back(Edge{"", showDealersCardsAction, alwaysTrueCondition, 13});
    edges[13].push_back(Edge{"", sendHandsAction, alwaysTrueCondition, 14});
    edges[14].push_back(Edge{"", changeToDealerAction, alwaysTrueCondition, 15});
    edges[15].push_back(Edge{"", playerDrawsCardAction, dealerToDrawCondition, 15});
    edges[15].push_back(Edge{"", emptyAction, dealerToEndDrawingCondition, 16});
    edges[16].push_back(Edge{"", playerWonAction, playerWonCondition, 17});
    edges[16].push_back(Edge{"", playerLostAction, playerLostCondition, 17});
    edges[17].push_back(Edge{"NEXT GAME ", changeToPlayerAction, alwaysTrueCondition, 18});
    edges[17].push_back(Edge{"END ", endGameAction, alwaysTrueCondition, 20});
    edges[18].push_back(Edge{"", clearHandsAction, alwaysTrueCondition, 0});

    Graph graph{edges, componentProvider, 0};
    Game game{componentProvider, graph};
    game.start();
}
