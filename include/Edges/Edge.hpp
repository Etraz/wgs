#pragma once

#include "../Components/ComponentProvider.hpp"
#include "Actions/Action.hpp"
#include "Conditions/Condition.hpp"


class Edge {
    std::string message;
    std::shared_ptr<Action> action;
    std::shared_ptr<Condition> condition;
    int end;
public:
    Edge(std::string, std::shared_ptr<Action>, std::shared_ptr<Condition>, int);

    bool isAccessible(ComponentProvider &);

    int choose(ComponentProvider &);

    std::string getMessage() const;
};