#include "../../include/Edges/Edge.hpp"

Edge::Edge(std::string message,
           Action &action,
           Condition &condition,
           int end) :
        message{message},
        action{action},
        condition{condition},
        end{end} {}

bool Edge::isAccessible(ComponentProvider &componentProvider) {
    return condition.check(componentProvider);
}

int Edge::choose(ComponentProvider &componentProvider) {
    action.run(componentProvider);
    return end;
}

std::string Edge::getMessage() const {
    return message;
}