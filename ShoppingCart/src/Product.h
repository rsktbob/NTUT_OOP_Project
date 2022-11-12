#ifndef PRODUCT
#define PRODUCT

#include <string>

using namespace std;

class Product
{
private:
    string _name;
    int _price;

public:
    Product()
    {
        _name = "";
        _price = 0;
    }
    Product(string name, int price)
    {
        if (name.length() < 4)
        {
            throw string("error name");
        }
        if (price < 0)
        {
            throw string("error price");
        }
        _name = name;
        _price = price;
    }
    bool operator==(const Product &other)
    {
        if (this->_name == other._name)
        {
            return true;
        }
        else
        {
            return false; 
        }
    }
    string getName()
    {
        return _name;
    }
    int getPrice()
    {
        return _price;
    }
};

#endif