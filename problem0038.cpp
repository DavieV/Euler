/*
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call
192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the
concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int num_size(long long);
bool is_pandigital(long long);

int main() {
    long long cur = 0;
    int digits = 0;
    long long max = 0;
    for (int i = 1; i < 10000; ++i) {
        for (int j = 1; digits < 9; ++j) {
            digits += num_size(i * j);
            cur = cur * pow(10, num_size(i * j)) + (i * j);
        }
        if (digits == 9 && is_pandigital(cur)) {
            if (cur > max)
                max = cur;
        }
        digits = 0;
        cur = 0;
    }
    cout << max << endl;
    return 0;
}

int num_size(long long x) {
    if (x < 10)
        return 1;
    if (x < 100)
        return 2;
    if (x < 1000)
        return 3;
    if (x < 10000)
        return 4;
    if (x < 100000)
        return 5;
    if (x < 1000000)
        return 6;
    if (x < 10000000)
        return 7;
    if (x < 100000000)
        return 8;
    if (x < 1000000000)
        return 9;
}

bool is_pandigital(long long num) {
    int occur[10];
    memset(occur, 0, sizeof(occur));
    while (num > 0) {
        ++occur[num%10];
        num /= 10;
    }
    if (occur[0] != 0)
        return false;
    for (int i = 1; i < 10; ++i) {
        if (occur[i] != 1)
            return false;
    }
    return true;
}
