'''
Determines the fractional expansion of root of up to x cycles.
It the compares the number of digits in the numerator and denominator
and returns True if the numerator has more digits
'''
def valid_fraction(x):
    n = 1
    d = 2
    for i in range(1, x):
        n += 2 * d
        tmp = n
        n = d
        d = tmp
    n += d
    return num_len(n) > num_len(d) 

# simply determines the length of a number (amount of digits)
def num_len(n):
    cap = 10
    length = 0
    while n > cap:
        cap *= 10
        length += 1
    return length

count = 0
for i in range(0, 1000):
    if valid_fraction(i) == True:
        count += 1

print count