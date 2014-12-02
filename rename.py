#rename each file so that appears in order on github

import os

def pad_zeroes(x):
    return "0" * (4 - len(x)) + x

for filename in os.listdir("."):
    if filename.startswith("problem"):
        if filename.endswith(".cpp") or filename.endswith(".py"):
            num = filename.split("problem")[1].split(".")[0]
            ext = filename.split("problem")[1].split(".")[1]
            os.rename(filename, "problem" + pad_zeroes(num) + "." + ext)