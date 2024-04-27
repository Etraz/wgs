#pragma once

#include "Cards/PlayingCard.hpp"
#include "Cards/CardHolder.hpp"
#include "Component.hpp"
#include <vector>

class ComponentProvider;

class ConnectionComponent;

class HandsComponent : public Component {
private:
    std::vector<std::vector<std::unique_ptr<CardHolder>>> hands;

    ConnectionComponent &getConnectionComponent();

    ComponentProvider &componentProvider;
    unsigned int numberOfPlayers;
public:
    HandsComponent(ComponentProvider &, unsigned int);

    [[nodiscard]] const std::vector<std::unique_ptr<CardHolder>> &getHand(PlayerIndex) const;

    void addCardToPlayer(PlayerIndex, std::unique_ptr<CardHolder>);

    //TODO this but single card (why??)
    void showPlayersCards(PlayerIndex);

    void splitHand(PlayerIndex);

    void restart();
};