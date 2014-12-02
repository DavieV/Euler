/*
Find the sum of all 11 truncateable primes from left-to-right and right-to-left
*/

#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 1000000

using namespace std;

int handlemultiples(int, bool[]);
int nextPrime(int, bool[]);
bool isValid(string, bool[]);

int main(void) {
    bool primes[MAX];
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;

    int prime = 2;
    for (int i = 0; i < sqrt(MAX) + 1; i++) {
        handlemultiples(prime, primes);
        prime = nextPrime(prime, primes);
    }

    int sum = 0;
    for (int j = 10; j < MAX; j++) {
        if (isValid(to_string(j), primes)) {
            cout << j << endl;
            sum += j;
        }
    }
    cout << sum << endl;
}

int handlemultiples(int prime, bool primes[]) {
    for (int i = prime * prime; i < MAX; i+=prime) {
        primes[i] = false;
    }
}

int nextPrime(int prime, bool primes[]) {
    while (primes[++prime] == false);
    return prime;
}

bool isValid(string num, bool primes[]) {
    string left = num;
    while (num.length() > 0) {
        if (primes[stoi(num)] != true || primes[stoi(left)] != true)
            return false;
        left = left.substr(1, left.length());
        num = num.substr(0, num.length()-1);
    }
    return true;
}
