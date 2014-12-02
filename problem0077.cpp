#include <iostream>
#include <cstring>
#include <vector>

#define MAX 10000

void del_mult(int, bool[]);
int next_prime(int, bool[]);
int find_sum(std::vector<int>);

int main() {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = 0;
    sieve[1] = 0;
    int prime = 2;

    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    // build a vector of the prime numbers for more efficient traversals
    std::vector<int> primes;
    for (int i = 0; i < MAX; ++i)
        if (sieve[i])
            primes.push_back(i);

    std::cout << find_sum(primes) << std::endl;
    return 0;
}

/*
* Uses dynamic programming to find the number of ways to find the sum
* based on the previous values
*/
int find_sum(std::vector<int> primes) {
    int sums[MAX];
    memset(sums, 0, sizeof(sums));
    sums[0] = 1;  // base case
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (j - primes[i] >= 0)
                sums[j] += sums[j-primes[i]];
        }
    }

    for (int i = 0; i < MAX; ++i)
        if (sums[i] > 5000)
            return i;
    return -1;
}

int next_prime(int p, bool sieve[]) {
    while (!sieve[++p]);
    return p;
}

void del_mult(int p, bool sieve[]) {
    for (int i = p * p; i < MAX; i+=p)
        sieve[i] = false;
}
