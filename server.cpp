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
#include "include/TempSender.hpp"
#include "include/Components/HandsComponent.hpp"

int main(int, char **) {

    ConnectionManager cm{};
    cm.startup(4000);

    cm.addTable();
    std::cout << "Table added!\n";
    cm.addUserToTemporary(0);
    std::cout<< "User added\n";
    // PASS communication into the game!
    cm.getTable(0).send("hello!");
    std::cout << "Message recieved: " << cm.getTable(0).receiveFromUser(0) << '\n';
    int fd = cm.getTable(0).fds.at(0);


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

    TempSender playerConnection{fd};
    ComponentProvider componentProvider{};

    componentProvider.addComponent(std::make_unique<HandsComponent>(HandsComponent{componentProvider}), "HandsComponent");
    componentProvider.addComponent(std::make_unique<ConnectionComponent>(ConnectionComponent{playerConnection}), "ConnectionComponent");
    componentProvider.addComponent(std::make_unique<ChipsComponent>(ChipsComponent{1000}), "ChipsComponent");
    componentProvider.addComponent(std::make_unique<DeckComponent>(DeckComponent{std::move(deck),e}), "DeckComponent");

    std::vector<std::vector<Edge>> edges;
    edges.resize(22);

    auto getBetFromPlayerAction = std::make_shared<GetBetFromPlayerAction>(GetBetFromPlayerAction{});
    auto playerDrawsCardAction = std::make_shared<PlayerDrawsCardAction>(PlayerDrawsCardAction{});
    auto changeToDealerAction = std::make_shared<ChangeToDealerAction>(ChangeToDealerAction{});
    auto changeToPlayerAction = std::make_shared<ChangeToPlayerAction>(ChangeToPlayerAction{});
    auto playerDrawsReversedCardAction = std::make_shared<PlayerDrawsReversedCardAction>(PlayerDrawsReversedCardAction{});
    auto sendHandsAction = std::make_shared<SendHandsAction>(SendHandsAction{});
    auto emptyAction = std::make_shared<EmptyAction>(EmptyAction{});
    auto doublePlayersBetAction = std::make_shared<DoublePlayersBetAction>(DoublePlayersBetAction{});
    auto showDealersCardsAction = std::make_shared<ShowDealersCardsAction>(ShowDealersCardsAction{});
    auto playerWonAction = std::make_shared<PlayerWonAction>(PlayerWonAction{});
    auto playerLostAction = std::make_shared<SendMessageAction>(SendMessageAction{"YOU LOST\n"});
    auto endGameAction = std::make_shared<EndGameAction>(EndGameAction{});
    auto clearHandsAction = std::make_shared<ClearHandsAction>(ClearHandsAction{});
    auto playerTiedAction = std::make_shared<PlayerTiedAction>(PlayerTiedAction{});

    auto alwaysTrueCondition = std::make_shared<AlwaysTrueCondition>(AlwaysTrueCondition{});
    auto handSizeUnder3Condition = std::make_shared<HandSizeUnderXCondition>(HandSizeUnderXCondition{3});
    auto playerCanDoubleBetCondition = std::make_shared<PlayerCanDoubleBetCondition>(PlayerCanDoubleBetCondition{});
    auto canDoubleCondition = std::make_shared<AndCondition>(AndCondition(handSizeUnder3Condition, playerCanDoubleBetCondition));
    auto playerBustedCondition = std::make_shared<BlackjackAtLeastXCondition>(BlackjackAtLeastXCondition{22});
    auto playerDidntBustedCondition = std::make_shared<NotCondition>(NotCondition(playerBustedCondition));
    auto dealerToEndDrawingCondition = std::make_shared<BlackjackAtLeastXCondition>(BlackjackAtLeastXCondition{17});
    auto dealerToDrawCondition = std::make_shared<NotCondition>(NotCondition(dealerToEndDrawingCondition));
    auto playerHasMoreThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{greater});
    auto playerHasLessThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{lesser});
    auto playerAndDealerHasTheSameCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{equal});
    auto playerCanBetCondition = std::make_shared<PlayerCanBetCondition>(PlayerCanBetCondition{});
    auto playerCannotBetCondition = std::make_shared<NotCondition>(NotCondition{playerCanBetCondition});

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
    game.start();


    cm.close();
}
