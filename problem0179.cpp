#include <iostream>
#include "eutility.hpp"

#define LIM 10000000

int main() {
    int count = 0;
    int tmp1 = num_divisors(2), tmp2;
    for (int i = 3; i <= LIM; ++i) {
        tmp2 = num_divisors(i);
        if (tmp1 == tmp2) {
            ++count;
        }
        tmp1 = tmp2;
    }
    std::cout << count << std::endl;
}
