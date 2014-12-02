/*
It was proposed by Christian Goldbach that every odd composite number
can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum
of a prime and twice a square?
*/

#include <iostream>
#include <cmath>
#include "PrimeSieve.hpp"

#define MAX 1000000

using namespace std;

bool p_square(int);
bool goldbach(int, PrimeSieve &);

int main() {
    PrimeSieve sieve(MAX);
    int i = 9;
    while (goldbach(i, sieve)) {
        i += 2;
    }
    cout << i << endl;
    return 0;
}

// determines if a number is a perfect square
bool p_square(int x) {
    int tmp = static_cast<int>(sqrt(x));
    return x == tmp * tmp;
}

bool goldbach(int x, PrimeSieve &sieve) {
    if (sieve[x])
        return true;
    for (int i = 0; x - i > 0 && i < MAX; ++i) {
        if (sieve[i] && p_square((x - i)/ 2))
            return true;
    }
    return false;
}
