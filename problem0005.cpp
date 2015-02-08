/*
* Find the smallest number evenly divisible by all integers from 1 to 20
*/

#include <iostream>

bool isValid(int n);

int main(void) {
    int i;
    for (i = 2520; !isValid(i); i++);
    std::cout << i << std::endl;
}

bool isValid(int n) {
    for (int i = 1; i <= 20; i++) {
        if (n % i != 0) return false;
    }
    return true;
}
