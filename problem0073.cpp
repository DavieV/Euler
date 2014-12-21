#include <iostream>

int count_fractions(int n);

int main() {
    std::cout << count_fractions(12000) << std::endl;
    return 0;
}

int count_fractions(int n) {
    int a = 0, b = 1, c = 1, d = n;
    int k, t1, t2;
    int count = 0;
    bool counting = false;
    while (c <= n) {
        if (a == 1 && b == 3)
            counting = true;
        if (counting && !(a == 1 && b == 3) && !(a == 1 && b == 2))
            ++count;
        if (a == 1 && b == 2)
            return count;
        t1 = a;
        t2 = b;
        k = (n + b) /  d;
        a = c;
        b = d;
        c = (k * c) - t1;
        d = (k * d) - t2;
    }
    return count;
}
