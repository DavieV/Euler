#Simple script to convert the text file into a simpler format
line = open("problem98.txt").readline()
words = line.split(",")

for word in words:
    word = word.replace('"', '').strip()
    print word