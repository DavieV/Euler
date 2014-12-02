/*
We shall say that an n-digit number is pandigital if it makes use of all the
digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5
pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity
can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only
include it once in your sum.
*/

#include <iostream>
#include <map>
#include <cstring>

using namespace std;

bool is_pandigital(int, int, int);
int sum_map(map<int, bool>);

int main() {
    map<int, bool>nums;
    for (int i = 0; i < 1000; ++i) {
        for (int j = i; j < 2000; ++j) {
            if (is_pandigital(i, j, i * j))
                nums[i * j] = true;
        }
    }
    int sum = sum_map(nums);
    cout << sum << endl;
    return 0;
}

int sum_map(map<int, bool>nums) {
    int s = 0;
    for (int i = 0; i < 10000; ++i) {
        if (nums.find(i) != nums.end())  // if i is in the map add it to the sum
            s += i;
    }
    return s;
}

/*
simply checks whether or not two numbers and their product form a 1-9
pandigital. It does this by counting the occurences of each digit, and
if each digit occurs exactly once (except for 0 no times) then it is
1-9 pandigital
*/
bool is_pandigital(int x, int y, int z) {
    int occur[10];  // we are dealing with 1-9 pandigital numbers
    memset(occur, 0, sizeof(occur));  // start with 0 occurences for each number
    while (x > 0) {
        ++occur[x%10];
        x /= 10;
    }
    while (y > 0) {
        ++occur[y%10];
        y /= 10;
    }
    while (z > 0) {
        ++occur[z%10];
        z /= 10;
    }
    if (occur[0] != 0) {
        return false;
    }
    for (int i = 1; i < 10; ++i) {
        if (occur[i] != 1)
            return false;
    }
    return true;
}
