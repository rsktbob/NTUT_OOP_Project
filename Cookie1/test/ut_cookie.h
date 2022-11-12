#include "../src/cookie.h"

TEST(COOKIE1, max_dv) {
    int test[4] = {1,2,3,4};
    int output = max_dv(4,test);
    int compare = 6;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE2, max_dv) {
    int test[6] = {1,2,3,4,5,6};
    int output = max_dv(6,test);
    int compare = 12;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE3, max_dv) {
    int test[5] = {1,2,3,4,5};
    int output = max_dv(5,test);
    int compare = 9;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE4,max_dv) {
    int test[9] = {1,2,3,4,5,6,7,8,9};
    int output = max_dv(9,test);
    int compare = 25;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE5, max_dv) {
    int test[4] = {1,-2,3,4};
    int output = max_dv(4,test);
    int compare = -1;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE6, max_dv) {
    int test[6] = {1,2,-3,4,5,6};
    int output = max_dv(6,test);
    int compare = -1;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE7, max_dv) {
    int test[8] = {1,2,3,4,5,6,7,8};
    int output = max_dv(-8,test);
    int compare = -1;
    ASSERT_EQ(compare,output);
}

TEST(COOKIE8, max_dv) {
    int test[6] = {1,2,3,4,5,6};
    int output = max_dv(-6,test);
    int compare = -1;
    ASSERT_EQ(compare,output);
}
