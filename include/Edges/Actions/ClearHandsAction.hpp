#pragma once

#include "Action.hpp"

class ClearHandsAction : public Action {
public:
    void run(ComponentProvider &) override;
};
