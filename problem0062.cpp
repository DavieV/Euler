#include <iostream>
#include <unordered_map>
#include <cmath>

std::string sort_digits(long long n);
std::string get_key(int n);
long long first_cube(std::string key);

int main() {
    std::cout << first_cube(get_key(5)) << std::endl;
    return 0;
}

long long first_cube(std::string key) {
    long long cube;
    for (int i = 1; i < 10000; ++i) {
        cube = pow(i, 3);
        if (sort_digits(cube) == key)
            return cube;
    }
    return -1;
}

std::string sort_digits(long long n) {
    int digits[10];
    for (int i = 0; i < 10; ++i)
        digits[i] = 0;
    while (n > 0) {
        ++digits[n%10];
        n /= 10;
    }
    std::string sorted = "";
    for (int i = 0; i < 10; ++i) {
        while (digits[i] > 0) {
            sorted = sorted + (char)(i + '0');
            --digits[i];
        }
    }
    return sorted;
}

std::string get_key(int n) {
    std::unordered_map<std::string, int> cubes;
    std::string key;
    long long cube;
    for (int i = 1; i < 10000; ++i) {
        cube = pow(i, 3);
        key = sort_digits(cube);
        if (cubes.find(key) == cubes.end()) {
            cubes[key] = 1;
        } else {
            ++cubes[key];
            if (cubes[key] == n) {
                return key;
            }
        }
    }
    return "";
}
