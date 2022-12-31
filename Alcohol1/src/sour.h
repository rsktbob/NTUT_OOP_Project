#ifndef SOUR_H
#define SOUR_H

#include "alcohol.h"

class Sour : public Alcohol
{
public:
    Sour() : Alcohol() {}
    Sour(string name, int price, double content) : Alcohol(name, price, content) {}
    Sour operator+(const Sour &other) 
    {
        return Sour(_name, _price+other._price, (_content+other._content) / 2);
    }
    bool operator==(const Sour &other)
    {
        if (_name == other._name && _price == other._price && _content == other._content)
        {
            return true;
        }
        return false;
    }
    Sour &operator=(const Sour &other) 
    {
        _name = other._name;
        _price = other._price;
        _content = other._content;
        return *this;
    }
    void dilute() override
    {
        if (_name == "" || _price < 0 || _content < 0.3 || _content > 1)
        {
            throw std::invalid_argument("error");
        }
        _content -= 0.3;
    }
};

#endif