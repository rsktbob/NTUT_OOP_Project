#include "../src/order.h"
#include "../src/algorithm.h"

TEST(ORDER1, SOMETEST)
{
    Order order;
    Tequila tequlia1("name1", 80., 0.8);
    Sour sour1("name2", 60, 0.3);
    Tequila tequlia2("name3", 50, 0.3);
    order.append_alcohol(&tequlia1);
    order.append_alcohol(&sour1);
    order.append_alcohol(&tequlia2);
    ASSERT_EQ(3, order.get_alcohol_count());
    ASSERT_EQ(190, order.get_total_price());
}