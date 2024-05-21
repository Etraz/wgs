#pragma once

#include "edges/Action.hpp"

class ShowPlayersHandAction : public Action {
    void run(ComponentProvider &) override;
};