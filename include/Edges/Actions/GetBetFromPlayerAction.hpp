#pragma once

#include "Action.hpp"

class GetBetFromPlayerAction : public Action {
public:
    void run(ComponentProvider &) override;
};
