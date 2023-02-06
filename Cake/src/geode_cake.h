#ifndef GEODECAKE_H
#define GEODECAKE_H

#include "cake.h"

class GeodeCake : public Cake
{
public:
    static int _count;
    GeodeCake() : Cake() {_count += 1; }
    GeodeCake(int price, int sweet) : Cake(price, sweet) {_count += 1; }
    ~GeodeCake() override 
    {
        _count -= 1;
    }
    std::string to_string()
    {
        char x1[80] = {};
        sprintf(x1, "| GeodeCake            |         %d |         %d |", _price, _sweet);
        return x1;
    }
    static int get_count()
    {
        return _count;
    }
};

int GeodeCake::_count = 0;

#endif
