#ifndef TEQULIA_H
#define TEQULIA_H

#include "alcohol.h"

class Tequila : public Alcohol
{
public:
    Tequila() : Alcohol() {}
    Tequila(string name, int price, double content) : Alcohol(name, price, content) {}
    Tequila operator+(const Tequila &other) 
    {
        return Tequila(_name, _price+other._price, (_content+other._content) / 2);
    }
    bool operator==(const Tequila &other)
    {
        if (_name == other._name && _price == other._price && _content == other._content)
        {
            return true;
        }
        return false;
    }
    Tequila &operator=(const Tequila &other) 
    {
        _name = other._name;
        _price = other._price;
        _content = other._content;
        return *this;
    }
    void dilute() override
    {
        if (_name == "" || _price < 0 || _content < 0.05 || _content > 1 )
        {
            throw std::invalid_argument("error");
        }
        _content -= 0.05;
    }
};

#endif