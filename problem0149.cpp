/*
Looking at the table below, it is easy to verify that the maximum possible sum
of adjacent numbers in any direction (horizontal, vertical, diagonal or
anti-diagonal) is 16 (= 8 + 7 + 1).

−2  5   3   2
9   −6  5   1
3   2   7   3
−1  8   −4    8
Now, let us repeat the search, but on a much larger scale:

First, generate four million pseudo-random numbers using a specific form of
what is known as a "Lagged Fibonacci Generator":

For 1 ≤ k ≤ 55, sk = [100003 − 200003k + 300007k3] (modulo 1000000) − 500000.
For 56 ≤ k ≤ 4000000, sk = [sk−24 + sk−55 + 1000000] (modulo 1000000) − 500000.

Thus, s10 = −393027 and s100 = 86613.

The terms of s are then arranged in a 2000×2000 table, using the first 2000
numbers to fill the first row (sequentially), the next 2000 numbers to fill
the second row, and so on.

Finally, find the greatest sum of (any number of) adjacent entries in any
direction (horizontal, vertical, diagonal or anti-diagonal).
-------------------------------------------------------------------------------
Classic Jake Kardane
*/
#include <iostream>

void fill_table(int64_t **table);
int64_t max_horiz(int64_t **table);
int64_t max_vert(int64_t **table);

int main() {
    int64_t **table = new int64_t *[2000];

    for (int i = 0; i < 2000; ++i)
        table[i] = new int64_t[2000];

    fill_table(table);
    std::cout << max_horiz(table) << std::endl;
    std::cout << max_vert(table) << std::endl;
    delete[] table;
    return 0;
}

void fill_table(int64_t **table) {
    int64_t *fib = new int64_t[4000000];
    int64_t t;
    for (int k = 0; k < 4000000; ++k) {
        t = k + 1;
        if (t <= 55) {
            fib[k] = (100003 - (200003 * t) + (300007 * t * t * t)) % 1000000 - 500000;
        } else {
            fib[k] = ((fib[t-25] + fib[t-56] + 1000000) % 1000000) - 500000;
        }
    }

    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            table[i][j] = fib[(2000 * i) + j];
        }
    }
    delete[] fib;
}

int64_t max_vert(int64_t **table) {
    int64_t max = 0;
    int64_t cur_d = 0, cur_dl = 0, cur_dr = 0;
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            cur_d += table[j][i];
            if (cur_d < 0)
                cur_d = 0;
            if (cur_d > max)
                max = cur_d;
        }
        for (int k = i; k + i < 2000; ++k) {
            cur_dr = table[k-i][k];
            if (cur_dr < 0)
                cur_dr = 0;
            if (cur_dr > max)
                max = cur_d;
        }
        for (int l = i; l >= 0; --l) {
            cur_dl = table[i-l][l];
            if (cur_dl < 0)
                cur_dl = 0;
            if (cur_dl > max)
                max = cur_dl;
        }
        cur_d = 0;
        cur_dl = 0;
        cur_dr = 0;
    }
    return max;
}

int64_t max_horiz(int64_t **table) {
    int64_t max = 0;
    int64_t cur_r = 0, cur_du = 0, cur_dd = 0;
    for (int i = 0; i < 2000; ++i) {
        for (int j = 0; j < 2000; ++j) {
            cur_r += table[i][j];
            if (cur_r < 0)
                cur_r = 0;
            if (cur_r > max)
                max = cur_r;
        }
        for (int k = i; k + i < 2000; ++k) {
            cur_dd += table[k][k-i];
            if (cur_dd < 0)
                cur_dd = 0;
            if (cur_dd < max)
                max = cur_dd;
        }
        for (int l = i; l >= 0; --l) {
            cur_du += table[l][i-l];
            if (cur_du < 0)
                cur_du = 0;
            if (cur_du > max)
                max = cur_du;
        }
        cur_r = 0;
        cur_du = 0;
        cur_dd = 0;
    }
    return max;
}
