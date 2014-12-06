#include <iostream>
#include "eutility.hpp"

bool is_valid(int n);
bool odd_digits(int n);

int main() {
    int count = 0;
    for (int i = 11; i < 1000000000; i += 2) {
        if (is_valid(i))
            count += 2;
    }
    std::cout << count << std::endl;
    return 0;
}

bool is_valid(int n) {
    if (n % 10 == 0)  // the reverse will be invalid
        return false;
    int rev = reverse_num(n);
    return odd_digits(n + rev);
}

bool odd_digits(int n) {
    int dig;
    while (n > 0) {
        dig = n % 10;
        if (dig % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}
