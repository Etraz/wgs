#pragma once

#include "edges/Action.hpp"

class SendAfterGameInfoAction : public Action{
public:
    void run(ComponentProvider &) override;
};