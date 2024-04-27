#pragma once

#include "Component.hpp"
#include <queue>

class ComponentProvider;

class PlayerComponent : public Component {
private:
    //TODO change to boost::circular_buffer
    std::deque<PlayerIndex> players;
    PlayerIndex maxPlayerIndex{};
    ComponentProvider &componentProvider;
    unsigned int numberOfPlayers;
public:
    PlayerComponent(ComponentProvider &, unsigned int);

    PlayerIndex getCurrentPlayer();

    void nextPlayer();

    void split();

    void restart();
};


