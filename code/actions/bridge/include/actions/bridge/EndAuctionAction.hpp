#pragma once

#include "edges/Action.hpp"

class EndAuctionAction : public Action {
public:
    void run(ComponentProvider &) override;
};