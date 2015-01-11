#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>

#define MAX 1000000

int next_prime(int p, bool s[]);
void del_mult(int p, bool s[]);
int valid_prime(int p);
int digits(std::pair<int, int> n);
int family(std::pair<int, int> n, int change, bool s[]);

int main() {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    // Fill in the sieve
    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    std::vector<int> primes;

    // Create a vector of prime numbers
    for (int i = 0; i < MAX; i++) {
        if (sieve[i])
            primes.push_back(i);
    }

    std::vector<std::pair<int, int>> rpt_primes;

    int tmp;
    for (int i : primes) {
        tmp = valid_prime(i);
        if (tmp >= 0)
            rpt_primes.push_back(std::make_pair(i, tmp));
    }

    for (auto i : rpt_primes) {
        if (family(i, digits(i), sieve) == 8) {
            std::cout << i.first << std::endl;
        }
    }
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

int valid_prime(int p) {
    int occur[10] = {0};
    p /= 10;
    while (p > 0) {
        ++occur[p%10];
        p /= 10;
    }
    if (occur[0] >= 3)
        return 0;
    if (occur[1] >= 3)
        return 1;
    if (occur[2] >= 3)
        return 1;
    return -1;
}

int digits(std::pair<int, int> n) {
    int tmp = n.first;
    int power = 1;
    int dig = 0;
    tmp /= 10;
    while (tmp > 0) {
        if (tmp % 10 == n.second) {
            dig += static_cast<int>(pow(10, power));
        }
        ++power;
        tmp /= 10;
    }
    return dig;
}

int family(std::pair<int, int> n, int change, bool s[]) {
    int size = 1;
    int p = n.first;
    int lim = 9 - n.second;
    for (int i = 0; i < lim; ++i) {
        p += change;
        if (s[p])
            ++size;
    }
    return size;
}
