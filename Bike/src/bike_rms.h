#ifndef BIKE_RMS_H
#define BIKE_RMS_H

#include <vector>
#include <stdexcept>
#include "bike.h"
#include "electric_bike.h"
#include "mybike.h"
#include "electric_bike.h"

using namespace std;

class BikeRMS
{
public:
    static vector<Bike*> _bikes;
    static vector<Bike*> _rent_bikes;
    static int _income;
    BikeRMS(vector<Bike*> bikes)
    {
        for (int i = 0; i < bikes.size(); i++)
        {
            _bikes.push_back(bikes[i]);
        }
    }
    int get_count_of_available_bike()
    {
        return _bikes.size() - _rent_bikes.size();
    }
    Bike *rent_bike(int ID)
    {
        if (ID < 0)
        {
            throw invalid_argument("error");
        }
        for (int i = 0; i < _rent_bikes.size(); i++)
        {
            if (ID == _rent_bikes[i]->get_id())
            {
                throw invalid_argument("error");
            }
        }
        for (int i = 0; i < _bikes.size(); i++)
        {
            if (ID == _bikes[i]->get_id())
            {
                _rent_bikes.push_back(_bikes[i]);
                _income += _bikes[i]->get_rental_price();
                return _bikes[i]; 
            }
        }
        throw invalid_argument("error");
    }
    void return_bike(Bike *bike)
    {
        int check1 = 0;
        for (int i = 0; i < _bikes.size(); i++)
        {
            if (bike->get_id() == _bikes[i]->get_id() && bike->get_rental_price() == _bikes[i]->get_rental_price())
            {
                check1 = 1;
                break;
            }
        }
        if (check1 == 0)
        {
            throw invalid_argument("error");
            return;
        }
        for (int i = 0; i < _rent_bikes.size(); i++)
        {
            if (bike->get_id() == _rent_bikes[i]->get_id() && bike->get_rental_price() == _rent_bikes[i]->get_rental_price())
            {
                _rent_bikes.erase(_rent_bikes.begin() + i);
                return;
            }
        }
        throw invalid_argument("error");
    }
    void append_bike(Bike *bike)
    {
        for (int i = 0; i < _bikes.size(); i++)
        {
            if (bike->get_id() == _bikes[i]->get_id())
            {
                throw invalid_argument("error");
                return;
            }
        }
        _bikes.push_back(bike);
    }
    static int get_total_rental_income()
    {
        return _income;
    }
    static void reset_total_rental_income()
    {
        _income = 0;
        _bikes.erase(_bikes.begin(), _bikes.end());
        _rent_bikes.erase(_rent_bikes.begin(), _rent_bikes.end());
    }
};

vector<Bike*> BikeRMS::_bikes;
vector<Bike*> BikeRMS::_rent_bikes;
int BikeRMS::_income = 0;

#endif