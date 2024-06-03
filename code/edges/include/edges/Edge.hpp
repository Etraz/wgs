#pragma once

#include "components/ComponentProvider.hpp"
#include "Action.hpp"
#include "Condition.hpp"


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