#include "actions/blackjack/MultiAction.hpp"

#include <utility>

MultiAction::MultiAction(std::vector<std::shared_ptr<Action>> actions) : actions{std::move(actions)} {}

void MultiAction::run(ComponentProvider &componentProvider) {
    for (auto &action: actions)
        action->run(componentProvider);
}
