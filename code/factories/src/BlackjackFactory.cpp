#include "factories/BlackjackFactory.hpp"
#include <iostream>
#include <random>
#include <chrono>
#include "game/Game.hpp"
#include "actions/blackjack/GetBetFromPlayerAction.hpp"
#include "actions/blackjack/PlayerDrawsCardAction.hpp"
#include "actions/blackjack/PlayerDrawsReversedCardAction.hpp"
#include "actions/common/EmptyAction.hpp"
#include "actions/blackjack/DoublePlayersBetAction.hpp"
#include "actions/blackjack/ShowDealersCardsAction.hpp"
#include "actions/blackjack/DoubleAndReturnPlayersBetAction.hpp"
#include "actions/blackjack/EndGameAction.hpp"
#include "actions/blackjack/SendMessageAction.hpp"
#include "actions/blackjack/RestartAction.hpp"
#include "actions/blackjack/ReturnPlayerBetAction.hpp"
#include "conditions/common/AlwaysTrueCondition.hpp"
#include "conditions/blackjack/HandSizeUnderXCondition.hpp"
#include "conditions/blackjack/PlayerCanDoubleBetCondition.hpp"
#include "conditions/common/AndCondition.hpp"
#include "conditions/blackjack/HandScoreAtLeastXCondition.hpp"
#include "conditions/common/NotCondition.hpp"
#include "conditions/blackjack/RelationBetweenPlayerAndDealerHandCondition.hpp"
#include "actions/blackjack/GoToNextPlayerAction.hpp"
#include "actions/blackjack/MultiAction.hpp"
#include "actions/blackjack/PlayerSplitsAction.hpp"
#include "actions/blackjack/ReturnHalfOfPlayerBetAction.hpp"
#include "conditions/blackjack/CurrentPlayerIsXCondition.hpp"
#include "conditions/blackjack/PlayerCanSplitCondition.hpp"
#include "conditions/blackjack/PlayerHaveNon0BetCondition.hpp"

Game BlackjackFactory::make(std::unique_ptr<AbstractSendRec> &&sendRec,
                            const std::vector<PlayerAddress> &addresess) {
    std::vector<std::unique_ptr<Card>> deck;
    for (int j = 0; j < 4; ++j) {
        for (unsigned char i = 2; i < 15; ++i) {
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, spades)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, hearts)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, diamonds)));
            deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, clubs)));
        }
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    PlayerIndex numberOfPlayers = addresess.size();
    std::vector<PlayerAddress> orginalAddreses{};
    orginalAddreses.reserve(numberOfPlayers + 1);
    orginalAddreses.push_back(0);

    for (auto &x: addresess)
        orginalAddreses.push_back(x);


    std::shared_ptr<ComponentProvider> componentProvider = std::make_shared<ComponentProvider>(ComponentProvider{});

    componentProvider->addComponent(
            std::make_unique<HandsComponent>(HandsComponent(componentProvider, numberOfPlayers)), "HandsComponent");
    componentProvider->addComponent(std::make_unique<ConnectionComponent>(ConnectionComponent(numberOfPlayers,
                                                                                              std::move(sendRec),
                                                                                              std::move(
                                                                                                      orginalAddreses))),
                                    "ConnectionComponent");
    componentProvider->addComponent(std::make_unique<ChipsComponent>(ChipsComponent(numberOfPlayers)),
                                    "ChipsComponent");
    componentProvider->addComponent(std::make_unique<CardDeck>(CardDeck{std::move(deck), e}),
                                    "CardDeck");
    componentProvider->addComponent(
            std::make_unique<PlayerComponent>(PlayerComponent{componentProvider, numberOfPlayers}), "PlayersComponent");

    auto edges = std::make_unique<std::vector<std::vector<Edge>>>(std::vector<std::vector<Edge>>{});
    edges->resize(12);

    auto emptyAction = std::make_shared<EmptyAction>(EmptyAction{});

    auto getBetFromPlayerAction = std::make_shared<GetBetFromPlayerAction>(GetBetFromPlayerAction{});
    auto playerDrawsCardAction = std::make_shared<PlayerDrawsCardAction>(PlayerDrawsCardAction{});
    auto goToNextPlayerAction = std::make_shared<GoToNextPlayerAction>(GoToNextPlayerAction{});
    auto playerBetsAndDrawsAction = std::make_shared<MultiAction>(MultiAction({getBetFromPlayerAction,
                                                                               playerDrawsCardAction,
                                                                               playerDrawsCardAction,
                                                                               goToNextPlayerAction}));
    auto playerDrawsReversedCardAction = std::make_shared<PlayerDrawsReversedCardAction>(
            PlayerDrawsReversedCardAction{});
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
    auto doubleAndReturnPlayersBet = std::make_shared<DoubleAndReturnPlayersBetAction>(
            DoubleAndReturnPlayersBetAction{});
    auto playerWonAction = std::make_shared<MultiAction>(MultiAction({doubleAndReturnPlayersBet,
                                                                      goToNextPlayerAction}));
    auto sendPlayerLostInfo = std::make_shared<SendMessageAction>(SendMessageAction{"YOU LOST"});
    auto playerLostAction = std::make_shared<MultiAction>(MultiAction({sendPlayerLostInfo,
                                                                       goToNextPlayerAction}));
    auto returnPlayerBetAction = std::make_shared<ReturnPlayerBetAction>(ReturnPlayerBetAction{});
    auto sendPlayerTiedInfo = std::make_shared<SendMessageAction>(SendMessageAction{"YOU TIED"});
    auto playerTiedAction = std::make_shared<MultiAction>(MultiAction({returnPlayerBetAction,
                                                                       goToNextPlayerAction}));
    auto endGameAction = std::make_shared<EndGameAction>(EndGameAction{});
    auto restartAction = std::make_shared<RestartAction>(RestartAction{});

    auto alwaysTrueCondition = std::make_shared<AlwaysTrueCondition>(AlwaysTrueCondition{});
    auto dealerIsCurrentPlayerCondition = std::make_shared<CurrentPlayerIsXCondition>(CurrentPlayerIsXCondition{0});
    auto playerIsCurrentPlayerCondition = std::make_shared<NotCondition>(NotCondition{dealerIsCurrentPlayerCondition});
    auto handSizeUnder3Condition = std::make_shared<HandSizeUnderXCondition>(HandSizeUnderXCondition{3});
    auto playerCanDoubleBetCondition = std::make_shared<PlayerCanDoubleBetCondition>(PlayerCanDoubleBetCondition{});
    auto playerCanDoubleCondition = std::make_shared<AndCondition>(
            AndCondition(handSizeUnder3Condition, playerCanDoubleBetCondition));
    auto playerCanSplitCondition = std::make_shared<PlayerCanSplitCondition>(PlayerCanSplitCondition{});
    auto playerBustedCondition = std::make_shared<HandScoreAtLeastXCondition>(HandScoreAtLeastXCondition{22});
    auto playerDidntBustedCondition = std::make_shared<NotCondition>(NotCondition(playerBustedCondition));
    auto dealerToEndDrawingCondition = std::make_shared<HandScoreAtLeastXCondition>(HandScoreAtLeastXCondition{17});
    auto dealerToDrawCondition = std::make_shared<NotCondition>(NotCondition(dealerToEndDrawingCondition));
    auto playerHasMoreThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(
            RelationBetweenPlayerAndDealerHandCondition{greater});
    auto playerHasLessThanDealerCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(
            RelationBetweenPlayerAndDealerHandCondition{lesser});
    auto playerAndDealerHasTheSameCondition = std::make_shared<RelationBetweenPlayerAndDealerHandCondition>(
            RelationBetweenPlayerAndDealerHandCondition{equal});
    auto playerHaveNon0BetCondition = std::make_shared<PlayerHaveNon0BetCondition>(PlayerHaveNon0BetCondition{});
    auto playerBetAndDidntBust = std::make_shared<AndCondition>(
            AndCondition(playerDidntBustedCondition, playerHaveNon0BetCondition));
    auto playerDidntBetOrBust = std::make_shared<NotCondition>(NotCondition{playerBetAndDidntBust});

    edges->at(0).push_back(Edge{"", playerBetsAndDrawsAction, playerIsCurrentPlayerCondition, 0});
    edges->at(0).push_back(Edge{"", dealerDrawsCardsAction, dealerIsCurrentPlayerCondition, 1});
    edges->at(1).push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 2});
    edges->at(1).push_back(Edge{"", showDealersCardsAction, dealerIsCurrentPlayerCondition, 4});
    edges->at(2).push_back(Edge{"HIT", playerDrawsCardAction, alwaysTrueCondition, 3});
    edges->at(2).push_back(Edge{"STAY", goToNextPlayerAction, alwaysTrueCondition, 1});
    edges->at(2).push_back(Edge{"DOUBLE", playerDoublesAction, playerCanDoubleCondition, 1});
    edges->at(2).push_back(Edge{"SPLIT", playerSplitsAction, playerCanSplitCondition, 2});
    edges->at(2).push_back(Edge{"SURRENDER", playerSurrendresAction, alwaysTrueCondition, 1});
    edges->at(3).push_back(Edge{"", emptyAction, playerDidntBustedCondition, 2});
    edges->at(3).push_back(Edge{"", goToNextPlayerAction, playerBustedCondition, 1});
    edges->at(4).push_back(Edge{"", playerDrawsCardAction, dealerToDrawCondition, 4});
    edges->at(4).push_back(Edge{"", emptyAction, dealerToEndDrawingCondition, 5});
    edges->at(5).push_back(Edge{"", goToNextPlayerAction, playerBustedCondition, 6});
    edges->at(5).push_back(Edge{"", goToNextPlayerAction, playerDidntBustedCondition, 8});
    edges->at(6).push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 7});
    edges->at(6).push_back(Edge{"", goToNextPlayerAction, dealerIsCurrentPlayerCondition, 11});
    edges->at(7).push_back(Edge{"", playerWonAction, playerBetAndDidntBust, 6});
    edges->at(7).push_back(Edge{"", goToNextPlayerAction, playerDidntBetOrBust, 6});
    edges->at(8).push_back(Edge{"", emptyAction, playerIsCurrentPlayerCondition, 9});
    edges->at(8).push_back(Edge{"", goToNextPlayerAction, dealerIsCurrentPlayerCondition, 11});
    edges->at(9).push_back(Edge{"", goToNextPlayerAction, playerDidntBetOrBust, 8});
    edges->at(9).push_back(Edge{"", emptyAction, playerBetAndDidntBust, 10});
    edges->at(10).push_back(Edge{"", playerWonAction, playerHasMoreThanDealerCondition, 8});
    edges->at(10).push_back(Edge{"", playerLostAction, playerHasLessThanDealerCondition, 8});
    edges->at(10).push_back(Edge{"", playerTiedAction, playerAndDealerHasTheSameCondition, 8});
    edges->at(11).push_back(Edge{"NEXT GAME ", restartAction, alwaysTrueCondition, 0});
    edges->at(11).push_back(Edge{"END ", endGameAction, alwaysTrueCondition, 0});

    auto graph = std::make_unique<Graph>(Graph{std::move(edges), componentProvider, 0});
    return Game{componentProvider, std::move(graph)};
}
