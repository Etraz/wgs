#pragma once

#include "Action.hpp"

class ShowDealersCardsAction : public Action {
    void run(ComponentProvider &) override;
};