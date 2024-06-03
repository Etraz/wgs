#include "factories/BridgeFactory.hpp"
#include "connection/LocalSendRec.hpp"
#include "components/cards/BridgeCall.hpp"

int main(int, char **) {
    std::vector<PlayerAddress> addresses{};
    addresses.push_back(1);
    addresses.push_back(2);
    addresses.push_back(3);
    addresses.push_back(4);
    Game game = BridgeFactory::make(std::make_unique<LocalSendRec>(LocalSendRec{}), addresses);
    game.start();
}
