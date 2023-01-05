#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H

#include <vector>
#include "sandwich.h"
#include "beef_sandwich.h"
#include "sweet_sandwich.h"

using namespace std;

template<typename T>
class sandwich_factory
{
public:
    static T* create_sandwich(int price, int id)
    {
        T *sandwich = new T(price, id);
        return T;
    }
    static vector<T*> create_sandwich_array(int price, int count, vector<int> id_list)
    {
        vector<T*> array;
        for (int i = 0; i < count; i++)
        {
            arrat.push_back(create_sandwich(price, id_list[i]));
        }
        return array;
    }
};

#endif
