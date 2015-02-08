/*
David Valleau - 2014
Eul-tility is a C++ header file used to aid in the solutions on project Euler,
or really any math related questions whatsoever.
*/

#ifndef __EULTILITY_H_INCLUDED__
#define __EULTILITY_H_INCLUDED__

int gcd(int a, int b); //determine the greatest common divisor of a and b

int num_len(int n);  // determine the amount of digits in a number
int num_len(int64_t n);

// ----------Functions for figurate (polygonal) numbers----------
int tri_num(int n);
int squ_num(int n);
int pent_num(int n);
int hex_num(int n);
int hept_num(int n);
int oct_num(int n);

int reverse_num(int n);  // rerverse the contents of a number
int sum_digits(int n);  // return the sum of the digits of n

bool is_permutation(int a, int b);  // determine if b is a permutation of a
bool is_palindrome(int n);
bool pandig_n(int a, int n);  // determine if a is 1-to-n pandigital
bool pandig_9(int n);

int num_divisors(int n);

bool is_prime(int n);

int gcd(int a, int b) {
    if (a == 1 || b == 1) return 1;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int num_len(int n) {
    int len = 1;
    int cap = 10;
    while (n > cap) {
        cap *= 10;
        ++len;
    }
    return len;
}

int num_len(int64_t n) {
    int len = 1;
    int64_t cap = 10;
    while (n > cap) {
        cap *= 10;
        ++len;
    }
    return len;
}

int tri_num(int n) {
    if (n > 65000)  // rough estimate of value that would cause overflow
        return -1;
    return n * (n + 1) / 2;
}

int squ_num(int n) {
    if (n > 46340)  // rough estimate of value that would cause overflow
        return -1;
    return n * n;
}

int pent_num(int n) {
    if (n > 37500)  // rough estimate of value that would cause overflow
        return -1;
    return n * (3 * n - 1) / 2;
}

int hex_num(int n) {
    if (n > 32500)
        return -1;
    return n * (2 * n - 1);
}

int hept_num(int n) {
    if (n > 29000)
        return -1;
    return n * (5 * n - 3) / 2;
}

int oct_num(int n) {
    if (n > 26000)
        return -1;
    return n * (3 * n - 2);
}

int reverse_num(int n) {
    int rev = 0;
    while (n > 0) {
        rev = (10 * rev) + (n % 10);
        n /= 10;
    }
    return rev;
}

int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_permutation(int a, int b) {
    if (num_len(a) != num_len(b))
        return false;
    int occur[10];
    for (int i = 0; i < 10; ++i)
        occur[i] = 0;
    while (a > 0) {
        ++occur[a%10];
        --occur[b%10];
        a /= 10;
        b /= 10;
    }
    for (int i = 0; i < 10; ++i) {
        if (occur[i] != 0)
            return false;
    }
    return true;
}

bool is_palindrome(int n) {
    return n == reverse_num(n);
}

// TODO(DavieV): make this shit cleaner
bool pandig_n(int a, int n) {
    int occur[10];
    for (int i = 0; i < 10; ++i)
        occur[i] = 0;
    while (a > 0) {
        ++occur[a%10];
        a /= 10;
    }
    if (occur[0] != 0)
        return false;
    for (int i = 1; i < 10; ++i) {
        if (occur[i] == 1) {
            if (i > n)
                return false;
        } else {
            if (i <= n)
                return false;
        }
    }
    return true;
}

bool pandig_9(int n) {
    int occur[10];
    for (int i = 0; i < 10; ++i)
        occur[i] = 0;
    int c = 0;
    while (n > 0) {
        if (n % 10 == 0) return false;
        if (occur[n % 10] == 0) {
            occur[n % 10]++;
            c++;
        } else {
            return false;
        }
        n /= 10;
    }
    return c == 9;
}

int num_divisors(int n) {
    int c = 2;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i * i == n)
                ++c;
            else
                c += 2;
        }
    }
    return c;
}

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

#endif
