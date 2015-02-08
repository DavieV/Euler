#include <iostream>
#include <cstring>
#include <set>
#include <vector>

#define SIZE 8
#define MAX 1000000

void build_pascals(int64_t **a);
std::set<int64_t> get_distinct(int64_t **a);
void del_mult(int p, bool s[]);
int next_prime(int p, bool s[]);
bool squarefree(std::vector<int64_t> prime_squares, int64_t n);

int main() {
    int64_t **triangle = new int64_t *[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        triangle[i] = new int64_t[SIZE];
        memset(triangle[i], 0, sizeof(triangle[i]));
    }

    build_pascals(triangle);
    std::set<int64_t> distinct = get_distinct(triangle);

    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;
    sieve[1] = false;
    int prime = 2;

    for (int i = 0; i * i < MAX; ++i) {
        del_mult(prime, sieve);
        prime = next_prime(prime, sieve);
    }

    std::vector<int64_t> prime_squares;

    for (int i = 0; i < MAX; ++i) {
        if (sieve[i])
            prime_squares.push_back(i*i);
    }

    int64_t sum = 0;
    for (auto i : distinct) {
        if (squarefree(prime_squares, i)) {
            std::cout << i << std::endl;
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    delete[] triangle;
    return 0;
}

void build_pascals(int64_t **a) {
    for (int i = 0; i < SIZE; ++i) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (a[i][j] == 0)
                a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
}

std::set<int64_t> get_distinct(int64_t **a) {
    std::set<int64_t> distinct;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE && a[i][j] != 0; ++j) {
            distinct.insert(a[i][j]);
        }
    }
    return distinct;
}

void del_mult(int p, bool s[]) {
    for (int i = p * p; i < MAX; i += p)
        s[i] = false;
}

int next_prime(int p, bool s[]) {
    while (!s[++p]);
    return p;
}

bool squarefree(std::vector<int64_t> prime_squares, bool s[], int64_t n) {
    for (int i = 0; prime_squares[i] * prime_squares[i] < n; ++i) {
        if (n % prime_squares[i] == 0)
            return false;
    }
    return s[sqrt(n)];
}
