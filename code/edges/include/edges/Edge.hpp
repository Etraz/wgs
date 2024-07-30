#pragma once

#include "components/ComponentProvider.hpp"
#include "Action.hpp"
#include "Condition.hpp"

#define createEdge(start, action, condition, end) edges->at((start)).push_back(Edge("", (action), (condition), (end)))
#define createEdgeWithMess(start, action, condition, end, mess) edges->at((start)).push_back(Edge((mess), (action), (condition), (end)))



class Edge {
    std::string message;
    std::shared_ptr<Action> action;
    std::shared_ptr<Condition> condition;
    int end;
public:
    Edge(std::string, std::shared_ptr<Action>, std::shared_ptr<Condition>, int);

    bool isAccessible(ComponentProvider &);

    int choose(ComponentProvider &);

    [[nodiscard]] std::string getMessage() const;
};