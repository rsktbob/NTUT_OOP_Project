#ifndef SANDWICH_H
#define SANDWICH_H 

#include <set>

using namespace std;

class Sandwich
{
protected:
    int _price;
    int _id;
public:
    static set<int> _id_array;
    Sandwich(int price, int id) : _price(price), _id(id)
    {
        _id_array.insert(id);
    }
    int get_price()
    {
        return _price;
    }
    int get_id()
    {
        return _id;
    }
    static bool record_has_specific_id(int id)
    {
        if (_id_array.find(id) != _id_array.end())
        {
            return true;
        }
        return false;
    }
    static int get_size_of_record_container()
    {
        return _id_array.size();
    }
};

set<int> Sandwich::_id_array;

#endif