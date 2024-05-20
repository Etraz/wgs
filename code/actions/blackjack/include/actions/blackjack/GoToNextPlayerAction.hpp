#pragma once

#include "edges/Action.hpp"

class GoToNextPlayerAction : public Action {
    void run(ComponentProvider &) override;
};
