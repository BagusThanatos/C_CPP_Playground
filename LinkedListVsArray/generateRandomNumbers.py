import random

with open("randomNumbers.txt", "wt") as f:
    f.write("100000")
    for i in range(100000):
        f.write("\n")
        f.write(str(random.randint(1,1000000)))
