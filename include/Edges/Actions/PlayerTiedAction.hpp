#pragma once

#include "Action.hpp"

class PlayerTiedAction : public Action {
public:
    void run(ComponentProvider &) override;
};
