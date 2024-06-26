#include "game/Graph.hpp"
#include <iostream>
#include <utility>

Graph::Graph(std::unique_ptr<std::vector<std::vector<Edge>>> &&edges,
             std::shared_ptr<ComponentProvider> componentProvider,
             int startingVertex) :
        edges{std::move(edges)},
        componentProvider{std::move(componentProvider)},
        currentVertex{startingVertex} {}

void Graph::move() {
//    std::cout << "current vertex = " << currentVertex << std::endl;
    auto &neighbours = edges->at(currentVertex);
    std::vector<int> possible;
    for (int i = 0; i < neighbours.size(); ++i) {
        Edge e = neighbours[i];
        if (e.isAccessible(*componentProvider))
            possible.push_back(i);
    }
    if (possible.empty())
        throw std::runtime_error("No possible move");
    if (possible.size() == 1)
        currentVertex = neighbours[possible[0]].choose(*componentProvider);
    else {
        std::string message = "AskMove:";
        message += std::to_string(possible.size());
        for (int i: possible) {
            message += ';';
            message += neighbours[i].getMessage();
        }
        int nextMove = askPlayerForMove(message);
        currentVertex = neighbours[possible[nextMove]].choose(*componentProvider);
    }
}

int Graph::askPlayerForMove(const std::string &message) {
    auto &connection = dynamic_cast<ConnectionComponent &>(componentProvider->getComponent("ConnectionComponent"));
    auto &players = dynamic_cast<PlayerComponent &>(componentProvider->getComponent("PlayersComponent"));
    auto response = connection.sendRec(message, players.getCurrentPlayer());

    return std::stoi(response.substr(response.find(':') + 1));
}
