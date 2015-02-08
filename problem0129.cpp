#include <iostream>
#include "eutility.hpp"

int repunit_factor(int64_t n);

int main() {
    for (int i = 1; ; ++i) {
        if (gcd(10, i) == 1) {
            if (repunit_factor(i) > 1000000) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}

int repunit_factor(int64_t n) {
    int rem = 1, k = 1;
    while (rem != 0) {
        rem = (10 * rem + 1) % n;
        ++k;
    }
    return k;
}
