#pragma once
#include "Components/ComponentProvider.hpp"
#include "Graph.hpp"

class Game{
private:
    ComponentProvider & componentProvider;
    Graph & graph;
public:
    Game(ComponentProvider &, Graph &);
    void start();
};