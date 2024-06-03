#include "components/HandsComponent.hpp"

#include <utility>
#include "components/ComponentProvider.hpp"


void HandsComponent::addSecretCardToPlayer(PlayerIndex index, std::unique_ptr<CardHolder> cardHolder) {
    std::string message = "ActionDrawCard:" + to_string(index) + ';' + std::to_string(cardHolder->getIndex()) + ';' +
                          cardHolder->getCard().serializeReverse();
    getConnectionComponent().sendBroadcast(message);
    message = "ActionChangeCard:" + std::to_string(cardHolder->getIndex()) + ';' + cardHolder->getCard().serialize();
    getConnectionComponent().send(message, index);
    hands[index].push_back(std::move(cardHolder));
}

void HandsComponent::addOpenCardToPlayer(PlayerIndex index, std::unique_ptr<CardHolder> cardHolder) {
    std::string message = "ActionDrawCard:" + to_string(index) + ';' + std::to_string(cardHolder->getIndex()) + ';' +
                          cardHolder->getCard().serialize();
    getConnectionComponent().sendBroadcast(message);
    hands[index].push_back(std::move(cardHolder));
}

void HandsComponent::showPlayersCards(PlayerIndex index) {
    for (auto &cardHolder: hands[index]) {
        auto &card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        std::string message = "ActionChangeCard:" + std::to_string(cardHolder->getIndex()) + ';' +
                              cardHolder->getCard().serialize();
        getConnectionComponent().sendBroadcast(message);
    }
}

HandsComponent::HandsComponent(std::shared_ptr<ComponentProvider> componentProvider,
                               unsigned int numberOfPlayers) :
        componentProvider{std::move(componentProvider)},
        numberOfPlayers{numberOfPlayers} {
    hands.resize(numberOfPlayers + 1);
}

ConnectionComponent &HandsComponent::getConnectionComponent() {
    return dynamic_cast<ConnectionComponent &>(componentProvider->getComponent("ConnectionComponent"));
}

void HandsComponent::restart() {
    for (size_t i = 0; i < hands.size(); i++) {
        clearPlayersHand(i);
        if (i > numberOfPlayers)
            getConnectionComponent().sendBroadcast("ActionRemoveHand:" + std::to_string(i));
    }
    hands.resize(numberOfPlayers + 1);
}

void HandsComponent::splitHand(PlayerIndex index) {
    auto &deck = dynamic_cast<CardDeck &>(componentProvider->getComponent("CardDeck"));
    PlayerIndex newHand = hands.size();
    hands.resize(newHand + 1);
    std::unique_ptr<CardHolder> cardHolder{std::move(hands[index][1])};
    hands[index].resize(1);
    getConnectionComponent().sendBroadcast("ActionRemoveCard:" + std::to_string(cardHolder->getIndex()));
    addOpenCardToPlayer(newHand, std::move(cardHolder));
    addOpenCardToPlayer(index, std::move(deck.getCard()));
    addOpenCardToPlayer(newHand, std::move(deck.getCard()));
}

std::vector<std::unique_ptr<CardHolder>> &HandsComponent::getHand(PlayerIndex index) {
    return hands[index];
}

std::unique_ptr<CardHolder>
HandsComponent::removeAndReturnGivenCardFromPlayer(PlayerIndex playerIndex, size_t cardIndex) {
    std::unique_ptr<CardHolder> toReturn{nullptr};
    for (auto ite = hands[playerIndex].begin(); ite != hands[playerIndex].end(); ite++) {
        if ((*ite)->getIndex() == cardIndex) {
            toReturn = std::unique_ptr<CardHolder>(std::move((*ite)));
            hands[playerIndex].erase(ite);
            return toReturn;
        }
    }
    return toReturn;
}

void HandsComponent::clearPlayersHand(PlayerIndex playerIndex) {
    auto &hand = hands[playerIndex];
    for (auto &card: hand)
        card->returnCard();
    hand.clear();
    getConnectionComponent().sendBroadcast("ActionClearHand:" + std::to_string(playerIndex));
}
