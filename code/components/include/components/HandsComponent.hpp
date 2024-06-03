#pragma once

#include "cards/PlayingCard.hpp"
#include "cards/CardHolder.hpp"
#include "Component.hpp"
#include <vector>

class ComponentProvider;

class ConnectionComponent;

class HandsComponent : public Component {
private:
    std::vector<std::vector<std::unique_ptr<CardHolder>>> hands;

    ConnectionComponent &getConnectionComponent();

    std::shared_ptr<ComponentProvider> componentProvider;
    unsigned int numberOfPlayers;
public:
    HandsComponent(std::shared_ptr<ComponentProvider>, unsigned int);

    std::vector<std::unique_ptr<CardHolder>> &getHand(PlayerIndex);

    void addSecretCardToPlayer(PlayerIndex, std::unique_ptr<CardHolder>);

    void addOpenCardToPlayer(PlayerIndex, std::unique_ptr<CardHolder>);

    std::unique_ptr<CardHolder> removeAndReturnGivenCardFromPlayer(PlayerIndex, size_t);

    void clearPlayersHand(PlayerIndex);

    //TODO this but single card (why??)
    void showPlayersCards(PlayerIndex);

    void splitHand(PlayerIndex);

    void restart();
};