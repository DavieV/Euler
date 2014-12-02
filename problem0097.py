num = 2
for i in range(1, 7830457):
    num = (num * 2) % (10 ** 10)
num = (num * 28433) + 1
print num % (10 ** 10)
