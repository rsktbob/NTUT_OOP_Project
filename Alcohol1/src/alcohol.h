#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>
#include <stdexcept>

using namespace std;

class Alcohol
{
protected:
    string _name;
    int _price;
    double _content;
public:
    Alcohol() : _name(""), _price(-1), _content(-1) {}
    Alcohol(string name, int price, double content) : _name(name), _price(price), _content(content) {
        if (_price < 0 || _content < 0 || _content > 1 )
        {
            throw std::invalid_argument("error");
        }
    }
    double get_alcohol_content()
    {
        if (_name == "" || _price < 0 || _content < 0 || _content > 1 )
        {
            throw std::invalid_argument("error");
        }
        return _content;
    } 
    int get_price()
    {
        if (_name == "" || _price < 0 || _content < 0 || _content > 1 )
        {
            throw std::invalid_argument("error");
        }
        return _price;
    }
    string get_name()
    {
        if (_name == "" || _price < 0 || _content < 0 || _content > 1 )
        {
            throw std::invalid_argument("error");
        }
        return _name;
    }
    virtual void dilute() = 0;
};

#endif