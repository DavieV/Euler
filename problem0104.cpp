#include <cmath>
#include <iostream>
#include "eutility.hpp"

int pand_term();

int main() {
    std::cout << pand_term() << std::endl;
    return 0;
}

int pand_term() {
    double lg_rt_5 = 0.3494850021680094;
    double lg_phi = 0.20898764024997873;
    int p1 = 1, p2 = 1;
    int cur = 2;
    int t = 3;
    double f = t * lg_phi - lg_rt_5;
    while (!(pandig_9(cur) && pandig_9((int)pow(10, f - (int)f + 8)))) {
        p1 = p2;
        p2 = cur;
        cur = (p1 + p2) % 1000000000LL;
        ++t;
        f = t * lg_phi - lg_rt_5;
    }
    std::cout << cur << std::endl;
    std::cout << (int)pow(10, f - (int)f + 8) << std::endl;
    return t;
}
