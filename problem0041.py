import math

def my_range(start, end, step):
    while start <= end:
        yield start
        start += step

def is_prime(x):
    if x % 2 == 0:
        return False
    cap = math.sqrt(x)
    for i in my_range(3, cap, 2):
        if x % i == 0:
            return False
    return True

def is_pandigital(x, s):
    digits = []
    for i in range(1, s+1):
        digits.append(i)
    for i in range(s):
        if x % 10 in digits:
            digits.remove(x % 10)
        else:
            return False
        x /= 10
    return digits == []

def sieve_for_primes_to(n):
    size = n//2
    sieve = [1]*size
    limit = int(n**0.5)
    for i in range(1,limit):
        if sieve[i]:
            val = 2*i+1
            tmp = ((size-1) - i)//val 
            sieve[i+val::val] = [0]*tmp
    return sieve

m = 0
s = 1

'''
for i in range(1, 10000000):
    if i >= 10 ** s:
        s+=1
    if is_prime(i) and is_pandigital(i, s):
        print i
        m = i
print m
'''
