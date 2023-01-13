#ifndef BIKE_FACTORY_H
#define BIKE_FACTORY_H

#include "bike.h"
#include "bike_rms.h"
#include "mybike.h"
#include "electric_bike.h"

using namespace std;

template<typename T>
class BikeFactory
{
public:
    static T* create_bike(int ID, int rent_price)
    {
        T *result = new T(ID, rent_price);
        return result;
    }
    static vector<T*> create_bike_array(vector<int> IDs, vector<int> rent_prices)
    {
        vector<T*> array;
        for (int i = 0; i < IDs.size(); i++)
        {
            array.push_back(new T(IDs[i], rent_prices[i]));
        }
        return array;
    }
};

#endif