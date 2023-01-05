#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H

#include <set>
#include <stdexcept>
#include "sandwich.h"

using namespace std;

class BeefSandwich : public Sandwich
{
public:
    static set<int> _id_array;
    BeefSandwich(int price, int id) : Sandwich(price, id) 
    {
        _id_array.insert(id);
    }
    ~BeefSandwich()
    {
        _id_array.erase(_id);
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

set<int> BeefSandwich::_id_array;

#endif