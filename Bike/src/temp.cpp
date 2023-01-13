#include <iostream>
#include "bike.h"
#include "mybike.h"
#include "bike_rms.h"
#include "electric_bike.h"
#include "mybike.h"
#include "electric_bike.h"

using namespace std;

int main()
{
    Bike *bike1 = new ElectricBike(1, 30);
    Bike *bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});

    Bike *rent_bike = rms.rent_bike(2);

    BikeRMS::reset_total_rental_income();
    cout << rms.get_count_of_available_bike() << endl;
    cout << rent_bike->get_id() << endl;
    cout << rent_bike->get_rental_price() << endl;
}