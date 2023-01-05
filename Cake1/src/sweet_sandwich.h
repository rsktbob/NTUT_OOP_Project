#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H

#include <set>
#include "sandwich.h"

using namespace std;

class SweetSandwich : public Sandwich
{
public:
    static set<int> _id_array;
    SweetSandwich(int price, int id) : Sandwich(price, id) 
    {
        _id_array.insert(id);
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

set<int> SweetSandwich::_id_array;

#endif