#include <iostream>
#include <string>

bool is_valid(unsigned long long n);

int main() {
    unsigned long long h = 1389026623;
    unsigned long long l = 1010101010;

    unsigned long long n;


    for (unsigned long long i = l; i < h; ++i) {
        n = i * i;
        if (is_valid(n)) {
            std::cout << i << std::endl;
            return 0;
        }
    }

    return 0;
}

bool is_valid(unsigned long long n) {
    if (n % 10 != 0)
        return false;

    n /= 100;

    int dig;
    for (int i = 9; i > 0; --i) {
        dig = n % 10;
        if (dig != i)
            return false;
        n /= 100;
    }
    return true;
}
