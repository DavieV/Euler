#include <iostream>
#include <cstring>
#include "eutility.hpp"

#define MAX 1500000

int main() {
    int triples[MAX+1];
    memset(triples, 0, sizeof(triples));

    int a, b, c, x, y, z;
    int mult = 2;
    for (int n = 1; n < 1000; ++n) {
        for (int m = n + 1; m < 1000; m += 2) {
            if (gcd(m, n) == 1) {
                a = (m * m) - (n * n);
                b = 2 * m * n;
                c = (m * m) + (n * n);
                x = a;
                y = b;
                z = c;
                while ((x + y + z) <= MAX) {
                    ++triples[x+y+z];
                    x = a * mult;
                    y = b * mult;
                    z = c * mult;
                    ++mult;
                }
                mult = 2;
            }
        }
    }

    int count = 0;
    for (int i = 0; i <= MAX; ++i)
        if (triples[i] == 1)
            ++count;

    std::cout << count << std::endl;
    return 0;
}
