#include "../src/tequila.h"

TEST(TEQUILA1, SOMETEST)
{
    Tequila tequila("name1", 60, 0.3);
    ASSERT_EQ(tequila.get_name(), "name1");
    ASSERT_EQ(tequila.get_price(), 60);
    ASSERT_NEAR(tequila.get_alcohol_content(), 0.3, 0.01);
}

TEST(TEQUILA2, SOMETEST)
{
    Tequila tequila1("name1", 60, 0.3);
    Tequila tequila2("name2", 240, 0.6);
    Tequila tequila3;
    tequila1 = tequila1;
    tequila1 = tequila1+tequila2;
    ASSERT_EQ(tequila1.get_name(), "name1");
    ASSERT_EQ(tequila1.get_price(), 300);
    ASSERT_NEAR(tequila1.get_alcohol_content(), 0.45, 0.01);
    ASSERT_THROW(tequila3.get_name(), std::invalid_argument);
    ASSERT_THROW(tequila3.get_price(), std::invalid_argument);
    ASSERT_THROW(tequila3.get_alcohol_content(), std::invalid_argument);
}

TEST(TEQUILA3, SOMETEST)
{
    Tequila tequila1("name1", 60, 0.3);
    Tequila tequila2("name2", 120, 0.6);
    tequila2.dilute();
    ASSERT_EQ(tequila1 == tequila1, true);
    ASSERT_THROW(Tequila("", -1, 3), std::invalid_argument);
    ASSERT_EQ(tequila1 == tequila2, false);
}

TEST(TEQUILA4, SOMETEST)
{
    Tequila tequila1;
    Tequila tequila2("name1", 80, 0.6);
    Tequila tequila3("name2", 240, 0.5);
    tequila2 = tequila3;
    ASSERT_THROW(tequila1.get_name(), std::invalid_argument);
    ASSERT_THROW(tequila1.get_price(), std::invalid_argument);
    ASSERT_THROW(tequila1.dilute(), std::invalid_argument);
}