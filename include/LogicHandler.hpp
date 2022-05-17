#pragma once

#include "../include/Bunny.hpp"
#include <iostream>
#include <list>
#include <memory>
#include <cstdlib>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::shared_ptr;
using std::list;

class LogicHandler {
protected:
    list<shared_ptr<Bunny>> _bunnyList;

    string addChild(Colour colourIn); //Adds a child of age 0, mothers colour.
    void doReport();
public:
    LogicHandler();
    int LogicLoop();
};