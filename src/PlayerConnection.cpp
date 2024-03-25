#include "../include/PlayerConnection.hpp"
#include <iostream>

// message = "AskBet:{owned}"
std::string PlayerConnection::getMessage(std::string message) {
    int x = -1;
    if (message.starts_with("AskBet:"))
        x = askForBet(std::stoi(message.substr(7)));
    else if (message.starts_with("AskMove:"))
        x = askForMove(message);
    else
        std::cout << message << std::endl;
    if (x == -1)
        return "";
    return std::to_string(x);
}

int PlayerConnection::askForBet(int owned) {
    int bet;
    while (true) {
        std::cout << "PLEASE PLACE THE BET. YOU OWN " << owned << "\nYOUR MOVE: ";
        std::cin >> bet;
        if (bet > 0 and bet <= owned)
            break;
        std::cout << "INCORRECT INPUT" << std::endl;
    }
    return bet;
}

// message = "AskMove:{numberOfMoves};{Message to print}
int PlayerConnection::askForMove(std::string message) {
    int startOfMessageToPrint = message.find(';'), numberOfMoves = std::stoi(
            message.substr(8, startOfMessageToPrint - 8)), move;
    std::string toPrint = message.substr(startOfMessageToPrint + 1);
    while (true) {
        std::cout << toPrint << "\nPLEASE CHOOSE YOUR MOVE.\nYOUR MOVE: ";
        std::cin >> move;
        if (move > 0 and move <= numberOfMoves)
            break;
        std::cout << "INCORRECT INPUT" << std::endl;
    }
    return move;
}