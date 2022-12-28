#include "../src/alcohol.h"
#include "../src/tequila.h"

TEST(ALCOHOL1, SOMETEST)
{
    Alcohol *alcohol;
    Tequila tequila("name1", 60, 0.8);
    alcohol = &tequila;
    alcohol->dilute();
    ASSERT_EQ(alcohol->get_name(), "name1");
    ASSERT_EQ(alcohol->get_price(), 60);
    ASSERT_NEAR(alcohol->get_alcohol_content(), 0.75, 0.01);
}

TEST(ALCOHOL2, SOMETEST)
{
    Alcohol *alcohol;
    Tequila tequila("name1", 60, 0.03);
    alcohol = &tequila;
    ASSERT_THROW(alcohol->dilute(), std::invalid_argument);
    ASSERT_THROW(Tequila("", -1, 0.3), std::invalid_argument);
}

TEST(ALCOHOL3, SOMETEST)
{
    Alcohol *alcohol;
    Tequila tequila;
    alcohol = &tequila;
    ASSERT_THROW(alcohol->get_name(), std::invalid_argument);
    ASSERT_THROW(alcohol->get_price(), std::invalid_argument);
    ASSERT_THROW(alcohol->get_alcohol_content(), std::invalid_argument);
}
