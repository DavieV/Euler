#include <iostream>

#define LIM 1000000000

long long greater(int n);
long long lesser(int n);

int main() {
    int n = 1;
    long long sum = 0;
    while ((3 * greater(n) + 1) < LIM && (3 * lesser(n) + 2) < LIM) {
        sum += (3 * greater(n) + 1) + (3 * lesser(n) + 2);
        ++n;
    }
    std::cout << sum << std::endl;
    return 0;
}

long long greater(int n) {
    if (n == 1) return 5;
    if (n == 2) return 65;
    if (n == 3) return 901;
    return (15 * greater(n - 1)) - (15 * greater(n - 2)) + greater(n - 3);
}

long long lesser(int n) {
    if (n == 1) return 16;
    if (n == 2) return 240;
    if (n == 3) return 3360;
    return (15 * lesser(n - 1)) - (15 * lesser(n - 2)) + lesser(n - 3);
}
