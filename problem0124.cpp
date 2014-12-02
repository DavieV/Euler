#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 100000

bool less_than(std::pair<int, int> x, std::pair<int, int> y) {
    if (x.second < y.second)
        return true;
    if (x.second > y.second)
        return false;
    if (x.second == y.second)
        return x.first < y.first;
}

int rad(int n, std::vector<int> p);
int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);

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
    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    std::vector<std::pair<int, int>> pairs;
    for (int i = 1; i <= 100000; ++i) {
        pairs.push_back(std::make_pair(i, rad(i, primes)));
    }

    std::sort(pairs.begin(), pairs.end(), less_than);
    std::cout << pairs[9999].first << std::endl;
    return 0;
}

int rad(int n, std::vector<int> p) {
    int prod = 1;
    for (int i = 0; n > 1; ++i) {
        if (n % p[i] == 0) {
            prod *= p[i];
            while (n % p[i] == 0) {
                n /= p[i];
            }
        }
    }
    return prod;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i += p)
        s[i] = false;
}
