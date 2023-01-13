#ifndef BIKEGC_H
#define BIKEGC_H

#include <vector>
#include "../src/bike.h"
#include "../src/mybike.h"
#include "../src/electric_bike.h"

class BikeGC {
public:
    static void bike_gc(std::vector<Bike*> vec){
        for(Bike* bike : vec){
            delete bike;
        }
    }
    static void mybike_gc(std::vector<MyBike*> vec){
        for(MyBike* bike : vec){
            delete bike;
        }
    }
    static void electric_bike_gc(std::vector<ElectricBike*> vec){
        for(ElectricBike* bike : vec){
            delete bike;
        }
    }
};

#endif
