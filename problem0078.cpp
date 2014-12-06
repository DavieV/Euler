#include <iostream>
#include <cstring>

#define MAX 100000

int main() {
    long sums[MAX+1];
    memset(sums, 0, sizeof(sums));
    sums[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        for (int j = i; j <= MAX; ++j) {
            sums[j] = (sums[j] + sums[j-i]) % 1000000;
        }
    }

    for (int i = 0; i <= MAX; ++i) {
        if (sums[i] % 1000000 == 0)
            std::cout << i << std::endl;
    }
    return 0;
}
