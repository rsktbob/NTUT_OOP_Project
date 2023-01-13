#ifndef MY_H
#define MY_H

#include <stdexcept>
#include "bike.h"

using namespace std;

class MyBike : public Bike
{
public:
    MyBike(int ID, int rent_price) : Bike(ID, rent_price) {}
    ~MyBike() = default;
    string to_string() override
    {
        char str[80] = {};
        sprintf(str, "%d-MyBike price=%d", _id, _rent_price);
        return str;
    }
};

#endif