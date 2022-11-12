#ifndef UT_DRINK
#define UT_DRINK

#include "../src/drink.h"

TEST(DRINKTEST, SOMETEST1)
{
    Drink drink("black tea", 0.6, 45);
    ASSERT_EQ(drink.getName(), "black tea");
    ASSERT_EQ(drink.getPrice(), 45);
    ASSERT_EQ(drink.getSweetnessLevel(), 0.6);
}
TEST(DRINKTEST, SOMETEST2)
{
    Drink drink1("green tea", 0.6, 45);
    Drink drink2 = drink1;
    drink2.addTopping(Topping("bublle", 0.25, 10));
    ASSERT_EQ(drink2.getName(), "green tea");
    ASSERT_EQ(drink2.getPrice(), 55);
    ASSERT_EQ(drink2.getSweetnessLevel(), 0.85);
}
TEST(DRINKTEST, SOMETEST3)
{
    Drink drink("milk tea", 0.5, 50);
    drink.addTopping(Topping("bubble", 0.25, 10));
    drink.addTopping(Topping("pudding", 0.15, 10));
    drink.addTopping(Topping("aiyu", 0.1, 10));
    ASSERT_EQ(drink.getToppingByIndex(0).getName(), "bubble");
    ASSERT_EQ(drink.getToppingByIndex(1).getName(), "pudding");
    ASSERT_EQ(drink.getToppingByIndex(2).getName(), "aiyu");
    ASSERT_EQ(drink.getToppingCount(), 3);
}
TEST(DRINKTEST, SOMETEST4)
{
    Drink drink;
    ASSERT_THROW(drink.getName(), std::string);
}

#endif