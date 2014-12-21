def sum_digits(n):
    s = 0
    while n > 0:
        s += n % 10
        n /= 10
    return s

nums = []
for i in range(2, 100):
    for j in range(2, 100):
        if i == sum_digits(i ** j):
            nums.append(i ** j)

nums.sort()

print nums[29]