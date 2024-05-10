#include <iostream>
#include <random>
#include <chrono>
#include "include/Game.hpp"
#include "include/Edges/Actions/GetBetFromPlayerAction.hpp"
#include "include/Edges/Actions/PlayerDrawsCardAction.hpp"
#include "include/Edges/Actions/PlayerDrawsReversedCardAction.hpp"
#include "include/Edges/Actions/EmptyAction.hpp"
#include "include/Edges/Actions/DoublePlayersBetAction.hpp"
#include "include/Edges/Actions/ShowDealersCardsAction.hpp"
#include "include/Edges/Actions/DoubleAndReturnPlayersBetAction.hpp"
#include "include/Edges/Actions/EndGameAction.hpp"
#include "include/Edges/Actions/SendMessageAction.hpp"
#include "include/Edges/Actions/RestartAction.hpp"
#include "include/Edges/Actions/ReturnPlayerBetAction.hpp"
#include "include/Edges/Conditions/AlwaysTrueCondition.hpp"
#include "include/Edges/Conditions/HandSizeUnderXCondition.hpp"
#include "include/Edges/Conditions/PlayerCanDoubleBetCondition.hpp"
#include "include/Edges/Conditions/AndCondition.hpp"
#include "include/Edges/Conditions/BlackjackAtLeastXCondition.hpp"
#include "include/Edges/Conditions/NotCondition.hpp"
#include "include/Edges/Conditions/RelationBetweenPlayerAndDealerHandCondition.hpp"
#include "include/Components/HandsComponent.hpp"
#include "include/PlayersConnection.hpp"
#include "include/Edges/Actions/GoToNextPlayerAction.hpp"
#include "include/Edges/Actions/MultiAction.hpp"
#include "include/Edges/Actions/PlayerSplitsAction.hpp"
#include "include/Edges/Actions/ReturnHalfOfPlayerBetAction.hpp"
#include "include/Edges/Conditions/CurrentPlayerIsXCondition.hpp"
#include "include/Edges/Conditions/PlayerCanSplitCondition.hpp"
#include "include/Edges/Conditions/PlayerHaveNon0BetCondition.hpp"

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
    PlayersConnection connection{};
    PlayerIndex numberOfPlayers = 1;


    ComponentProvider componentProvider{};

    componentProvider.addComponent(std::make_unique<HandsComponent>(HandsComponent(componentProvider, numberOfPlayers)), "HandsComponent");
    componentProvider.addComponent(std::make_unique<ConnectionComponent>(ConnectionComponent(numberOfPlayers, connection)), "ConnectionComponent");
    componentProvider.addComponent(std::make_unique<ChipsComponent>(ChipsComponent(numberOfPlayers)), "ChipsComponent");
    componentProvider.addComponent(std::make_unique<DeckComponent>(DeckComponent{std::move(deck),e}), "DeckComponent");
    componentProvider.addComponent(std::make_unique<PlayerComponent>(PlayerComponent{componentProvider, numberOfPlayers}), "PlayersComponent");

    std::vector<std::vector<Edge>> edges;
    edges.resize(12);

    auto emptyAction = std::make_shared<EmptyAction>(EmptyAction{});

    auto getBetFromPlayerAction = std::make_shared<GetBetFromPlayerAction>(GetBetFromPlayerAction{});
    auto playerDrawsCardAction = std::make_shared<PlayerDrawsCardAction>(PlayerDrawsCardAction{});
    auto goToNextPlayerAction = std::make_shared<GoToNextPlayerAction>(GoToNextPlayerAction{});
    auto playerBetsAndDrawsAction = std::make_shared<MultiAction>(MultiAction({getBetFromPlayerAction,
                                                                               playerDrawsCardAction,
                                                                               playerDrawsCardAction,
                                                                               goToNextPlayerAction}));
    auto playerDrawsReversedCardAction = std::make_shared<PlayerDrawsReversedCardAction>(PlayerDrawsReversedCardAction{});
    auto dealerDrawsCardsAction = std::make_shared<MultiAction>(MultiAction({playerDrawsCardAction,
                                                                             playerDrawsReversedCardAction,
                                                                             goToNextPlayerAction}));
    auto showDealersCardsAction = std::make_shared<ShowDealersCardsAction>(ShowDealersCardsAction{});
    auto doublePlayersBetAction = std::make_shared<DoublePlayersBetAction>(DoublePlayersBetAction{});
    auto playerDoublesAction = std::make_shared<MultiAction>(MultiAction({doublePlayersBetAction,
                                                                          playerDrawsCardAction,
                                                                          goToNextPlayerAction}));
    auto playerSplitsAction = std::make_shared<PlayerSplitsAction>(PlayerSplitsAction{});
    auto returnHalfOfPlayerBetAction = std::make_shared<ReturnHalfOfPlayerBetAction>(ReturnHalfOfPlayerBetAction{});
    auto playerSurrendresAction = std::make_shared<MultiAction>(MultiAction({returnHalfOfPlayerBetAction,
                                                                             goToNextPlayerAction}));
    auto doubleAndReturnPlayersBet = std::make_shared<DoubleAndReturnPlayersBetAction>(DoubleAndReturnPlayersBetAction{});
    auto playerWonAction = std::make_shared<MultiAction>(MultiAction({doubleAndReturnPlayersBet,
                                                                      goToNextPlayerAction}));
    auto sendPlayerLostInfo = std::make_shared<SendMessageAction>(SendMessageAction{"YOU LOST"});
    auto playerLostAction = std::make_shared<MultiAction>(MultiAction({sendPlayerLostInfo,
                                                                       goToNextPlayerAction}));
    auto returnPlayerBetAction = std::make_shared<ReturnPlayerBetAction>(ReturnPlayerBetAction{});
    auto playerTiedAction = std::make_shared<MultiAction>(MultiAction({returnPlayerBetAction,
                                                                       goToNextPlayerAction}));
    auto endGameAction = std::make_shared<EndGameAction>(EndGameAction{});
    auto restartAction = std::make_shared<RestartAction>(RestartAction{});

    auto alwaysTrueCondition = std::make_shared<AlwaysTrueCondition>(AlwaysTrueCondition{});
    auto dealerIsCurrentPlayerCondition = std::make_shared<CurrentPlayerIsXCondition>(CurrentPlayerIsXCondition{0});
    auto playerIsCurrentPlayerCondition = std::make_shared<NotCondition>(NotCondition{dealerIsCurrentPlayerCondition});
    auto handSizeUnder3Condition = std::make_shared<HandSizeUnderXCondition>(HandSizeUnderXCondition{3});
    auto playerCanDoubleBetCondition = std::make_shared<PlayerCanDoubleBetCondition>(PlayerCanDoubleBetCondition{});
    auto playerCanDoubleCondition = std::make_shared<AndCondition>(AndCondition(handSizeUnder3Condition, playerCanDoubleBetCondition));
    auto playerCanSplitCondition = std::make_shared<PlayerCanSplitCondition>(PlayerCanSplitCondition{});
    auto playerBustedCondition = std::make_shared<BlackjackAtLeastXCondition>(BlackjackAtLeastXCondition{22});
    auto playerDidntBustedCondition = std::make_shared<NotCondition>(NotCondition(playerBustedCondition));
    auto dealerToEndDrawingCondition = std::make_shared<BlackjackAtLeastXCondition>(BlackjackAtLeastXCondition{17});
    auto dealerToDrawCondition = std::make_shared<NotCondition>(NotCondition(dealerToEndDrawingCondition));
    auto playerHasMoreThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{greater});
    auto playerHasLessThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{lesser});
    auto playerAndDealerHasTheSameCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(RelationBetweenPlayerAndDealerHandCondition{equal});
    auto playerHaveNon0BetCondition = std::make_shared<PlayerHaveNon0BetCondition>(PlayerHaveNon0BetCondition{});
    auto playerBetAndDidntBust = std::make_shared<AndCondition>(AndCondition(playerDidntBustedCondition, playerHaveNon0BetCondition));
    auto playerDidntBetOrBust = std::make_shared<NotCondition>(NotCondition{playerBetAndDidntBust});

    edges[0].push_back(Edge{"", playerBetsAndDrawsAction, playerIsCurrentPlayerCondition, 0});
    edges[0].push_back(Edge{"", dealerDrawsCardsAction, dealerIsCurrentPlayerCondition, 1});
    edges[1].push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 2});
    edges[1].push_back(Edge{"", showDealersCardsAction, dealerIsCurrentPlayerCondition, 4});
    edges[2].push_back(Edge{"HIT", playerDrawsCardAction, alwaysTrueCondition, 3});
    edges[2].push_back(Edge{"STAY", goToNextPlayerAction, alwaysTrueCondition, 1});
    edges[2].push_back(Edge{"DOUBLE", playerDoublesAction, playerCanDoubleCondition, 1});
    edges[2].push_back(Edge{"SPLIT", playerSplitsAction, playerCanSplitCondition, 2});
    edges[2].push_back(Edge{"SURRENDER", playerSurrendresAction, alwaysTrueCondition, 1});
    edges[3].push_back(Edge{"", emptyAction, playerDidntBustedCondition, 2});
    edges[3].push_back(Edge{"", goToNextPlayerAction, playerBustedCondition, 1});
    edges[4].push_back(Edge{"", playerDrawsCardAction, dealerToDrawCondition, 4});
    edges[4].push_back(Edge{"", emptyAction, dealerToEndDrawingCondition, 5});
    edges[5].push_back(Edge{"", goToNextPlayerAction, playerBustedCondition, 6});
    edges[5].push_back(Edge{"", goToNextPlayerAction, playerDidntBustedCondition, 8});
    edges[6].push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 7});
    edges[6].push_back(Edge{"", emptyAction, dealerIsCurrentPlayerCondition, 11});
    edges[7].push_back(Edge{"", playerWonAction, playerBetAndDidntBust, 6});
    edges[7].push_back(Edge{"", goToNextPlayerAction, playerDidntBetOrBust, 6});
    edges[8].push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 9});
    edges[8].push_back(Edge{"", emptyAction, dealerIsCurrentPlayerCondition, 11});
    edges[9].push_back(Edge{"", goToNextPlayerAction, playerDidntBetOrBust, 8});
    edges[9].push_back(Edge{"", emptyAction, playerBetAndDidntBust, 10});
    edges[10].push_back(Edge{"", playerWonAction, playerHasMoreThanDealerCondition, 8});
    edges[10].push_back(Edge{"", playerLostAction, playerHasLessThanDealerCondition, 8});
    edges[10].push_back(Edge{"", playerTiedAction, playerAndDealerHasTheSameCondition, 8});
    edges[11].push_back(Edge{"NEXT GAME ", restartAction, alwaysTrueCondition, 0});
    edges[11].push_back(Edge{"END ", endGameAction, alwaysTrueCondition, 0});

    Graph graph{edges, componentProvider, 0};
    Game game{componentProvider, graph};
    game.start();
}
