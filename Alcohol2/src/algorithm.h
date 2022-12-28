#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <algorithm>
#include "alcohol.h"
#include "sour.h"
#include "tequila.h"

using namespace std;

void sort_alcohol_by_content(vector<Alcohol*> &alcohol)
{
    sort(alcohol.begin(), alcohol.end(), [] (Alcohol *a, Alcohol *b) {
        if (a->get_alcohol_content() < b->get_alcohol_content())
        {
            return true;
        }
        else if (a->get_alcohol_content() == b->get_alcohol_content() && a->get_name() < b->get_name())
        {
            return true;
        }
        return false;
    });
}

void sort_alcohol_by_name(vector<Alcohol*> &alcohol)
{
    sort(alcohol.begin(), alcohol.end(), [] (Alcohol *a, Alcohol *b) {return a->get_name() < b->get_name();});   
}

Alcohol* get_greatest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort(alcohol.begin(), alcohol.end(), [] (Alcohol *a, Alcohol *b) {
        if (a->get_alcohol_content() > b->get_alcohol_content())
        {
            return true;
        }
        else if (a->get_alcohol_content() == b->get_alcohol_content() && a->get_name() > b->get_name())
        {
            return true;
        }
        return false;
    });
    return alcohol[0];    
}

Alcohol* get_smallest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort(alcohol.begin(), alcohol.end(), [] (Alcohol *a, Alcohol *b) {
        if (a->get_alcohol_content() < b->get_alcohol_content())
        {
            return true;
        }
        else if (a->get_alcohol_content() == b->get_alcohol_content() && a->get_name() < b->get_name())
        {
            return true;
        }
        return false;
    });
    return alcohol[0];
}

#endif