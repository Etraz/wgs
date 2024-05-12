#pragma once

#include "Components/ComponentProvider.hpp"
#include "Graph.hpp"

class Game {
private:
    std::shared_ptr<ComponentProvider> componentProvider;
    std::unique_ptr<Graph> graph;
public:
    Game(std::shared_ptr<ComponentProvider>, std::unique_ptr<Graph> &&);

    void start();
};