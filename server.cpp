#include <iostream>
#include "include/Server/ConnectionManager.hpp"
#include "include/ConcreteSendRec.hpp"
#include "include/Components/HandsComponent.hpp"

#include "include/BlackjackFactory.hpp"

int main(int, char **) {

    ConnectionManager cm{};
    cm.startup(8080);

    cm.addTable();
    std::cout << "Table added!\n";
    // PASS communication into the game!

    auto lcm = cm.getTable(0);

    std::unique_ptr<ConcreteSendRec> sendRec = std::make_unique<ConcreteSendRec>(ConcreteSendRec{lcm});
    PlayerIndex numberOfPlayers = 1;
    for (int i = 0; i < numberOfPlayers; i++) {
        cm.addUserToTemporary(0);
        std::cout << "User added " << i << "\n";
    }

    std::vector<PlayerAddress> addresses{};
    //addresses.push_back(1);
    addresses = lcm.getKeys();
    Game blackjack = BlackjackFactory::make(std::move(sendRec), addresses);
    blackjack.start();

    cm.close();
}
