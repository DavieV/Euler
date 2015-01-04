def gcd(m, n):
    if n == 0:
        return m
    return gcd(n, m % n)

def A(n):
    if (gcd(n, 10) != 1):
        return -1
    rem = 1
    k = 1
    while rem != 0:
        rem = (10 * rem + 1) % n
        k += 1
    return k

n = 1000000
while A(n) < 1000000:
    n += 1

print n