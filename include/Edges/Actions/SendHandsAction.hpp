#pragma once
#include "Action.hpp"

class SendHandsAction: public Action {
    void run(ComponentProvider &) override;
};