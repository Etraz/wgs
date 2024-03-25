#include "../../include/Components/ComponentProvider.hpp"

ComponentProvider::ComponentProvider(HandsComponent &handsComponent,
                                     PlayingCardsDeck &playingCardsDeck,
                                     ChipsComponent &chipsComponent,
                                     ConnectionComponent &connectionComponent) :
        handsComponent{handsComponent},
        playingCardDeck{playingCardsDeck},
        chipsComponent{chipsComponent},
        connectionComponent{connectionComponent} {}

void ComponentProvider::setPlayerNext(bool playerNext) {
    this->playerNext = playerNext;
}

bool ComponentProvider::isPlayerNext() {
    return playerNext;
}

HandsComponent &ComponentProvider::getHandsComponent() const {
    return handsComponent;
}

PlayingCardsDeck &ComponentProvider::getPlayingCardsDecks() const {
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
