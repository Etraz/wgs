#pragma once

#include "../Components/ComponentProvider.hpp"
#include "Actions/Action.hpp"
#include "Conditions/Condition.hpp"


class Edge {
    std::string message;
    Action &action;
    Condition &condition;
    int end;
public:
    Edge(std::string, Action &, Condition &, int);

    bool isAccessible(ComponentProvider &);

    int choose(ComponentProvider &);

    std::string getMessage() const;
};