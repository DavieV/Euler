/*
* Find the sum of all prime numbers under 2 million
*/

#include <iostream>
#include <cstring>

#define MAX 2000000

bool is_prime(int n);
int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);

int main() {
    int64_t sum = 0;
    bool sieve[10] = {true};
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i += p)
        s[i] = false;
}

bool is_prime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n * (i + 2) == 0)
            return false;
    }
    return true;
}
