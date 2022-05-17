#pragma once
#include <string>
#include "../include/Colour.hpp"
using std::string;

class Bunny {
    string _name;
    bool _isMale;
    Colour _colour;
    int _age;
    bool _isInfected;

    void genFullName();
public:
    explicit Bunny(bool isMale, Colour colour, int age);
    string getName();
    bool getIsMale(); //returns gender of bunny as a bool, true for male, false for female.
    string getGenderString();
    int getAge(); //returns age of bunny.
    Colour getColour(); //returns colour of bunny.
    string getColourString();
    bool getIsInfected();
    void setIsInfected();
    string getIsInfectedString();
    void growOld(); //increment age and return a bool as to whether the bunny is dead. true for dead, false for alive.
    bool checkAgeDeath();
};