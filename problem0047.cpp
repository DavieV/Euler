/*
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX 1000000

using namespace std;

int nextPrime(int, bool[]);
bool fourDistinct(int, vector<int>, bool[]);
void handleMultiples(int, bool[]);

int main() {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = 0;
    sieve[1] = 0;

    int prime = 2;
    vector<int> primes;

    for (int i = 0; i * i < MAX; ++i) {
        handleMultiples(prime, sieve);
        prime = nextPrime(prime, sieve);
    }

    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            primes.push_back(i);
    }

    int i = 1;
    for (int i = 0; i < 1000000; ++i) {
        if (fourDistinct(i, primes, sieve)) {
            if (fourDistinct(i+1, primes, sieve)) {
                if (fourDistinct(i+2, primes, sieve)) {
                    if (fourDistinct(i+3, primes, sieve)) {
                        cout << i << endl;
                        break;
                    } else {
                        ++i;
                    }
                } else {
                    i += 2;
                }
            } else {
                i += 3;
            }
        } else {
            i += 4;
        }
    }
    cout << i << endl;
    return 0;
}

int nextPrime(int p, bool sieve[]) {
    ++p;
    while (!sieve[p]) ++p;
    return p;
}

void handleMultiples(int p, bool sieve[]) {
    for (int i = p * p; i < MAX; i += p)
        sieve[i] = false;
}

bool fourDistinct(int x, vector<int>primes, bool sieve[]) {
    if (sieve[x])
        return false;
    int count = 0;  // count the number of distinct prime factors of x
    for (int i = 0; i < primes.size() && x > 1; ++i) {
        if (x % primes[i] == 0) {
            ++count;
            while (x % primes[i] == 0)
                x /= primes[i];
            if (count > 4)
                return false;
        }
    }
    return count == 4;
}
