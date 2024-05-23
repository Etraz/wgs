#include <iostream>
#include "factories/BlackjackFactory.hpp"
#include "connection/LocalSendRec.hpp"
#include "components/cards/BridgeCall.hpp"

int main(int, char **) {
    std::string s_1NT = "1;32";
    auto c_1NT = BridgeCall{s_1NT};
    std::cout << "number = " << c_1NT.getNumber() << " suite = " << ToString(c_1NT.getSuite()) << std::endl;
    std::string s_7hearts = "7;8";
    auto c_7hearts = BridgeCall{s_7hearts};
    std::cout << "number = " << c_7hearts.getNumber() << " suite = " << ToString(c_7hearts.getSuite()) << std::endl;
    std::string s_double = "-1;1";
    auto c_double = BridgeCall{s_double};
    std::cout << "number = " << c_double.getNumber() << " suite = " << ToString(c_double.getSuite()) << std::endl;

//    std::vector<PlayerAddress> addresses{};
//    addresses.push_back(1);
//    addresses.push_back(2);
//    addresses.push_back(3);
//    addresses.push_back(4);
//    Game game = BlackjackFactory::make(std::make_unique<LocalSendRec>(LocalSendRec{}), addresses);
//    game.start();
}
