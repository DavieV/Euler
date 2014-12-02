def sumDigits(x):
    s = 0
    while x > 0:
        s += x % 10
        x /= 10
    return s

m = 0
for i in range(1, 101):
    for j in range(1, 101):
        m = max(m, sumDigits(i ** j))
print m
