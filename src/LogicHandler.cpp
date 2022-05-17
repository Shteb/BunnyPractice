#include "../include/LogicHandler.hpp"
#include "../include/Colour.hpp"

struct lessThanKey {//Sorting condition
    inline bool operator() (const shared_ptr<Bunny>& bunny1, const shared_ptr<Bunny>& bunny2) {
        return ((bunny1->getAge()) < (bunny2->getAge()));
    }
};

LogicHandler::LogicHandler() {
    //generating one male and one female bunny to ensure the program goes somewhere.
    _bunnyList.push_back(shared_ptr<Bunny>(new Bunny(true, Colour(rand() % 4), rand() % 10)));
    _bunnyList.push_back(shared_ptr<Bunny>(new Bunny(false, Colour(rand() % 4), rand() % 10)));

    //generating an additional 3 bunnies of random colour, sex and age.
    for (int i = 0;i < 3; i++) {
        _bunnyList.push_back(shared_ptr<Bunny>(new Bunny(rand() % 2, Colour(rand() % 4), rand() % 10)));
    }

    //Sorting inital list
    _bunnyList.sort(lessThanKey());

    //Initial report
    doReport();
    system("pause");
}

string LogicHandler::addChild(Colour colourIn) {
    shared_ptr<Bunny> toReturn(new Bunny(rand() % 2, colourIn, 0));
    _bunnyList.push_back(toReturn);
    return toReturn->getName();
}

void LogicHandler::doReport() {
    for (auto const& i : _bunnyList) {
        cout << "Name: " << i->getName() << ", Gender: " << i->getGenderString() << ", Coat: " << i->getColourString() << ", Age: " << i->getAge() << ", Health: " << i->getIsInfectedString() << ".\n";
    }
}



int LogicHandler::LogicLoop() {
    list<shared_ptr<Bunny>> toKill = {};
    list<shared_ptr<Bunny>> toInfect = {};
    int infectedCount = 0;
    bool agedMalePresent = false;
    list<Colour> childColours = {};

    //iterate through all bunnies, extract information and perform logic.
    for (auto const& i : _bunnyList) {
        //age and add dead bunnies to kill list.
        i->growOld();
        if (i->checkAgeDeath()) {
            toKill.push_front(i);
        }

        //check gender and maturity and set flags for birth later.
        if (i->getAge() >= 2) {
            if (!i->getIsInfected()) {
                if (i->getIsMale()) {
                    agedMalePresent = true;
                }
                else {
                    childColours.push_back(i->getColour());
                }
            }
        }

        //infected count.
        if (i->getIsInfected()) {
            infectedCount++;
        }
    }

    //Infect handling
    std::sample( //randomly select n bunnies and infect them, where n = infectedCount.
        _bunnyList.begin(),
        _bunnyList.end(),
        std::back_inserter(toInfect),
        infectedCount,
        std::mt19937{ std::random_device{}() });
    for (auto i : toInfect) {
        i->setIsInfected();
    }

    //Birth handling
    if (agedMalePresent) { //If mature male flag is true, add a child of every colour of mature female.
        for (auto i : childColours) {
            cout << addChild(i) << " was born!\n";
        }
    }

    //Kill handling
    if (_bunnyList.size() > 1000) { //Food shortage, randomly samples half and adds them to kill list.
        std::sample(
            _bunnyList.begin(),
            _bunnyList.end(),
            std::back_inserter(toKill),
            (_bunnyList.size() / 2),
            std::mt19937{ std::random_device{}() });
    }
    for (shared_ptr<Bunny> const i : toKill) { //Executes killing on all bunnys in kill list.
        cout << i->getName() << " has died!\n";
        _bunnyList.remove(i);
    }

    //Console out.
    doReport();

    //Wait for user input
    system("pause");
    cout << "\n";

    //Exit of all bunnies dead
    if (_bunnyList.size() == 0) {
        return 0;
    }
    return 1;
}