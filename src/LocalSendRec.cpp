#include "../include/LocalSendRec.hpp"
#include <iostream>

std::string LocalSendRec::askForBet(int owned) {
    int bet{};
    while (true) {
        std::cout << "PLEASE PLACE THE BET. YOU OWN " << owned << "\nYOUR MOVE: ";
        std::cin >> bet;
        if (bet > 0 and bet <= owned)
            break;
        std::cout << "INCORRECT INPUT" << std::endl;
    }
    return "AskBetResp:" + std::to_string(bet);
}

// message = "AskMove:{numberOfMoves};{Message to print}
std::string LocalSendRec::askForMove(const std::string &message) {
    size_t startOfMessageToPrint = message.find(';');
    int numberOfMoves = std::stoi(
            message.substr(8, startOfMessageToPrint - 8)), move{};
    std::string toPrint = message.substr(startOfMessageToPrint + 1);
    while (true) {
        std::cout << toPrint << "\nPLEASE CHOOSE YOUR MOVE.\nYOUR MOVE: ";
        std::cin >> move;
        if (move > 0 and move <= numberOfMoves)
            break;
        std::cout << "INCORRECT INPUT" << std::endl;
    }
    return "AskMoveResp:" + std::to_string(move);
}

std::string LocalSendRec::sendRec(std::string message, PlayerAddress address) {
    std::string response;
    std::cout << "SendRec to " << address << std::endl;
    if (message.starts_with("AskBet:"))
        response = askForBet(std::stoi(message.substr(7)));
    else if (message.starts_with("AskMove:"))
        response = askForMove(message);
    if (response.empty())
        throw std::runtime_error{"Messege type not recognized"};
    return response;
}

void LocalSendRec::send(std::string message, PlayerAddress address) {
    if (address != 0)
        std::cout << "Send to " << address << '\n' << message << std::endl;
}
