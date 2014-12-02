/*
The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169;
it turns out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a
starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
*/

#include <iostream>
#include <map>

using namespace std;

int fact(int n);
int sumDigits(int n);

int main(void) {
    map<int, int> nums;
    int chains = 0;
    for (int i = 0; i < 1000000; ++i) {
        int count = 0;
        int cur = i;
        nums[cur] = 1;
        while (nums[cur] < 2) {
            cur = sumDigits(cur);
            count++;
            if (nums.find(cur) != nums.end())
                nums[cur]++;
            else
                nums[cur] = 1;
        }
        if (count == 60) chains++;
        nums.clear();
    }
    cout << chains << endl;
}

int fact(int n) {
    int tmp = 1;
    for (int i = 2; i <= n; ++i) {
        tmp *= i;
    }
    return tmp;
}

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += fact(n % 10);
        n /= 10;
    }
    return sum;
}
