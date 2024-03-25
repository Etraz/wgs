#pragma once

#include "Edges/Edge.hpp"
#include <vector>

class Graph {
private:
    std::vector<std::vector<Edge>> &edges;
    ComponentProvider &componentProvider;
    int currentVertex;

    int askPlayerForMove(std::string);

public:
    Graph(std::vector<std::vector<Edge>> &, ComponentProvider &, int);

    void move();
};
