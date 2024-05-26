#pragma once

#include "edges/Condition.hpp"

class CurrentTricksFullIsCondition : public Condition{
public:
    bool check(ComponentProvider &) override;
};