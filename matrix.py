lines = open("matrix.txt").readlines()

for line in lines:
	nums = line.split(",")
	for num in nums:
		print num