#include "actions/bridge/BridgeDealAction.hpp"

void BridgeDealAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &deck = dynamic_cast<CardDeck &>(componentProvider.getComponent("CardDeck"));

    for (PlayerIndex playerIndex = 0; playerIndex < 4; playerIndex++)
        for (int i = 0; i < 13; i++)
            hands.addSecretCardToPlayer(playerIndex, deck.getCard());
}
