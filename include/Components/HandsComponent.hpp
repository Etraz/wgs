#pragma once

#include "Cards/PlayingCard.hpp"
#include "Cards/CardHolder.hpp"
#include "Component.hpp"
#include <vector>

class ConnectionComponent;

class HandsComponent : public Component{
private:
    std::vector<std::unique_ptr<CardHolder>> players, dealers;
    ConnectionComponent & connectionComponent;
public:
    explicit HandsComponent(ConnectionComponent &);
    const std::vector<std::unique_ptr<CardHolder>> & getPlayersHand() const ;
    const std::vector<std::unique_ptr<CardHolder>> & getDealersHand() const ;
    void clear();
    void addCardToPlayer(PlayerIndex, std::unique_ptr<CardHolder>);
    //TODO this but single card
    void showPlayersCards(PlayerIndex);
};