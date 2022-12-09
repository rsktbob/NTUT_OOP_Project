#ifndef TEQUILA_H
#define TEQUILA_H

#include <string>
#include "alcohol.h"

using namespace std; 


class Tequila : public Alcohol
{
public:
    Tequila() : Alcohol() {}
    Tequila(string name, int price, double content) : Alcohol(name, price, content) {}
    ~Tequila() = default;
    Tequila &operator=(const Tequila &other)
    {
        if (this != &other)
        {
            _name = other._name;
            _price = other._price;
            _content = other._content;
        }
        return *this;
    }
    Tequila operator+(const Tequila &other)
    {
        return Tequila(_name, _price+other._price, (_content+other._content)/2);
    }
    bool operator==(const Tequila &other)
    {
        if (_name == other._name && _price == other._price &&  _content == other._content)
        {
            return true;   
        }
        return false;
    }
    void dilute() override
    {
        if (_content < 0.05 || _content > 1)
        {
            throw invalid_argument("error");
        }
        _content -= 0.05;
    }
};

#endif