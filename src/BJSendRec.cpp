//
// Created by przem on 06.05.2024.
//

#include "../include/BJSendRec.hpp"

BJSendRec::BJSendRec(LocalConnectionManager &lcm): lcm{lcm} {
}

std::string BJSendRec::getMessage(std::string) {
    return {};
}

std::string BJSendRec::sendRec(std::string s, PlayerAddress i) {
    send(s, i);

    return lcm.receiveFromUser(i);
}

void BJSendRec::send(std::string s, PlayerAddress i) {
    lcm.send(s + '\n', i);


}
