#ifndef BIKE_H
#define BIKE_H

#include <stdexcept>

class Bike
{
protected:
    int _id;
    int _rent_price;
public:
    Bike(int ID, int rent_price)
    {
        if (rent_price < 0)
        {
            throw std::invalid_argument("error");
        }
        _id = ID;
        _rent_price = rent_price;
    }
    virtual ~Bike() = default;
    int get_id()
    {
        return _id;
    }
    int get_rental_price()
    {
        return _rent_price;
    }
    virtual std::string to_string() = 0;
};

#endif