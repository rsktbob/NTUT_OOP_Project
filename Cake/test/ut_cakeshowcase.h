#include "../src/cake.h"
#include "../src/cake_showcase.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
#include "../src/chocolate_cake.h"

TEST(CAKE1, SOMETEST)
{
    ChocolateCake cake1(65, 50);
    ChocolateCake cake2(50, 45);
    ChocolateCake cookie1(80, 45);
    ChocolateCake cookie2;
    ASSERT_EQ(cake1.get_price(), 65);
    ASSERT_EQ(cake2.get_sweet(), 45);
    ASSERT_EQ(cookie1.to_string(), "| ChocolateCake        |         80 |         45 |");
    ASSERT_EQ(ChocolateCake::get_count(), 4);
    ASSERT_EQ(Cake::get_total(), 4);
}

TEST(CAKE2, SOMETEST)
{
    GeodeCake cake1(65, 50);
    GeodeCake cake2(50, 45);
    GeodeCake cookie1(80, 45);
    GeodeCake cookie2;
    ASSERT_EQ(cake1.get_price(), 65);
    ASSERT_EQ(cake2.get_sweet(), 45);
    ASSERT_EQ(cookie1.to_string(), "| GeodeCake            |         80 |         45 |");
    ASSERT_EQ(GeodeCake::get_count(), 4);
}

TEST(CAKE3, SOMETEST)
{
    HoneyCake cake1(65, 50);
    HoneyCake cake2(50, 45);
    HoneyCake cookie1(80, 45);
    HoneyCake cookie2;
    HoneyCake *cake_array[3];
    cake_array[0] = &cake1;
    cake_array[1] = &cake2;
    cake_array[2] = &cookie1;
    CakeShowcase<HoneyCake> cakeshowcase(3, cake_array);
    ASSERT_EQ(cakeshowcase[0]->get_price(), 65);
    ASSERT_EQ(cakeshowcase.to_string(),"| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n| HoneyCake            |         65 |         50 |\n| HoneyCake            |         50 |         45 |\n| HoneyCake            |         80 |         45 |\n| -------------------- | ---------- | ---------- |");
    ASSERT_EQ(cakeshowcase.calc_total_price(), 195);
    ASSERT_EQ(cakeshowcase.calc_total_sweet(), 140);
    ASSERT_EQ(cookie1.to_string(), "| HoneyCake            |         80 |         45 |");
    ASSERT_EQ(HoneyCake::get_count(), 4);
}