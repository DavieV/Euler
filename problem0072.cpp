/*
Consider the fraction, n/d, where n and d are positive integers. If
n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending
order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8,
2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions
for d ≤ 1,000,000?
*/

#include <iostream>
#include <cstring>

#define MAX 1000000

int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);

int main() {
    int euler_sieve[MAX+1];   // sieve for Euler's totient function
    bool prime_sieve[MAX+1];  // sieve of prime numbers

    for (int i = 0; i <= MAX; ++i) {
        prime_sieve[i] = true;
        euler_sieve[i] = i;
    }

    prime_sieve[0] = false;
    prime_sieve[1] = false;
    int prime = 2;

    // Complete the sieve of prime numbers
    for (int i = 0; i * i <= MAX; ++i) {
        del_mult(prime, prime_sieve);
        prime = next_prime(prime, prime_sieve);
    }

    // complete the sieve for Euler's totient function
    for (int i = 1; i <= MAX; ++i) {
        if (prime_sieve[i]) {
            for (int j = i; j <= MAX; j += i)
                euler_sieve[j] -= euler_sieve[j] / i;
        }
    }

    int64_t count = 0;
    for (int i = 2; i <= MAX; ++i)
        count += euler_sieve[i];

    std::cout << count << std::endl;

    return 0;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i <= MAX; i +=p)
        s[i] = false;
}
