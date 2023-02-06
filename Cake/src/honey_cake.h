#ifndef HONEYCAKE_H
#define HONEYCAKE_H

#include <string>
#include "cake.h"

class HoneyCake : public Cake
{
public:
    static int _count;
    HoneyCake() : Cake() { _count += 1; }
    HoneyCake(int price, int sweet) : Cake(price, sweet) { _count += 1; }
    ~HoneyCake() override 
    {
        _count -= 1;
    }
    std::string to_string()
    {
        char x1[80] = {};
        sprintf(x1, "| HoneyCake            |         %d |         %d |", _price, _sweet);
        return x1;
    }
    static int get_count()
    {
        return _count;
    }
};

int HoneyCake::_count = 0;

#endif