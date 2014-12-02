/*
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers 
less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and 
relatively prime to nine, φ(9)=6.

n   Relatively Prime    φ(n)    n/φ(n)
2   1   1   2
3   1,2 2   1.5
4   1,3 2   2
5   1,2,3,4 4   1.25
6   1,5 2   3
7   1,2,3,4,5,6 6   1.1666...
8   1,3,5,7 4   2
9   1,2,4,5,7,8 6   1.5
10  1,3,7,9 4   2.5
It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.

This program makes use of a PrimeSieve class that was created by my friend Quinn. It the sieve or Erastothenes which is useful
for problems that have to do with prime numbers.
*/

#include <iostream>
#include "PrimeSieve.hpp"

using namespace std;

int main(void) {
    PrimeSieve sieve(1000001);

    int max = 0;
    int maxval;
    for (int i = 2; i < sieve.size(); i+=2) {
        int current = 0;
        for (int j = 0; j * j < i + 1; j++) {
            if (sieve[j] && i % j == 0) current++;
        }
        if (current > max) {
            max = current;
            maxval = i;
        }
    }
    cout << maxval << endl;
}
