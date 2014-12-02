/*
Euler discovered the remarkable quadratic formula:
n² + n + 41
It turns out that the formula will produce 40 primes for the consecutive
values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41
is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly
divisible by 41.
The incredible formula  n² − 79n + 1601 was discovered, which produces 80
primes for the consecutive values n = 0 to 79. The product of the
coefficients, −79 and 1601, is −126479.
Considering quadratics of the form:
n² + an + b, where |a| < 1000 and |b| < 1000
where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |−4| = 4
Find the product of the coefficients, a and b, for the quadratic expression
that produces the maximum number of primes for consecutive values of n,
starting with n = 0.
*/

#include <iostream>
#include "PrimeSieve.hpp"

#define MAX 1000000

int primes_produced(int, int, PrimeSieve &);

int main() {
    PrimeSieve sieve(MAX);
    int max = 0;
    int tmp, max_a, max_b;
    for (int a = 1; a < 1000; ++a) {
        for (int b = 1; b < 1000; ++b) {
            tmp = primes_produced(a, b, sieve);
            if (tmp > max) {
                max = tmp;
                max_a = a;
                max_b = b;
            }
            tmp = primes_produced(-1 * a, b, sieve);
            if (tmp > max) {
                max = tmp;
                max_a = -1 * a;
                max_b = b;
            }
            tmp = primes_produced(a, -1 * b, sieve);
            if (tmp > max) {
                max = tmp;
                max_a = a;
                max_b = -1 * b;
            }
            tmp = primes_produced(-1 * a, -1 * b, sieve);
            if (tmp > max) {
                max = tmp;
                max_a = -1 * a;
                max_b = -1 * b;
            }
        }
    }
    std::cout << max_a * max_b << std::endl;
    std::cout << primes_produced(max_a, max_b, sieve) << std::endl;
    return 0;
}

// count the number of prime numbers produced by this quadratic
int primes_produced(int a, int b, PrimeSieve &sieve) {
    int c = 0;
    int tmp = (c * c) + a * c + b;
    while (tmp < MAX) {
        if (tmp < 0)
            return false;
        if (!sieve[tmp])
            break;
        ++c;
        tmp = (c * c) + a * c + b;
    }
    return c;
}