//
// Created by przem on 06.05.2024.
//

#ifndef WGS_CONCRETESENDREC_HPP
#define WGS_CONCRETESENDREC_HPP

#include "AbstractSendRec.hpp"
#include "Server/LocalConnectionManager.hpp"


class ConcreteSendRec : public AbstractSendRec {

private:
    LocalConnectionManager &lcm;

public:
    explicit ConcreteSendRec(LocalConnectionManager &lcm);

    std::string sendRec(std::string, PlayerAddress) override;

    void send(std::string, PlayerAddress) override;

};


#endif //WGS_CONCRETESENDREC_HPP
