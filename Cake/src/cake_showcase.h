#ifndef CAKEDHOWCASE_H
#define CAKEDHOWCASE_H

#include <vector>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <stdio.h>

using namespace std;

template<typename T>
class CakeShowcase
{
private:
    int length;
    vector<T*> _array;
public:
    CakeShowcase(int length, T** array) 
    {
        for (int i = 0; i < length; i++)
        {
            _array.push_back(array[i]);
        }
    }
    ~CakeShowcase()
    {
        _array.clear();
    }
    int calc_total_price()
    {
        int sum = 0;
        for (int i = 0; i < _array.size(); i++)
        {
            sum += _array[i]->get_price();
        }
        return sum;
    }
    int calc_total_sweet()
    {
        int sum = 0;
        for (int i = 0; i < _array.size(); i++)
        {
            sum += _array[i]->get_sweet();
        }
        return sum;
    }
    string to_string()
    {
        char str[2000];
        int position = sprintf(str, "| CakeName             | Price      | Sweet      |\n");
        position += sprintf(&str[position], "| -------------------- | ---------- | ---------- |\n");
        for (int i = 0; i < _array.size(); i++)
        {
            position += sprintf(&str[position], "%s\n", _array[i]->to_string().c_str());
        }
        sprintf(&str[position], "| -------------------- | ---------- | ---------- |");
        return str;
    }
    T* operator[](int index)
    {
        if (index >= _array.size() || index < 0)
        {
            throw std::out_of_range("error");
        }
        return _array[index];
    }
};

#endif
