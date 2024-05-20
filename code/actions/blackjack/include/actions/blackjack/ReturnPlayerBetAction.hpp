#pragma once

#include "edges/Action.hpp"

class ReturnPlayerBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};
