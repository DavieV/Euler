import math

def is_prime(x):
    if x % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(x))):
        if x % i == 0:
            print i
            return False
    return True

print is_prime(2433601)