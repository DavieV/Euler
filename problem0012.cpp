/*
* Find the first triangle number to have over 500 divisors
*/

#include <iostream>
#include <cstring>

#define MAX 10000

using namespace std;

int primeCount(int, int);
int nextPrime(bool[], int);
void handleMultiples(bool[], int);
int numDivisors(int, bool[]);

int main(void) {
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;

    int prime = 2;

    for (int i = 0; i * i < MAX; i++) {
        handleMultiples(sieve, prime);
        prime = nextPrime(sieve, prime);
    }

    int num = 0;
    int i = 1;
    while (numDivisors(num, sieve) < 500) {
        num += i;
        i++;
    }
    cout << num << endl;
    cout << numDivisors(num, sieve) << endl;
    return 0;
}

void handleMultiples(bool sieve[], int n) {
    for (int i = n * n; i < MAX; i += n) {
        sieve[i] = false;
    }
}

int nextPrime(bool sieve[], int n) {
    n++;
    while (sieve[n] == false) n++;
    return n;
}

/*
Determine the number of times a prime number divides evenly into a number n
*/
int primeCount(int prime, int n)    {
    int count = 0;
    while (n % prime == 0) {
        n /= prime;
        count++;
    }
    return count;
}

/*
This function determines the number of divisors of a given number by prime
factoring the number, and then finding the product of each prime's exponent
with one added.
ex. 28 = 2 ^ 2 * 7
numDivisors(28) = 3 * 2 = 6
*/
int numDivisors(int n, bool sieve[]) {
    int divisors = 1;
    int prime = 2;
    while (prime <= n && prime < MAX) {
        divisors *= primeCount(prime, n) + 1;
        prime = nextPrime(sieve, prime);
    }
    return divisors;
}
