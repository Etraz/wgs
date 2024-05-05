//
// Created by przem on 06.05.2024.
//

#include "../include/BJSendRec.hpp"

BJSendRec::BJSendRec(const LocalConnectionManager &lcm) {
    this->lcm = lcm;
}

std::string BJSendRec::getMessage(std::string) {
    return {};
}

std::string BJSendRec::sendRec(std::string s, PlayerAddress i) {
    lcm.send(s, i);


    return lcm.receiveFromUser(i);
}

void BJSendRec::send(std::string s, PlayerAddress i) {
    lcm.send(s, i);


}
