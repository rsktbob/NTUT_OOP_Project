#include <bits/stdc++.h>
#include "../src/drink.h"

/* Place some test here */
/* TEST(GroupName, TestName){} */
TEST(DRINK1, CONSTRUCTTEST)
{
    Drink drink("Signature Black Tea with Milk", 0.3);
    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.3, 0.01);
}

TEST(DRINK2, CONSTRUCTORTEST)
{
    Drink drink("Milk Tea", 0.6);
    ASSERT_EQ(drink.getName(), "Milk Tea");
    ASSERT_EQ(drink.getSweetnessLevel(), 0.6);
}

TEST(DRINK3, NAMETEST)
{
    Drink drink("Black tea", 0.5);
    ASSERT_EQ(drink.getName(), "Black tea");
}

TEST(DRINK4, NAMETEST)
{
    Drink drink("Green tea", 0.5);
    ASSERT_EQ(drink.getName(), "Green tea");
}

TEST(DRINK5, SWEETNESSLEVELTEST)
{
    Drink drink("Cola", 0.8);
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.8, 0.01);
}

TEST(DRINK6, SWEETNESSLEVELTEST)
{
    Drink drink("Oolong tea", 0.6);
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.6, 0.01);
}

TEST(DRINK7, ADDTOPPINGTEST)
{
    Drink drink("Green tea", 0.5);
    drink.addTopping("Bubble");
    drink.addTopping("Pudding");
    ASSERT_EQ(drink.getToppingByIndex(0), "Bubble");
    ASSERT_EQ(drink.getToppingByIndex(1), "Pudding");
}

TEST(DRINK8, ADDTOPPINGTEST)
{
    Drink drink("Black tea", 0.5);
    drink.addTopping("Konjac");
    drink.addTopping("Aiyu");
    drink.addTopping("vermicelli");
    ASSERT_EQ(drink.getToppingByIndex(0), "Konjac");
    ASSERT_EQ(drink.getToppingByIndex(1), "Aiyu");
    ASSERT_EQ(drink.getToppingByIndex(2), "vermicelli");
}

TEST(DRINK9, ADDTOPPINGTEST)
{
    Drink drink("Green tea", 0.5);
    drink.addTopping("Bubble");
    drink.addTopping("Konjac");
    ASSERT_EQ(drink.getToppingByIndex(0), "Bubble");
    ASSERT_EQ(drink.getToppingByIndex(1), "Konjac");
}

TEST(DRINK10, ADDTOPPINGTEST)
{
    Drink drink("Black tea", 0.5);
    drink.addTopping("Bubble");
    drink.addTopping("vermicelli");
    ASSERT_EQ(drink.getToppingByIndex(0), "Bubble");
    ASSERT_EQ(drink.getToppingByIndex(1), "vermicelli");
}

TEST(DRINK11, TOPPINGCOUNTTEST)
{
    Drink drink("Green tea", 0.5);
    drink.addTopping("Bubble");
    drink.addTopping("Konjac");
    drink.addTopping("Aiyu");
    ASSERT_EQ(drink.getToppingCount(), 3);
}

TEST(DRINK12, TOPPINGCOUNTTEST)
{
    Drink drink("Green tea", 0.5);
    drink.addTopping("vermicelli");
    drink.addTopping("Bubble");
    drink.addTopping("Konjac");
    drink.addTopping("Aiyu");
    ASSERT_EQ(drink.getToppingCount(), 4);
}




