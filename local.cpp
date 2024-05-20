#include "code/factories/include/factories/BlackjackFactory.hpp"
#include "code/connection/include/connection/LocalSendRec.hpp"

int main(int, char **) {
    std::vector<PlayerAddress> addresses{};
    addresses.push_back(1);
    addresses.push_back(2);
    addresses.push_back(3);
    addresses.push_back(4);
    Game game = BlackjackFactory::make(std::make_unique<LocalSendRec>(LocalSendRec{}), addresses);
    game.start();
}
