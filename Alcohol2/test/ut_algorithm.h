#include "../src/algorithm.h"

using namespace std;

TEST(ALGORITHM1, SOMETEST)
{
    vector<Alcohol *> alcohol;
    Tequila tequlia1("name1", 80., 0.8);
    Sour sour1("name3", 60, 0.3);
    Tequila tequlia2("name2", 50, 0.3);
    alcohol.push_back(&tequlia1);
    alcohol.push_back(&sour1);
    alcohol.push_back(&tequlia2);
    sort_alcohol_by_name(alcohol);
    sort_alcohol_by_content(alcohol);
    ASSERT_EQ("name2", get_smallest_content_of_alcohol(alcohol)->get_name());
    ASSERT_EQ("name1", get_greatest_content_of_alcohol(alcohol)->get_name());
    alcohol.clear();
}

TEST(ALGORITHM2, SOMETEST)
{
    vector<Alcohol *> alcohol;
    Tequila tequlia1("name2", 80., 0.3);
    Sour sour1("name1", 60, 0.3);
    Tequila tequlia2("name3", 50, 0.6);
    alcohol.push_back(&tequlia1);
    alcohol.push_back(&sour1);
    alcohol.push_back(&tequlia2);
    sort_alcohol_by_content(alcohol);
    ASSERT_EQ("name1", get_smallest_content_of_alcohol(alcohol)->get_name());
    ASSERT_EQ("name3", get_greatest_content_of_alcohol(alcohol)->get_name());
    alcohol.clear();
}

TEST(ALGORITHM3, SOMETEST)
{
    vector<Alcohol *> alcohol;
    Tequila tequlia1("name2", 80., 0.6);
    Sour sour1("name1", 60, 0.6);
    Tequila tequlia2("name3", 50, 0.3);
    alcohol.push_back(&tequlia1);
    alcohol.push_back(&sour1);
    alcohol.push_back(&tequlia2);
    ASSERT_EQ("name3", get_smallest_content_of_alcohol(alcohol)->get_name());
    ASSERT_EQ("name2", get_greatest_content_of_alcohol(alcohol)->get_name());
    alcohol.clear();
}