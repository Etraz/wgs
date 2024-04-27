#include "../../include/Components/HandsComponent.hpp"
#include "../../include/Components/ComponentProvider.hpp"

const std::vector<std::unique_ptr<CardHolder>> &HandsComponent::getHand(PlayerIndex index) const {
    return hands[index];
}

void HandsComponent::addCardToPlayer(PlayerIndex index, std::unique_ptr<CardHolder> cardHolder) {
    std::string message = "ActionDrawCard:" + to_string(index) + ';' + std::to_string(cardHolder->getIndex()) + ';' +
                          cardHolder->getCard().serialize();
    getConnectionComponent().sendBroadcast(message);
    hands[index].push_back(std::move(cardHolder));
}

void HandsComponent::showPlayersCards(PlayerIndex index) {
    for (auto &cardHolder: hands[index]) {
        auto &card = dynamic_cast<const PlayingCard &>(cardHolder->getCard());
        if (!card.isShown()) {
            cardHolder->reverseCard();
            std::string message = "ActionChangeCard:" + std::to_string(cardHolder->getIndex()) + ';' +
                                  cardHolder->getCard().serialize();
            getConnectionComponent().sendBroadcast(message);
        }
    }
}

HandsComponent::HandsComponent(ComponentProvider &componentProvider,
                               unsigned int numberOfPlayers) :
        componentProvider{componentProvider},
        numberOfPlayers{numberOfPlayers} {
    hands.resize(numberOfPlayers + 1);
}

ConnectionComponent &HandsComponent::getConnectionComponent() {
    return dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
}

void HandsComponent::restart() {
    for (size_t i = hands.size() - 1; i >= 0; i++) {
        auto &hand = hands[i];
        for (auto &card: hand)
            card->returnCard();
        hand.clear();
        getConnectionComponent().sendBroadcast("ActionClearHand:" + std::to_string(i));
        if (i > numberOfPlayers)
            getConnectionComponent().sendBroadcast("ActionRemoveHand:" + std::to_string(i));
    }
    hands.resize(numberOfPlayers + 1);
}

void HandsComponent::splitHand(PlayerIndex index) {
    auto &deck = dynamic_cast<DeckComponent &>(componentProvider.getComponent("DeckComponent"));
    PlayerIndex newHand = hands.size();
    hands.resize(newHand + 1);
    std::unique_ptr<CardHolder> cardHolder{std::move(hands[index][1])};
    hands[index].resize(1);
    getConnectionComponent().sendBroadcast("ActionRemoveCard:" + std::to_string(cardHolder->getIndex()));
    addCardToPlayer(newHand, std::move(cardHolder));
    addCardToPlayer(index, std::move(deck.getCard()));
    addCardToPlayer(newHand, std::move(deck.getCard()));
}