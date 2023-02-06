#ifndef CAKE_H
#define CAKE_H

#include <string>

class Cake
{
protected:
    int _price;
    int _sweet;
public:
    static int _total;
    Cake() { _total += 1; };
    Cake(int price, int sweet) : _price(price), _sweet(sweet) { _total += 1; }
    virtual ~Cake() { _total -= 1; };
    int get_price()
    {
        return _price;
    }
    int get_sweet()
    {
        return _sweet;
    }
    static int get_total()
    {
        return _total;
    }
    virtual std::string to_string() = 0;
};

int Cake::_total = 0;

#endif