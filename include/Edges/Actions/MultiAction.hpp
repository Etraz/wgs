#pragma once

#include "Action.hpp"

class MultiAction : public Action {
private:
    std::vector<std::shared_ptr<Action>> actions;
public:
    explicit MultiAction(std::vector<std::shared_ptr<Action>>);

    void run(ComponentProvider &) override;
};