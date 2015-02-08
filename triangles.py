lines = open("triangles.txt").readlines()

for line in lines:
    print line.strip('\n').replace(',', ' ')