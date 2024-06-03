#pragma once

#include <memory>
#include <vector>
#include "connection/LocalSendRec.hpp"
#include "game/Game.hpp"

class BridgeFactory {
public:
    static Game make(std::unique_ptr<AbstractSendRec> &&, const std::vector<PlayerAddress> &);
};