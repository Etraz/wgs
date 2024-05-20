#include "actions/blackjack/RestartAction.hpp"

void RestartAction::run(ComponentProvider &componentProvider) {
    auto &hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto &chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto &deck = dynamic_cast<CardDeck &>(componentProvider.getComponent("CardDeck"));

    hands.restart();
    players.restart();
    connection.restart();
    chips.restart();
    deck.restart();
}
