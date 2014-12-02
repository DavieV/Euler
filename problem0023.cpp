/*
A perfect number is a number for which the sum of its proper divisors is exactly
equal to the number. 
For example, the sum of the proper divisors of 28 would be 
1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
and it is called abundant 
if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
that can be written as the sum of two abundant numbers is 24. By mathematical 
analysis, it can be shown that all integers greater than 28123 can be written as
the sum of two abundant numbers. However, this upper limit cannot be reduced any further
by analysis even though it is known that the greatest number that cannot be expressed 
as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two 
abundant numbers.
*/

#include <iostream>
#include <vector>
#include <map>

#define MAX 28123

using namespace std;

bool is_abundant(int);
map<int, bool> sum_abundant(vector<int>);
int find_sum(map<int, bool>);

int main() {
    vector<int> abund;
    for (int i = 2; i <= MAX; ++i) {
        if (is_abundant(i))
            abund.push_back(i);
    }
    map<int, bool> nums = sum_abundant(abund);
    int sum = find_sum(nums);
    cout << sum << endl;
    return 0;
}

/* 
* find the sum of all numbers with the bound that aren't in the map
* i.e numbers that can't be represented as a sum of abundant numbers
*/
int find_sum(map<int, bool> nums) {
    int sum = 0;
    for (int i = 0; i <= MAX; ++i) {
        if (nums.find(i) == nums.end())  // if i is not in the map
            sum += i;
    }
    return sum;
}

/*
* create a map of all of the numbers that can be represented as a sum of
* two abundant numbers
*/
map<int, bool> sum_abundant(vector<int> abund) {
    map<int, bool> nums;
    for (int i = 0; i < abund.size(); ++i)
        for (int j = i; j < abund.size(); ++j) {
            if (abund[i] + abund[j] <= MAX)
                nums[abund[i] + abund[j]] = true;
            else
                break;
        }
    return nums;
}

// determine whether or not a number is abundant
bool is_abundant(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (n / i == i)
                sum += i;
            else
                sum += i + (n / i);
        }
    }
    return sum > n;
}
