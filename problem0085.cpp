/*
By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:


Although there exists no rectangular grid that contains exactly two million rectangles, find the area 
of the grid with the nearest solution.
*/

#include <iostream>

using namespace std;

int numRects(int, int);
int choose2(int);
int abs(double);

int main(void) {
    int min = 2000000;
    double tmp;
    int x, y;
    for (int i = 1; i < 100; ++i) {
        for (int j = 1; j < 100; ++j) {
            tmp = abs(2000000 - numRects(i+1, j+1));
            if (tmp < min) {
                min = tmp;
                x = i;
                y = j;
            }
        }
    }
    cout << numRects(6, 8) << endl;
    cout << min << " " << x << " " << y << endl;
    cout << x * y << endl;
}

int abs(double x) {
    if (x < 0)
        return -1 * x;
    else
        return x;
}

int numRects(int x, int y) {
    return choose2(x) * choose2(y);
}

int choose2(int n) {
    return (n * (n-1)) / 2;
}
