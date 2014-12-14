#include <iostream>
#include <set>
#include "eutility.hpp"

#define LIM 10000

int main() {
    int64_t cur;
    std::set<int64_t> nums;
    for (int i = 1; i < LIM; ++i) {
        cur = (i * i);
        for (int j = i+1; cur < LIM * LIM; ++j) {
            cur += (j * j);
            if (is_palindrome(cur) && cur < LIM * LIM) {
                nums.insert(cur);
            }
        }
    }

    int64_t total = 0;
    for (int64_t i : nums) {
        total += i;
    }
    std::cout << total << std::endl;
    return 0;
}
