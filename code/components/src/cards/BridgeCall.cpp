#include "components/cards/BridgeCall.hpp"

BridgeCall::BridgeCall(int number,
                       PlayingCardColor suite,
                       BridgeCallType type) :
                       number{number},
                       suite{suite},
                       type{type} {}

// [number];[suite];[type]
BridgeCall::BridgeCall(std::string s) {
    size_t splitPoint = s.find(';');
    number = std::stoi(s.substr(0, splitPoint));
    s = s.substr(splitPoint + 1);
    splitPoint = s.find(';');
    suite = static_cast<PlayingCardColor>(std::stoi(s.substr(0, splitPoint)));
    type = static_cast<BridgeCallType>(std::stoi(s.substr(splitPoint + 1)));
}

PlayingCardColor BridgeCall::getSuite() const {
    return suite;
}

int BridgeCall::getNumber() const {
    return number;
}

BridgeCallType BridgeCall::getType() const {
    return type;
}