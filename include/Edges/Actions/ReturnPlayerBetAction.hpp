#pragma once

#include "Action.hpp"

class ReturnPlayerBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};
