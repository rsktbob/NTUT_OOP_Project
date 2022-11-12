#include "../src/cookie.h"

bool** create_grid() {
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    return array;
}

void delete_grid(bool** array) {
    for(int i = 0; i < 10; i++) {
        delete []array[i];
    }
    delete []array;
}

TEST(cookie1, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);
    placeTop(grid);
    placeTop(grid);
    ASSERT_EQ(calcRow(grid,7),3);
    ASSERT_EQ(calcColumn(grid,0),3); 
    delete_grid(grid);
}

TEST(cookie2, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    int compare1 = calcRow(grid,6);
    int compare2 = calcColumn(grid,0);
    int output1 = 2;
    int output2 = 4;
    ASSERT_EQ(calcRow(grid,6),2);
    ASSERT_EQ(calcColumn(grid,0),4);
    delete_grid(grid);
}

TEST(cookie3, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    ASSERT_THROW(placeTop(grid),string);
    delete_grid(grid);
}

TEST(cookie4, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    ASSERT_THROW(placeRight(grid),string);
    delete_grid(grid);
}

TEST(cookie5, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    ASSERT_EQ(calcRow(grid,62343),-1);
    delete_grid(grid);
}

TEST(cookie6, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    ASSERT_EQ(calcColumn(grid,-214634),-1);
    delete_grid(grid);
}

TEST(cookie7, SomeTest) {
    bool ** grid = create_grid();
    grid[9][0] = true;
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    ASSERT_EQ(calcColumn(grid,0),10);
    delete_grid(grid);
}
