#include <chrono>
#include "factories/BridgeFactory.hpp"
#include "actions/bridge/BridgeDealAction.hpp"
#include "actions/common/EmptyAction.hpp"
#include "conditions/common/AlwaysTrueCondition.hpp"
#include "conditions/common/HandSizeUnderXCondition.hpp"
#include "conditions/common/NotCondition.hpp"
#include "conditions/bridge/CurrentTrickIsFullCondition.hpp"
#include "actions/bridge/CurrentPlayerStartsNewTrickAction.hpp"
#include "actions/common/GoToNextPlayerAction.hpp"
#include "actions/common/MultiAction.hpp"
#include "actions/bridge/CurrentPlayerPlaysCardAction.hpp"
#include "actions/bridge/BridgeRestartAction.hpp"
#include "actions/bridge/SendAfterGameInfoAction.hpp"
#include "actions/bridge/EndTrickAction.hpp"
#include "actions/bridge/GetNextCallFromPlayerAction.hpp"
#include "conditions/bridge/AuctionToContinueCondition.hpp"
#include "actions/bridge/EndAuctionAction.hpp"

Game BridgeFactory::make(std::unique_ptr<AbstractSendRec> &&sendRec,
                         const std::vector<PlayerAddress> &addresess) {
    std::vector<std::unique_ptr<Card>> deck;
    for (unsigned char i = 2; i < 15; i++) {
        deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, spades)));
        deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, hearts)));
        deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, diamonds)));
        deck.push_back(std::unique_ptr<Card>(new PlayingCard(i, clubs)));
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    std::vector<PlayerAddress> orginalAddreses{};
    orginalAddreses.reserve(4);
    for (auto &x: addresess)
        orginalAddreses.push_back(x);

    std::shared_ptr<ComponentProvider> componentProvider = std::make_shared<ComponentProvider>(ComponentProvider{});

    componentProvider->addComponent(std::make_unique<HandsComponent>(
            HandsComponent(componentProvider, 8)), "HandsComponent");
    componentProvider->addComponent(std::make_unique<ConnectionComponent>(
            ConnectionComponent(4, std::move(sendRec), std::move(orginalAddreses))), "ConnectionComponent");
    componentProvider->addComponent(std::make_unique<BridgeTricksComponent>(
            BridgeTricksComponent()), "TricksComponent");
    componentProvider->addComponent(std::make_unique<BridgeAuctionComponent>(
            BridgeAuctionComponent()), "TricksComponent");
    componentProvider->addComponent(std::make_unique<CardDeck>(
            CardDeck{std::move(deck), e}), "CardDeck");
    componentProvider->addComponent(std::make_unique<PlayerComponent>(
            PlayerComponent{componentProvider, 3}), "PlayersComponent");

    auto edges = std::make_unique<std::vector<std::vector<Edge>>>(std::vector<std::vector<Edge>>{});
    edges->resize(4);

    auto emptyAction = std::make_shared<EmptyAction>(EmptyAction{});
    auto goToNextPlayerAction = std::make_shared<GoToNextPlayerAction>(GoToNextPlayerAction{});

    auto getNextCallFromPlayerAction = std::make_shared<GetNextCallFromPlayerAction>(GetNextCallFromPlayerAction{});
    auto getCallAction = std::make_shared<MultiAction>(MultiAction({getNextCallFromPlayerAction,
                                                                    goToNextPlayerAction}));
    auto endAuctionAction = std::make_shared<EndAuctionAction>(EndAuctionAction{});

    auto bridgeDealAction = std::make_shared<BridgeDealAction>(BridgeDealAction{});
    auto currentPlayerStartsNewTrickAction = std::make_shared<CurrentPlayerStartsNewTrickAction>(
            CurrentPlayerStartsNewTrickAction{});
    auto startTrickAction = std::make_shared<MultiAction>(MultiAction({currentPlayerStartsNewTrickAction,
                                                                       goToNextPlayerAction}));

    auto currentPlayerPlaysCardAction = std::make_shared<CurrentPlayerPlaysCardAction>(CurrentPlayerPlaysCardAction{});
    auto playNextCardAction = std::make_shared<MultiAction>(MultiAction({currentPlayerPlaysCardAction,
                                                                         goToNextPlayerAction}));
    auto endTrickAction = std::make_shared<EndTrickAction>(EndTrickAction{});
    auto sendAfterGameInfoAction = std::make_shared<SendAfterGameInfoAction>(SendAfterGameInfoAction{});
    auto restartAction = std::make_shared<BridgeRestartAction>(BridgeRestartAction{});
    auto endGameAction = std::make_shared<MultiAction>(MultiAction({sendAfterGameInfoAction,
                                                                    restartAction}));

    auto alwaysTrueCondition = std::make_shared<AlwaysTrueCondition>(AlwaysTrueCondition{});

    auto auctionToContinueCondition = std::make_shared<AuctionToContinueCondition>(AuctionToContinueCondition{});
    auto auctionToEndCondition = std::make_shared<NotCondition>(NotCondition(auctionToContinueCondition));

    auto handIsEmptyCondition = std::make_shared<HandSizeUnderXCondition>(HandSizeUnderXCondition{1});
    auto handIsNotEmptyCondition = std::make_shared<NotCondition>(NotCondition{handIsEmptyCondition});
    auto currentTrickIsFullCondition = std::make_shared<CurrentTrickIsFullCondition>(CurrentTrickIsFullCondition{});
    auto currentTrickIsNotFullCondition = std::make_shared<NotCondition>(NotCondition{currentTrickIsFullCondition});

    // AUCTION
    edges->at(0).push_back(Edge("", getCallAction, auctionToContinueCondition, 0));
    edges->at(1).push_back(Edge("", endAuctionAction, auctionToEndCondition, 1));

    // TRICKS
    edges->at(1).push_back(Edge("", bridgeDealAction, alwaysTrueCondition, 2));
    edges->at(2).push_back(Edge("", startTrickAction, handIsNotEmptyCondition, 3));
    edges->at(2).push_back(Edge("", restartAction, handIsEmptyCondition, 0));
    edges->at(3).push_back(Edge("", playNextCardAction, currentTrickIsNotFullCondition, 3));
    edges->at(3).push_back(Edge("", endTrickAction, currentTrickIsFullCondition, 2));


    auto graph = std::make_unique<Graph>(Graph{std::move(edges), componentProvider, 0});
    return Game{componentProvider, std::move(graph)};
}
