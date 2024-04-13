#include "../include/TempSender.hpp"
#include <iostream>
#include <sys/socket.h>
#include <thread>
#include <vector>
// message = "AskBet:{owned}"
std::string TempSender::getMessage(std::string message) {
    int x = -1;
    if (message.starts_with("AskBet:"))
        x = askForBet(std::stoi(message.substr(7)));
    else if (message.starts_with("AskMove:"))
        x = askForMove(message);
    else
        ::send(fd, message.c_str(), message.size(), 0);
    std::cout << message << std::endl;// send
    ::send(fd, "\n", 1, 0);
    if (x == -1)
        return "";
    return std::to_string(x);
}

int TempSender::askForBet(int owned) {
    int bet;
    while (true) {
        std::string s = "PLEASE PLACE THE BET. YOU OWN ";
        s.append(std::to_string(owned));
        s.append("\nYOUR MOVE: ");
        ::send(fd, s.c_str(), s.size(), 0);

        std::cout << s;// send
        char buf[2048];
        int size = ::recv(fd, buf, 2047, 0);
        bet = std::atoi(buf);
        if (bet > 0 and bet <= owned)
            break;
        ::send(fd, "INCORRECT INPUT\n", 16, 0);// send
    }
    return bet;
}

// message = "AskMove:{numberOfMoves};{Message to print}
int TempSender::askForMove(std::string message) {
    int startOfMessageToPrint = message.find(';'), numberOfMoves = std::stoi(
            message.substr(8, startOfMessageToPrint - 8)), move;
    std::string toPrint = message.substr(startOfMessageToPrint + 1);
    toPrint.append("\nPLEASE CHOOSE YOUR MOVE.\nYOUR MOVE: ");
    while (true) {
        std::cout << toPrint;// send
        ::send(fd, toPrint.c_str(), toPrint.size(), 0);
        char buf[1024];
        ::recv(fd, buf, 1024, 0);
        move = std::atoi(buf);
        if (move > 0 and move <= numberOfMoves)
            break;
        std::cout << "INCORRECT INPUT" << std::endl;// send
        ::send(fd, "INCORRECT INPUT\n", 16, 0);
    }
    return move;
}

TempSender::TempSender(int fd): fd{fd} {

}
