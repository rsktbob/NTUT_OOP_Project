#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "alcohol.h"

using namespace std;

class Order
{
private:
    vector<Alcohol *> _alcohol;
public:
    Order() = default;
    ~Order()
    {
        _alcohol.clear();
    }
    void append_alcohol(Alcohol* alcohol)
    { 
        _alcohol.push_back(alcohol);
    }
    int get_alcohol_count()
    {
        return _alcohol.size();
    }
    int get_total_price()
    {
        int result = 0;
        for (int i = 0; i < _alcohol.size(); i++)
        {
            result += _alcohol[i]->get_price();
        }
        return result;
    }
};

#endif
