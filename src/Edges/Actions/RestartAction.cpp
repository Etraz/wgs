#include "../../../include/Edges/Actions/RestartAction.hpp"

void RestartAction::run(ComponentProvider &componentProvider) {
    auto & hands = dynamic_cast<HandsComponent &>(componentProvider.getComponent("HandsComponent"));
    auto & players = dynamic_cast<PlayerComponent &>(componentProvider.getComponent("PlayersComponent"));
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    auto & chips = dynamic_cast<ChipsComponent &>(componentProvider.getComponent("ChipsComponent"));
    auto & deck = dynamic_cast<DeckComponent &>(componentProvider.getComponent("DeckComponent"));

    hands.restart();
    players.restart();
    connection.restart();
    chips.restart();
    deck.restart();
}
