/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/

#include <iostream>
#include <cstring>

using namespace std;

bool is_pandigital(long long);
bool is_prime(long long);

int main(){
    for (long long i = 7654321; i > 0; --i) {
        if (is_prime(i) && is_pandigital(i)) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

bool is_prime(long long x) {
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i < x + 1; ++i) {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool is_pandigital(long long x) {
    int occur[10];
    int len = 0;
    memset(occur, 0, sizeof(occur));
    while (x > 0) {
        ++occur[x%10];
        x /= 10;
        ++len;
    }
    if (occur[0] != 0)
        return false;
    for (int i = 1; i < len; ++i) {
        if (occur[i] != 1)
            return false;
    }
    return true;
}
