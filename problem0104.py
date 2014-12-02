def first_nine(x):
    if len(x) < 18:
        return False
    occur = [0] * 10
    for i in range(0, 9):
        occur[int(x[i])] += 1
    if occur[0] != 0:
        return False
    for i in range(1, 10):
        if occur[i] != 2:
            return False
    return True

def last_nine(x):
    if len(x) < 18:
        return False
    occur = [0] * 10
    for i in range(0, 9):
        occur[int(x[len(x)-1-i])] += 1
    if occur[0] != 0:
        return False
    for i in range(1, 10):
        if occur[i] != 2:
            return False
    return True

prev1 = 1
prev2 = 1
cur = 2
term = 3
while first_nine(str(cur)) == False or last_nine(str(cur)) == False:
    prev2 = prev1
    prev1 = cur
    cur = prev1 + prev2
    term += 1
print term