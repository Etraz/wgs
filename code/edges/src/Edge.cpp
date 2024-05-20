#include "edges/Edge.hpp"

#include <utility>

Edge::Edge(std::string message,
           std::shared_ptr<Action> action,
           std::shared_ptr<Condition> condition,
           int end) :
        message{std::move(message)},
        action{std::move(action)},
        condition{std::move(condition)},
        end{end} {}

bool Edge::isAccessible(ComponentProvider &componentProvider) {
    return condition->check(componentProvider);
}

int Edge::choose(ComponentProvider &componentProvider) {
    action->run(componentProvider);
    return end;
}

std::string Edge::getMessage() const {
    return message;
}