/*Calculate the sum of all multiples of 3 and 5 less than 1000 */

#include <iostream>

int sum(int n);

int main() {
    std::cout << sum(1000) << std::endl;
}

int sum(int n) {
    int threes = (n-1) / 3 * ((n-1) / 3 + 1) / 2 * 3;
    int fives = (n-1) / 5 * ((n-1) / 5 + 1) / 2 * 5;
    int fifteens = (n-1) / 15 * ((n-1) / 15 + 1) / 2 * 15;
    return threes + fives - fifteens;
}

