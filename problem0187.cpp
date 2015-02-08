#include <iostream>
#include <vector>
#include "PrimeSieve.hpp"

int main() {
    std::vector<int> primes = PrimeSieve(10000000)::make_vector;
    return 0;
}
