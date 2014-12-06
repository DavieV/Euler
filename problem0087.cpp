#include <iostream>
#include <vector>
#include <cmath>
#include <set>

#define MAX 8000
#define LIMIT 50000000

void del_mult(int p, bool s[]);
int next_prime(int p, bool s[]);
int count(std::vector<int> p);

int main() {
    bool sieve[MAX];

    for (int i = 0; i < MAX; ++i)
        sieve[i] = true;

    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    std::vector<int> primes;

    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    std::cout << count(primes) << std::endl;

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

int count(std::vector<int> p) {
    std::set<int> sums;
    int sum;
    for (int i = 0; (pow(p[i], 2)) < LIMIT; ++i) {
        for (int j = 0; (pow(p[i], 2) + pow(p[j], 3)) < LIMIT; ++j) {
            for (int k = 0; (sum = (pow(p[i], 2) + pow(p[j], 3) + pow(p[k], 4))) < LIMIT; ++k) {
                sums.insert(sum);
            }
        }
    }
    return sums.size();
}
