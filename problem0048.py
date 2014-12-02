s = 0
for i in range(1, 1001):
    s += i ** i
print s % 10 ** 10

print sum(map(lambda x: x ** x, range(1, 1001))) % 10 ** 10 