//
// Created by przem on 06.05.2024.
//

#include "connection/ConcreteSendRec.hpp"
#include <iostream>

ConcreteSendRec::ConcreteSendRec(LocalConnectionManager &lcm) : lcm{lcm} {
}

std::string ConcreteSendRec::sendRec(std::string s, PlayerAddress i) {
    send(s, i);
    std::cout << "SendRec" << std::endl;

    return lcm.receiveFromUser(i);
}

void ConcreteSendRec::send(std::string s, PlayerAddress i) {
    lcm.send(s + '\n', i);
    std::cout << "Send to " << i << '\n' << s << std::endl;


}
