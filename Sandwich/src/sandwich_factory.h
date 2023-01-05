#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "sandwich.h"
#include "beef_sandwich.h"
#include "sweet_sandwich.h"

using namespace std;

template<typename T>
class SandwichFactory
{
public:
    static T* create_sandwich(int price, int id)
    {
        T *sandwich = new T(price, id);
        return sandwich;
    }
    static vector<T*> create_sandwich_array(int price, int count, vector<int> id_list)
    {
        if (count < 0)
        {
            throw invalid_argument("error");
        }
        vector<T*> array;
        for (int i = 0; i < count; i++)
        {
            array.push_back(create_sandwich(price, id_list[i]));
        }
        return array;
    }
};

#endif
