#ifndef ELECTRIC_H
#define ELECTRIC_H

#include <stdexcept>
#include "bike.h"

using namespace std;

class ElectricBike : public Bike
{
private:
    double _power;
public:
    ElectricBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price)
    {
        if (power < 0 || power > 1)
        {
            throw invalid_argument("error");
        }
        _power = power;
    }
    ~ElectricBike() = default;
    double get_power()
    {
        return _power;
    }
    void set_power(double power)
    {
        if (power < 0 || power > 1)
        {
            throw invalid_argument("error");
        }
        _power = power;
    }
    string to_string() override
    {
        char str[2000] = {};
        sprintf(str, "%d-ElectricBike price=%d power=%.2lf", _id, _rent_price, _power);
        return str;
    }
};

#endif