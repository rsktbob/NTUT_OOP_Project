#include <gtest/gtest.h>
#include <vector>
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"

class Sandwichtest : public :: testing::Test
{
protected:
    BeefSandwich *sandwich1;
    SweetSandwich *sandwich2;
    BeefSandwich *beefsandwich1;
    Sandwich *sandwich3;
    vector<BeefSandwich*> array;
    void SetUp() override
    {
        sandwich1 = new BeefSandwich(80, 1);
        sandwich2 = new SweetSandwich(65, 2);
        beefsandwich1 = SandwichFactory<BeefSandwich>::create_sandwich(80, 3);
        array = SandwichFactory<BeefSandwich>::create_sandwich_array(80, 3, {3, 4, 5});
    }
    void TearDown() override
    {
        delete sandwich1;
        delete sandwich2;
        delete beefsandwich1;
        for (int i = 0; i < array.size(); i++)
        {
            delete array[i];
        }
    }
};

TEST_F(Sandwichtest, SOMETEST1)
{
    ASSERT_EQ(BeefSandwich::record_has_specific_id(1), true);
    ASSERT_EQ(BeefSandwich::record_has_specific_id(0), false);
    ASSERT_EQ(SweetSandwich::record_has_specific_id(2), true);
    ASSERT_EQ(Sandwich::record_has_specific_id(1), true);
}

TEST_F(Sandwichtest, SOMETEST2)
{
    sandwich3 = beefsandwich1;
    ASSERT_EQ(sandwich3->get_price(), 80);
    ASSERT_EQ(Sandwich::record_has_specific_id(3), true);
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 4);
}

TEST_F(Sandwichtest, SOMETEST3)
{
    ASSERT_EQ(sandwich1->get_id(), 1);
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 1);
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 5);
}