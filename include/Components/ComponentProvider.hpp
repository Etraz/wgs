#pragma once

#include "HandsComponent.hpp"
#include "PlayingCardsDeck.hpp"
#include "ChipsComponent.hpp"
#include "ConnectionComponent.hpp"

class ComponentProvider {
private:
    HandsComponent &handsComponent;
    PlayingCardsDeck &playingCardDeck;
    ChipsComponent &chipsComponent;
    ConnectionComponent &connectionComponent;
    bool playerNext{true};
    bool gameToContinue{true};
public:
    ComponentProvider(HandsComponent &,
                      PlayingCardsDeck &,
                      ChipsComponent &,
                      ConnectionComponent &);

    bool isPlayerNext();

    void setPlayerNext(bool);

    void setGameToContinue(bool);

    HandsComponent &getHandsComponent() const;

    PlayingCardsDeck &getPlayingCardsDecks() const;

    ChipsComponent &getChipsComponent() const;

    ConnectionComponent &getConnectionComponent() const;

    bool isGameToContinue() const;
};