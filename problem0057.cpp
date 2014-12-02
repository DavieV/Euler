#include <iostream>

bool valid_fraction(int);
void swap(long long *, long long *);
int num_len(long long);

int main() {
    int count = 0;
    for (int i = 0; i < 1000; ++i) {
        if (valid_fraction(i))
            ++count;
    }
    std::cout << count << std::endl;
    return 0;
}

bool valid_fraction(int cycles) {
    long long n = 1, d = 2;
    for (; cycles > 0; --cycles) {
        n += 2 * d;
        swap(&n, &d);
    }
    n += d;
    if (num_len(n) > num_len(d)) {
        std::cout << n << " / " << d << std::endl;
        return true;
    }
    //return num_len(n) > num_len(d);
    return false;
}

void swap(long long *a, long long *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b; 
}

int num_len(long long n) {
    long long cap = 10;
    int len = 1;
    while (n > cap) {
        cap *= 10;
        ++len;
    }
    return len;
}
