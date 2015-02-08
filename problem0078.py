def piles(x):
    sums = [0] * (x+1)
    sums[0] = 1
    for i in range(1, x):
        for j in range(i, x+1):
            sums[j] += sums[j-i]

    print sums[x]

piles(1000)