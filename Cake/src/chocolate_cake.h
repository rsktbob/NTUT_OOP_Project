#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <string>
#include "cake.h"

class ChocolateCake : public Cake
{
public:
    static int _count;
    ChocolateCake() : Cake() {_count += 1; }
    ChocolateCake(int price, int sweet) : Cake(price, sweet) {_count += 1; }
    ~ChocolateCake() override
    {
        _count -= 1;
    }
    std::string to_string() override
    {
        char str[80] = {};
        sprintf(str, "| ChocolateCake        |         %d |         %d |", _price, _sweet);
        return str;
    }
    static int get_count()
    {
        return _count;
    }
};

int ChocolateCake::_count = 0;

#endif