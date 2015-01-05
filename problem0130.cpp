#include <iostream>
#include "eutility.hpp"

int repunit_factor(int n);

int main() {
    int64_t sum = 0;
    int count = 0;
    for (int i = 6; count < 25; ++i) {
        if (gcd(10, i) == 1) {
            if ((i - 1) % repunit_factor(i) == 0) {
                if (!is_prime(i)) {
                    sum += i;
                    ++count;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

int repunit_factor(int n) {
    int rem = 1, k = 1;
    while (rem != 0) {
        rem = (10 * rem + 1) % n;
        ++k;
    }
    return k;
}