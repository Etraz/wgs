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



    ConcreteSendRec connection{cm.getTable(0)};
    PlayerIndex numberOfPlayers = 1;
    for (int i = 0; i < numberOfPlayers; i++) {
        cm.addUserToTemporary(0);
        std::cout << "User added " << i << "\n";
    }

//    Game blackjack = BlackjackFactory::make(sendRec, playerAddresses);
//    blackjack.start();

    cm.close();
}
