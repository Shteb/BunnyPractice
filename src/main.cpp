#include "../include/LogicHandler.hpp"
#include <iostream>
using std::cout;
using std::cin;

int main() {
    //initialise logic handler here
    srand((unsigned)time(0));
    LogicHandler logicHan;
    //being logic handler while loop here
    while (logicHan.LogicLoop()) {
    }
    cout << "All bunnies have perished to the infection.\n\nPress enter to exit.\n\n";
    std::string userIn;
    cin >> userIn;
}