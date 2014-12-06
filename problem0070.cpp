#include <iostream>
#include "eutility.hpp"

#define MAX 10000000

int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);

int main() {
    int *euler_sieve = new int[MAX];    // sieve for euler's totient function
    bool *prime_sieve = new bool[MAX];  // sieve of prime numbers

    for (int i = 0; i < MAX; ++i) {
        prime_sieve[i] = true;
        euler_sieve[i] = i;
    }

    prime_sieve[0] = false;
    prime_sieve[1] = false;
    int prime = 2;

    // Complete the sieve of prime numbers
    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, prime_sieve);
        prime = next_prime(prime, prime_sieve);
    }

    // Complete the sieve of euler totient functions
    for (int i = 1; i < MAX; ++i) {
        if (prime_sieve[i]) {
            for (int j = i; j < MAX; j += i)
                euler_sieve[j] -= euler_sieve[j] / i;
        }
    }

    double min = 1000000, tmp;
    int n;
    for (int i = 2; i < MAX; ++i) {
        if (is_permutation(i, euler_sieve[i])) {
            tmp = (double)(i) / (double)(euler_sieve[i]);
            if (tmp < min) {
                min = tmp;
                n = i;
            }
        }
    }

    std::cout << n << " " << euler_sieve[n] << std::endl;
    delete[] euler_sieve;
    delete[] prime_sieve;

    return 0;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i +=p)
        s[i] = false;
}
