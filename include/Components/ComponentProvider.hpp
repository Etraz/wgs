#pragma once

#include "HandsComponent.hpp"
#include "Cards/DeckComponent.hpp"
#include "ChipsComponent.hpp"
#include "ConnectionComponent.hpp"

class ComponentProvider {
private:
    HandsComponent &handsComponent;
    DeckComponent &playingCardDeck;
    ChipsComponent &chipsComponent;
    ConnectionComponent &connectionComponent;
    PlayerIndex nextPlayerIndex{1}; // 0 dealer, 1 player
    bool gameToContinue{true};
public:
    ComponentProvider(HandsComponent &,
                      DeckComponent &,
                      ChipsComponent &,
                      ConnectionComponent &);

    //TODO new component for this
    PlayerIndex getNextPlayer();

    void setNextPlayer(PlayerIndex);

    void setGameToContinue(bool);

    HandsComponent &getHandsComponent() const;

    DeckComponent &getPlayingCardsDecks() const;

    ChipsComponent &getChipsComponent() const;

    ConnectionComponent &getConnectionComponent() const;

    bool isGameToContinue() const;
};