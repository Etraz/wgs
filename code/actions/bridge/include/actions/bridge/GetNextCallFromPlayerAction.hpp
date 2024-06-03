#pragma once

#include "edges/Action.hpp"

class GetNextCallFromPlayerAction : public Action {
public:
    void run(ComponentProvider &provider) override;
};