#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <stdexcept>
#include <string>

using namespace std;

class Alcohol
{
protected:
    string _name;
    int _price;
    double _content;
public:
    Alcohol()
    {
        _name = "";
        _price = -1;
        _content = -1;
    }
    Alcohol(string name, int price, double content)
    {
        if (name.length() == 0 || price < 0 || content < 0 || content > 1)
        {
            throw invalid_argument("error");
        }
        _name = name;
        _price = price;
        _content = content;
    }
    virtual ~Alcohol() = default;
    double get_alcohol_content()
    {
        if (_content < 0 || _content > 1)
        {
            throw invalid_argument("error");
        }
        return _content;
    }
    int get_price()
    {
        if (_price < 0)
        {
            throw invalid_argument("error");    
        }
        return _price;
    }
    string get_name()
    {
        if (_name == "")
        {
            throw invalid_argument("error");
        }
        return _name;
    }
    virtual void dilute() = 0;
};

#endif
