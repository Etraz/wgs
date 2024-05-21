#pragma once

#include "edges/Action.hpp"

class PlayerDrawsCardAction : public Action {
private:
    bool isCardSecret;
public:
    explicit PlayerDrawsCardAction(bool = true);
    void run(ComponentProvider &) override;
};