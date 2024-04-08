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
#include "include/Edges/Actions/PlayerTiedAction.hpp"
#include "include/Edges/Conditions/AlwaysTrueCondition.hpp"
#include "include/Edges/Conditions/HandSizeUnderXCondition.hpp"
#include "include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"
#include "include/Edges/Conditions/AndCondition.hpp"
#include "include/Edges/Conditions/BlackjackAtLeastXCondition.hpp"
#include "include/Edges/Conditions/NotCondition.hpp"
#include "include/Edges/Conditions/RelationBetweenPlayerAndDealerHandCondition.hpp"
#include "include/Edges/Conditions/PlayerCanBetCondition.hpp"
#include "include/Server/ConnectionManager.hpp"


int main(int, char **) {
    std::vector<std::unique_ptr<Card>> deck;
    for (int j = 0; j < 4; ++j){
        for (unsigned char i = 2; i < 15; ++i) {
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, spades)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, hearts)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, diamonds)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, clubs)));
        }
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    DeckComponent playingCardsDeck{std::move(deck), e};
    ChipsComponent chipsComponent{1000};
    PlayerConnection playerConnection{};
    ConnectionComponent connectionComponent{playerConnection};
    HandsComponent handsComponent{connectionComponent};


    ComponentProvider componentProvider{handsComponent,
                                        playingCardsDeck,
                                        chipsComponent,
                                        connectionComponent};
    std::vector<std::vector<Edge>> edges;
    edges.resize(22);

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
    PlayerTiedAction playerTiedAction{};

    AlwaysTrueCondition alwaysTrueCondition{};
    HandSizeUnderXCondition handSizeUnder3Condition{3};
    PlayerCanDoubleBetCondition playerCanDoubleBetCondition{};
    AndCondition canDoubleCondition(dynamic_cast<Condition &>(handSizeUnder3Condition),
                                    dynamic_cast<Condition &>(playerCanDoubleBetCondition));
    BlackjackAtLeastXCondition playerBustedCondition{22};
    NotCondition playerDidntBustedCondition(dynamic_cast<Condition &>(playerBustedCondition));
    BlackjackAtLeastXCondition dealerToEndDrawingCondition{17};
    NotCondition dealerToDrawCondition(dynamic_cast<Condition &>(dealerToEndDrawingCondition));
    RelationBetweenPlayerAndDealerHandCondition playerHasMoreThanDealerCondition{greater};
    RelationBetweenPlayerAndDealerHandCondition playerHasLessThanDealerCondition{lesser};
    RelationBetweenPlayerAndDealerHandCondition playerAndDealerHasTheSameCondition{equal};
    PlayerCanBetCondition playerCanBetCondition{};
    NotCondition playerCannotBetCondition(dynamic_cast<Condition &>(playerCanBetCondition));

    edges[0].push_back(Edge{"", getBetFromPlayerAction, playerCanBetCondition, 1});
    edges[0].push_back(Edge{"", endGameAction, playerCannotBetCondition, 21});
    edges[1].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 2});
    edges[2].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 3});
    edges[3].push_back(Edge{"", changeToDealerAction, alwaysTrueCondition, 4});
    edges[4].push_back(Edge{"", playerDrawsCardAction, alwaysTrueCondition, 5});
    edges[5].push_back(Edge{"", playerDrawsReversedCardAction, alwaysTrueCondition, 6});
    edges[6].push_back(Edge{"", changeToPlayerAction, alwaysTrueCondition, 7});
    edges[7].push_back(Edge{"", changeToPlayerAction, alwaysTrueCondition, 19});
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
    edges[15].push_back(Edge{"", emptyAction, dealerToEndDrawingCondition, 20});
    edges[20].push_back(Edge{"", playerWonAction, playerBustedCondition, 17});
    edges[20].push_back(Edge{"", emptyAction, playerDidntBustedCondition, 16});
    edges[16].push_back(Edge{"", playerWonAction, playerHasMoreThanDealerCondition, 17});
    edges[16].push_back(Edge{"", playerLostAction, playerHasLessThanDealerCondition, 17});
    edges[16].push_back(Edge{"", playerTiedAction, playerAndDealerHasTheSameCondition, 17});
    edges[17].push_back(Edge{"NEXT GAME ", changeToPlayerAction, alwaysTrueCondition, 18});
    edges[17].push_back(Edge{"END ", endGameAction, alwaysTrueCondition, 21});
    edges[18].push_back(Edge{"", clearHandsAction, alwaysTrueCondition, 0});

    Graph graph{edges, componentProvider, 0};
    Game game{componentProvider, graph};
    ConnectionManager cm{};
    cm.startup(4000);

    cm.addTable();
    std::cout << "Table added!\n";
    cm.addUserToTemporary(0);

    // PASS communication into the game!
    game.start();


    cm.close();
}
