#include <iostream>
#include <cstring>

int main() {
    int sums[101];
    memset(sums, 0, sizeof(sums));
    sums[0] = 1;
    for (int i = 1; i < 100; ++i) {
        for (int j = i; j <= 100; ++j) {
            sums[j] += sums[j-i];
        }
    }
    std::cout << sums[100] << std::endl;
    return 0;
}
