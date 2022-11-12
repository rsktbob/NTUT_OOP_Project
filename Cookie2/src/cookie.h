#ifndef COOKIE_H
#define COOKIE_H

#include <iostream>
#include <string>
using namespace std;

int check_x(bool** grid){
    /* Return the x-coordinate of the lastest of cookie. */
    int check = 1;
    for(int  i = 1; i <= 9; i++) {
        for(int j = 9; j >= 0; j--) {
            if(grid[j][i] != false) {
                check = 0;
                break;
            }
        }
        if(check == 1) {
            return i-1;
        }
        check = 1;
    }
    return 9;
}

int check_y(bool** grid){
    /* Return the y-coordinate of the lastest of cookie. */
    int check = 1;
    for(int i = 8; i >= 0; i--) {
        for(int j = 0; j <= 9; j++) {
            if(grid[i][j] != false) {
                check = 0;
                break;
            }
        }
        if(check == 1) {
            return i+1;
        }
        check = 1;
    }
    return 0;
}

void print_grid(bool** grid){
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);
    /* Check when you place cookie, it will out of bound or not. */
    /* ... */
    if(y == 0) {
        throw string("out of range");
        return;
    }
    /* Place cookie from the top of current cookie. */
    grid[y-1][x] = true;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);
    /* Check when you place cookie, it will out of bound or not. */
    if(x == 9) {
        throw string("out of range");
        return;
    }
    /* Place cookie from the right of current cookie. */
    grid[y][x+1] = true;
}

int calcRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    if(row < 0 || row > 9) {
        return -1;
    }
    int count = 0;
    for(int i = 0; i < 10; i++) {
        if(grid[row][i] == true) {
            count++;
        }
    }
    return count;
}

int calcColumn(bool** grid, int column){
    /* Calculate the count of cookie on the specific column */
    if(column < 0 || column > 9) {
        return -1;
    }
    int count = 0;
    for(int i = 0; i < 10; i++) {
        if(grid[i][column] == true) {
            count++;
        }
    }
    return count;
}

#endif
