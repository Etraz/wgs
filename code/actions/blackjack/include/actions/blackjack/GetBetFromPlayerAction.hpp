#pragma once

#include "edges/Action.hpp"

class GetBetFromPlayerAction : public Action {
public:
    void run(ComponentProvider &) override;
};
