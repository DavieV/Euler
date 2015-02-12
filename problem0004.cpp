/*
* Finds the largest palindrome made by the product of two three-digit numbers
*/
#include <iostream>
#include "eutility.hpp"

using namespace std;

bool isPalindrome(int n);

int main() {
    int max = 0;
    int prod;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            prod = i * j;
            if (isPalindrome(prod) && prod > max)
                max = prod;
        }
    }
    cout << max << endl;
}

bool isPalindrome(int n) {
    return n == reverse_num(n);
}
