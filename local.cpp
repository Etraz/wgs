#include "include/BlackjackFactory.hpp"
#include "include/LocalSendRec.hpp"

int main(int, char **) {
    std::vector<PlayerAddress> addresses{};
    addresses.push_back(1);
    addresses.push_back(2);
    addresses.push_back(3);
    addresses.push_back(4);
    Game game = BlackjackFactory::make(std::make_unique<LocalSendRec>(LocalSendRec{}), addresses);
    game.start();
}
