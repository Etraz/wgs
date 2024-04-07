#include "../../include/Components/ComponentProvider.hpp"

ComponentProvider::ComponentProvider(HandsComponent &handsComponent,
                                     DeckComponent &playingCardsDeck,
                                     ChipsComponent &chipsComponent,
                                     ConnectionComponent &connectionComponent) :
        handsComponent{handsComponent},
        playingCardDeck{playingCardsDeck},
        chipsComponent{chipsComponent},
        connectionComponent{connectionComponent} {}

void ComponentProvider::setNextPlayer(PlayerIndex playerIndex) {
    this->nextPlayerIndex = playerIndex;
}

PlayerIndex ComponentProvider::getNextPlayer() {
    return nextPlayerIndex;
}

HandsComponent &ComponentProvider::getHandsComponent() const {
    return handsComponent;
}

DeckComponent &ComponentProvider::getPlayingCardsDecks() const {
    return playingCardDeck;
}

ChipsComponent &ComponentProvider::getChipsComponent() const {
    return chipsComponent;
}

ConnectionComponent &ComponentProvider::getConnectionComponent() const {
    return connectionComponent;
}

bool ComponentProvider::isGameToContinue() const {
    return gameToContinue;
}

void ComponentProvider::setGameToContinue(bool gameToContinue) {
    this->gameToContinue = gameToContinue;
}
