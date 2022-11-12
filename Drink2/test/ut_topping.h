#ifndef UT_TOPPING
#define UT_TOPPING

#include <cmath>
#include "../src/topping.h"

TEST(ToppingTest, TestWithCopyConstructor){
    Topping topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithCopyAssignment){
    Topping topping;
    topping = Topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithWrongValue){
    ASSERT_THROW(Topping("Bub", 0.4, 5), std::string);
    ASSERT_THROW(Topping("Bubble", -0.1, 5), std::string);
    ASSERT_THROW(Topping("Bubble", 0.4, -5), std::string);
}

#endif