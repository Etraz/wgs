#pragma once

#include "Edges/Edge.hpp"
#include <vector>

class Graph {
private:
    std::unique_ptr<std::vector<std::vector<Edge>>> edges;
    std::shared_ptr<ComponentProvider> componentProvider;
    int currentVertex;

    int askPlayerForMove(const std::string &);

public:
    Graph(std::unique_ptr<std::vector<std::vector<Edge>>> &&, std::shared_ptr<ComponentProvider>, int);

    void move();
};
