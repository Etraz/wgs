#pragma once

#include <memory>
#include <vector>
#include "AbstractSendRec.hpp"
#include "Game.hpp"

class BlackjackFactory {
public:
    static Game make(std::unique_ptr<AbstractSendRec> &&, const std::vector<PlayerAddress> &);
};

