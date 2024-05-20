# pragma once

#include "edges/Action.hpp"

class ReturnHalfOfPlayerBetAction : public Action {
public:
    void run(ComponentProvider &) override;
};
