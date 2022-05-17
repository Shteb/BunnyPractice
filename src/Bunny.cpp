#include "../include/Bunny.hpp"


Bunny::Bunny(bool isMaleIn, Colour colourIn, int ageIn) {
    genFullName();
    _isMale = isMaleIn;
    _colour = colourIn;
    _age = ageIn;
    if (rand() % 100 < 2) {
        _isInfected = true;
    }
    else {
        _isInfected = false;
    }
}

string Bunny::getName() {
    return _name;
}

void Bunny::genFullName() {
    _name = "";

    switch (rand() % 20)
    {
    case 0:
        _name += "James ";
        break;
    case 1:
        _name += "Barnes ";
        break;
    case 2:
        _name += "Johnathan ";
        break;
    case 3:
        _name += "Mary ";
        break;
    case 4:
        _name += "Susan ";
        break;
    case 5:
        _name += "Polly ";
        break;
    case 6:
        _name += "Samuel ";
        break;
    case 7:
        _name += "Matthew ";
        break;
    case 8:
        _name += "Luke ";
        break;
    case 9:
        _name += "Mark ";
        break;
    case 10:
        _name += "Natalie ";
        break;
    case 11:
        _name += "Bartholomew ";
        break;
    case 12:
        _name += "Saphronia ";
        break;
    case 13:
        _name += "Esmerelda ";
        break;
    case 14:
        _name += "Rodger ";
        break;
    case 15:
        _name += "Leonardo ";
        break;
    case 16:
        _name += "Raphael ";
        break;
    case 17:
        _name += "Donatello ";
        break;
    case 18:
        _name += "Michaelangelo ";
        break;
    case 19:
        _name += "Constantine ";
        break;
    default:
        break;
    }

    switch (rand() % 10)
    {
    case 0:
        _name += "R. ";
        break;
    case 1:
        _name += "A. ";
        break;
    case 2:
        _name += "J. ";
        break;
    case 3:
        _name += "P. ";
        break;
    case 4:
        _name += "W. ";
        break;
    case 5:
        _name += "A. ";
        break;
    case 6:
        _name += "E. ";
        break;
    case 7:
        _name += "K. ";
        break;
    case 8:
        _name += "O. ";
        break;
    case 9:
        _name += "V. ";
        break;
    default:
        break;
    }

    switch (rand() % 20)
    {
    case 0:
        _name += "Johnson";
        break;
    case 1:
        _name += "Bacherman";
        break;
    case 2:
        _name += "Smith";
        break;
    case 3:
        _name += "Kalleri";
        break;
    case 4:
        _name += "Colico";
        break;
    case 5:
        _name += "Rahld";
        break;
    case 6:
        _name += "Humphrey";
        break;
    case 7:
        _name += "Dalason";
        break;
    case 8:
        _name += "Bakerly";
        break;
    case 9:
        _name += "Feld";
        break;
    case 10:
        _name += "Beezul";
        break;
    case 11:
        _name += "Diesel";
        break;
    case 12:
        _name += "Fawnesworth";
        break;
    case 13:
        _name += "Woodruff";
        break;
    case 14:
        _name += "Fielding";
        break;
    case 15:
        _name += "Roservelt";
        break;
    case 16:
        _name += "Sprout";
        break;
    case 17:
        _name += "Bacon";
        break;
    case 18:
        _name += "Clemente";
        break;
    case 19:
        _name += "Wilhelm";
        break;
    default:
        break;
    }
}

bool Bunny::getIsMale() {
    return _isMale;
}

string Bunny::getGenderString() {
    if (_isMale) {
        return "male";
    }
    else {
        return "female";
    }
}

int Bunny::getAge() {
    return _age;
}

Colour Bunny::getColour() {
    return _colour;
}

string Bunny::getColourString() {
    switch (_colour)
    {
    case Colour::white:
        return "white";
        break;

    case Colour::black:
        return "black";
        break;

    case Colour::brown:
        return "brown";
        break;

    case Colour::spotted:
        return "spotted";
        break;

    default:
        return "no colour assigned";
        break;
    }
}

bool Bunny::getIsInfected() {
    return _isInfected;
}

void Bunny::setIsInfected() {
    _isInfected = true;
}

string Bunny::getIsInfectedString() {
    if (_isInfected) {
        return "infected";
    }
    else {
        return "healthy";
    }
}

void Bunny::growOld() {
    _age++;
}

bool Bunny::checkAgeDeath() {
    if (_age >= 10 && !_isInfected) {
        return true;
    }
    else if (_age >= 50 && _isInfected) {
        return true;
    }
    else if (_age < 10) {
        return false;
    }
    return false;
}