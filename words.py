line = open("words.txt").readline()
names = line.split(",")

for name in names:
	name = name.replace('"', '').strip()
	print name