#pragma once

#include "edges/Action.hpp"

class PlayerSplitsAction : public Action {
    void run(ComponentProvider &) override;

};
