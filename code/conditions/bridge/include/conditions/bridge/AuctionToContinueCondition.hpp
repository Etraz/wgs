#pragma once

#include "edges/Condition.hpp"

class AuctionToContinueCondition : public Condition {
public:
    bool check(ComponentProvider &) override;
};