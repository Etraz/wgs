# pragma once

#include "Action.hpp"

class ReturnHalfOfPlayerBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};
