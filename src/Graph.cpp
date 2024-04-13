#include "../include/Graph.hpp"
#include <iostream>

Graph::Graph(std::vector<std::vector<Edge>> &edges,
             ComponentProvider &componentProvider,
             int startingVertex) :
        edges{edges},
        componentProvider{componentProvider},
        currentVertex{startingVertex} {}

void Graph::move() {
//    std::cout << "current vertex = " << currentVertex << std::endl;
    auto &neighbours = edges[currentVertex];
    std::vector<int> possible;
    for (int i = 0; i < neighbours.size(); ++i) {
        Edge e = neighbours[i];
        if (e.isAccessible(componentProvider))
            possible.push_back(i);
    }
    if (possible.empty())
        throw std::runtime_error("No possible move");
    if (possible.size() == 1)
        currentVertex = neighbours[possible[0]].choose(componentProvider);
    else {
        std::string message = "AskMove:";
        message += std::to_string(possible.size());
        message += ';';
        for (int i = 0; i < possible.size(); ++i) {
            message += std::to_string(i + 1);
            message += ". ";
            message += neighbours[possible[i]].getMessage();
        }
        int nextMove = askPlayerForMove(message);
        currentVertex = neighbours[possible[nextMove]].choose(componentProvider);
    }
}

int Graph::askPlayerForMove(std::string message) {
    auto & connection = dynamic_cast<ConnectionComponent &>(componentProvider.getComponent("ConnectionComponent"));
    return std::stoi(connection.sendMessage(message)) - 1;
}