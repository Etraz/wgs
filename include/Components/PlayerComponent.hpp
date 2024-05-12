#pragma once

#include "Component.hpp"
#include <memory>
#include <queue>

class ComponentProvider;

class PlayerComponent : public Component {
private:
    //TODO change to boost::circular_buffer
    std::deque<PlayerIndex> players;
    PlayerIndex maxPlayerIndex{};
    std::shared_ptr<ComponentProvider> componentProvider;
    unsigned int numberOfPlayers;
public:
    PlayerComponent(std::shared_ptr<ComponentProvider>, unsigned int);

    PlayerIndex getCurrentPlayer();

    void nextPlayer();

    void split();

    void restart();
};


