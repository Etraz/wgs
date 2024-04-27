#pragma once

#include "Action.hpp"

class GoToNextPlayerAction : public Action {
    void run(ComponentProvider &) override;
};
