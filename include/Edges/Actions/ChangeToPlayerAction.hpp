#pragma once

#include "Action.hpp"

class ChangeToPlayerAction : public Action {
    void run(ComponentProvider &) override;
};
