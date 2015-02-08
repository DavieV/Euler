#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <unordered_map>
#include "eutility.hpp"

#define MAX 1000000

int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);
int concat(int m, int n, bool s[]);

int main() {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    std::vector<int> primes;
    for (int i = 2; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    std::unordered_map<int, std::pair<int, int>> groups;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i+1; concat(i, j, sieve) != -1; ++j) {
            if (concat(primes[i], primes[j], sieve) == 1) {
                if (groups.find(primes[i]) == groups.end()) {
                    groups[primes[i]].first = 1;
                    groups[primes[i]].second = primes[i] + primes[j];
                } else {
                    groups[primes[i]].first += 1;
                    groups[primes[i]].second += primes[j];
                }
            }
        }
    }

    for (int i = 0; i < primes.size(); ++i) {
        if (groups[primes[i]].first == 5)
            std::cout << groups[primes[i]].first << " " << groups[primes[i]].second << std::endl;
    }
    return 0;
}

int concat(int m, int n, bool s[]) {
    int64_t a = m, b = n;
    int64_t val1 = (a * static_cast<int>(pow(10, num_len(b)))) + b;
    int64_t val2 = (b * static_cast<int>(pow(10, num_len(a)))) + a;
    if (val1 > MAX || val2 > MAX)
        return -1;
    else
        return s[val1] && s[val2];
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i += p)
        s[i] = false;
}
