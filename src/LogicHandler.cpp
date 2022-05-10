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
    for (auto const& i : _bunnyList) {
        cout << i->getName() << ", " << i->getGenderString() << ", " << i->getColourString() << ", " << i->getAge() << ", " << i->getIsInfectedString() << ".\n";
    }
    system("pause");
}

string LogicHandler::addChild(Colour colourIn) {
    shared_ptr<Bunny> toReturn(new Bunny(rand() % 2, colourIn, 0));
    _bunnyList.push_back(toReturn);
    return toReturn->getName();
}

int LogicHandler::LogicLoop() {
    static list<shared_ptr<Bunny>> toKill = {};
    static list<shared_ptr<Bunny>> toInfect = {};
    static int infectedCount = 0;
    static bool agedMalePresent = false;
    list<Colour> childColours = {};

    //iterate through all bunnies, extract information and perform logic.
    for (auto const& i : _bunnyList) {
        //age check
        if (i->growOld()) { //age and add dead bunnies to kill list.
            toKill.push_front(i);
        }

        //gender check.
        if (i->getAge() >= 2) {
            if (!i->getIsInfected()) {
                if (i->getIsMale() && i->getAge() >= 2) {
                    agedMalePresent = true;
                }
                else if (i->getAge() >= 2) {
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
    std::sample( //randomly select n bunnies and infect them.
        _bunnyList.begin(),
        _bunnyList.end(),
        std::back_inserter(toInfect),
        infectedCount,
        std::mt19937{ std::random_device{}() });
    for (auto i : toInfect) {
        i->setIsInfected();
    }

    //Birth handling
    if (agedMalePresent) {
        for (auto i : childColours) {
            cout << addChild(i) << " was born!\n";
        }
    }


    //Kill handling
    if (_bunnyList.size() > 1000) { //Food shortage, randomly selects half and culls them.
        std::sample(
            _bunnyList.begin(),
            _bunnyList.end(),
            std::back_inserter(toKill),
            (_bunnyList.size() / 2),
            std::mt19937{ std::random_device{}() });
    }
    for (shared_ptr<Bunny> const i : toKill) {
        cout << i->getName() << " has died!\n";
        _bunnyList.remove(i);
    }

    //Clear static lists for next loop.
    toKill.clear();
    toInfect.clear();
    childColours.clear();

    //Console out.
    for (auto const& i : _bunnyList) {
        cout << i->getName() << ", " << i->getGenderString() << ", " << i->getColourString() << ", " << i->getAge() << ", " << i->getIsInfectedString() << ".\n";
    }

    //User input
    system("pause");
    cout << "\n";
    return 1;
}