#pragma once

#include "edges/Action.hpp"

class ShowDealersCardsAction : public Action {
    void run(ComponentProvider &) override;
};