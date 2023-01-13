#include <stdexcept>
#include <vector>

#include "bike_gc.h"
#include "../src/mybike.h"
#include "../src/bike_rms.h"
#include "../src/electric_bike.h"
#include "../src/bike_factory.h"

class SampleTestWithFixture : public ::testing::Test {
    virtual void SetUp(){
        BikeRMS::reset_total_rental_income();
    }
};

TEST_F(SampleTestWithFixture, construct_mybike){
    MyBike mybike(5, 10);

    ASSERT_EQ(mybike.get_id(), 5);
    ASSERT_EQ(mybike.get_rental_price(), 10);
}

TEST_F(SampleTestWithFixture, mybike_to_string_should_return_correct_format){
    MyBike mybike(5, 10);

    ASSERT_EQ(mybike.to_string(), "5-MyBike price=10");
}

TEST_F(SampleTestWithFixture, construct_mybike_with_negative_price_should_throw_invalid_argument){
    ASSERT_THROW(MyBike(5, -10), std::invalid_argument);
}


TEST_F(SampleTestWithFixture, construct_electric_bike_with_no_power){
    ElectricBike electric_bike(5, 10);

    ASSERT_EQ(electric_bike.get_id(), 5);
    ASSERT_EQ(electric_bike.get_rental_price(), 10);
    ASSERT_EQ(electric_bike.get_power(), 0); // The default power is zero.
}

TEST_F(SampleTestWithFixture, construct_electric_bike_with_specific_power){
    ElectricBike electric_bike(5, 10, 0.6);

    ASSERT_EQ(electric_bike.get_id(), 5);
    ASSERT_EQ(electric_bike.get_rental_price(), 10);
    ASSERT_EQ(electric_bike.get_power(), 0.6);
}

TEST_F(SampleTestWithFixture, set_electric_bike_with_specific_power){
    ElectricBike electric_bike(5, 10, 0.6);

    electric_bike.set_power(0.4);

    ASSERT_EQ(electric_bike.get_id(), 5);
    ASSERT_EQ(electric_bike.get_rental_price(), 10);
    ASSERT_EQ(electric_bike.get_power(), 0.4);
}

TEST_F(SampleTestWithFixture, electric_bike_to_string_should_return_correct_format){
    ElectricBike electric_bike(5, 10, 0.6);

    ASSERT_EQ(electric_bike.to_string(), "5-ElectricBike price=10 power=0.60");
}

TEST_F(SampleTestWithFixture, construct_electric_bike_with_negative_price_should_throw_invalid_argument){
    ASSERT_THROW(ElectricBike(5, -10), std::invalid_argument);
}

TEST_F(SampleTestWithFixture, set_electric_bike_with_out_of_range_power_should_throw_invalid_arguments){
    ASSERT_THROW(ElectricBike(5, 10, 0.6).set_power(1.6), std::invalid_argument);
    ASSERT_THROW(ElectricBike(5, 10, 0.6).set_power(-0.6), std::invalid_argument);
    ASSERT_THROW(ElectricBike(5, 10, 1.6), std::invalid_argument);
    ASSERT_THROW(ElectricBike(5, 10, -0.6), std::invalid_argument);
}

TEST_F(SampleTestWithFixture, construct_bike_rms){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});
    ASSERT_EQ(rms.get_count_of_available_bike(), 2);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, rent_the_bike_from_rms){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});
    Bike* rent_bike = rms.rent_bike(2);

    ASSERT_EQ(rms.get_count_of_available_bike(), 1);
    ASSERT_EQ(rent_bike->get_id(), 2);
    ASSERT_EQ(rent_bike->get_rental_price(), 30);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, return_the_bike_from_rms){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});
    Bike* rent_bike = rms.rent_bike(2);

    rms.return_bike(rent_bike);

    ASSERT_EQ(rms.get_count_of_available_bike(), 2);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, append_the_new_bike_to_rms){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    Bike* bike3 = new ElectricBike(3, 30);
    BikeRMS rms({bike1, bike2});

    rms.append_bike(bike3);

    ASSERT_EQ(rms.get_count_of_available_bike(), 3);
    BikeGC::bike_gc({bike1, bike2, bike3});
}

TEST_F(SampleTestWithFixture, return_the_total_income_from_all_rms){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 20);
    Bike* bike3 = new ElectricBike(3, 30);
    Bike* bike4 = new MyBike(4, 20);
    BikeRMS rms1({bike1, bike2});
    BikeRMS rms2({bike3, bike4});

    rms1.rent_bike(1);
    rms2.rent_bike(4);

    ASSERT_EQ(BikeRMS::get_total_rental_income(), 50);
    BikeGC::bike_gc({bike1, bike2, bike3, bike4});
}

TEST_F(SampleTestWithFixture, rent_the_non_exists_bike_should_throw_invalid_argument){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});

    ASSERT_THROW(rms.rent_bike(3), std::invalid_argument);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, rent_unavailable_bike_should_throw_invalid_argument){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});
    rms.rent_bike(2);

    ASSERT_THROW(rms.rent_bike(2), std::invalid_argument);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, return_the_bike_which_already_exists_should_throw_invalid_argument){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});

    ASSERT_THROW(rms.return_bike(bike2), std::invalid_argument);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, return_the_bike_which_not_belong_of_rms_should_throw_invalid_argument){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    Bike* bike3 = new ElectricBike(3, 30);
    BikeRMS rms({bike1, bike2});

    ASSERT_THROW(rms.return_bike(bike3), std::invalid_argument);
    BikeGC::bike_gc({bike1, bike2, bike3});
}

TEST_F(SampleTestWithFixture, append_the_exists_bike_should_throw_invalid_argument){
    Bike* bike1 = new ElectricBike(1, 30);
    Bike* bike2 = new MyBike(2, 30);
    BikeRMS rms({bike1, bike2});    

    ASSERT_THROW(rms.append_bike(bike2), std::invalid_argument);
    BikeGC::bike_gc({bike1, bike2});
}

TEST_F(SampleTestWithFixture, create_electric_bike_with_factory){
    ElectricBike* bike = BikeFactory<ElectricBike>::create_bike(15, 30);
    
    ASSERT_EQ(bike->get_id(), 15);
    ASSERT_EQ(bike->get_rental_price(), 30);
    ASSERT_EQ(bike->get_power(), 0);
    BikeGC::electric_bike_gc({bike});
}

TEST_F(SampleTestWithFixture, create_electric_bike_array_with_factory){
    std::vector<int> ids = {1, 2, 3};
    std::vector<int> prices = {5, 10, 15};
    std::vector<ElectricBike*> bikes = BikeFactory<ElectricBike>::create_bike_array({1, 2, 3}, {5, 10, 15});
    
    for(int i = 0; i < ids.size(); i++){
        ASSERT_EQ(bikes[i]->get_id(), ids[i]);
        ASSERT_EQ(bikes[i]->get_rental_price(), prices[i]);
    }
    BikeGC::electric_bike_gc(bikes);
}
