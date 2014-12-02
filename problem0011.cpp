/*
* Find the largest product of 4 adjacent integers in a 20x20 grid. The integers can be located vertically, 
horizontally, and diagonally
*/

#include <iostream>

using namespace std;

int findLargest(int[][20]);
int maxLine(int[][20], int, int);
int maxDiag(int[][20], int, int);

int main(void) {
    int grid[20][20];

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << findLargest(grid) << endl;
}

int findLargest(int grid[][20]) {
    int max = 0;
    int tmp1, tmp2;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            tmp1 = maxLine(grid, i, j);
            tmp2 = maxDiag(grid, i, j);
            if (tmp1 > max) {
                max = tmp1;
                cout << max << endl;
            }
            if (tmp2 > max) {
                max = tmp2;
                cout << max << endl;
            }
        }
    }
    return max;
}

int maxLine(int grid[][20], int i, int j) {
    int max = 0;
    if (i >= 3) {
        int up = grid[i][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j];
        if (up > max) max = up;
    }
    if (i <= 16) {
        int down = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
        if (down > max) max = down;
    }
    if (j >= 3) {
        int left = grid[i][j] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3];
        if (left > max) max = left;
    }
    if (j <= 16) {
        int right = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
        if (right > max) right = max;
    }
    return max;
}

int maxDiag(int grid[][20], int i, int j) {
    int max = 0;
    if (i >= 3 && j >= 3) {
        int upL = grid[i][j] * grid[i-1][j-1] * grid[i-2][j-2] * grid[i-3][j-3];
        if (upL > max) max = upL;
    }
    if (i >= 3 && j <= 16) {
        int upR = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
        if (upR > max) max = upR;
    }
    if (i <= 16 && j >= 3) {
        int dnL = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
        if (dnL > max) max = dnL;
    }
    if (i <= 16 && j <= 16) {
        int dnR = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
        if (dnR > max) max = dnR;
    }
    return max;
}
