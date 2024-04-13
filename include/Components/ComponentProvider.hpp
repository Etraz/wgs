#pragma once

#include "Cards/DeckComponent.hpp"
#include "ChipsComponent.hpp"
#include "ConnectionComponent.hpp"
#include "HandsComponent.hpp"
#include <map>

class ComponentProvider {
private:
    std::map<std::string, std::unique_ptr<Component>> Components;
    PlayerIndex nextPlayerIndex{1}; // 0 dealer, 1 player
    bool gameToContinue{true};
public:
    ComponentProvider() = default;
    //TODO new component for this
    PlayerIndex getNextPlayer() const;

    void addComponent(std::unique_ptr<Component>, const std::string&);

    Component & getComponent(const std::string&) const;

    void setNextPlayer(PlayerIndex);

    void setGameToContinue(bool);

    bool isGameToContinue() const;
};