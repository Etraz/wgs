#pragma once

#include "edges/Action.hpp"

class ShowPlayersHandAction : public Action {
private:
    PlayerIndex index{};
public:
    explicit ShowPlayersHandAction(PlayerIndex = 0);
    void run(ComponentProvider &) override;
};