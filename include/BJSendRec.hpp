//
// Created by przem on 06.05.2024.
//

#ifndef WGS_BJSENDREC_HPP
#define WGS_BJSENDREC_HPP

#include "AbstractSendRec.hpp"
#include "Server/LocalConnectionManager.hpp"


class BJSendRec : public AbstractSendRec {

private:
    LocalConnectionManager &  lcm;

public:
    explicit BJSendRec(LocalConnectionManager & lcm);

    std::string getMessage(std::string) override;

    std::string sendRec(std::string, PlayerAddress) override;

    void send(std::string, PlayerAddress) override;

};


#endif //WGS_BJSENDREC_HPP
