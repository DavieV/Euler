#include <iostream>
#include <unordered_map>

int cycle_len(int);

int main() {
    int max = 0;
    for (int i = 1; i < 1000; ++i) {
        if (cycle_len(i) > max)
            max = i;
    }
    std::cout << max << std::endl;
    return 0;
}

// determine the length of the reciprocal cycle 1/n
int cycle_len(int n) {
    std::unordered_map<int, bool> nums;
    int start = 10;
    int times = start / n;
    int len = 0;
    while (nums.find(start) == nums.end()) {
        nums[start] = true;
        start = (start - (n * times)) * 10;
        times = start / n;
        ++len;
        if (start == 0)
            return len;
    }
    return len;
}
