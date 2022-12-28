#include "../src/sour.h"

TEST(SOUR1, SOMETEST)
{
    Sour sour("name1", 240, 0.8);
    ASSERT_EQ(sour.get_name(), "name1");
    ASSERT_EQ(sour.get_price(), 240);
    ASSERT_NEAR(sour.get_alcohol_content(), 0.8, 0.01);
};

TEST(SOUR2, SOMETEST)
{
    Sour sour1("name1", 240, 0.8);
    Sour sour2("name2", 80, 0.6);
    sour1 = sour1;
    sour1 = sour2;
    sour1 = sour1+sour2;
    ASSERT_EQ(sour1.get_name(), "name2");
    ASSERT_EQ(sour1.get_price(), 160);
    ASSERT_NEAR(sour1.get_alcohol_content(), 0.6, 0.01);
    ASSERT_EQ(sour1 == sour1, true);
}

TEST(SOUR3, SOMETEST)
{
    Sour sour1;
    ASSERT_THROW(sour1.get_name(), std::invalid_argument);
    ASSERT_THROW(Sour("", -1, 3), std::invalid_argument);
}

TEST(SOUR4, SOMETEST)
{
    Sour sour1("name1", 240, 0.8);
    Sour sour2("name2", 80, 0.1);
    sour1.dilute();
    ASSERT_THROW(sour2.dilute(), std::invalid_argument);
}


