import random
import os

random.seed(1532005)

random.seed(os.urandom(128))

test = []
for i in range(10):
    test.append([])
    test[i] = [random.randint(-(10 ** 9), 10 ** 9) / 100 for _ in range(10 ** 6)]

test[0] = sorted(test[0])
test[1] = sorted(test[1], reverse=True)

for i in range(10):
    print(i)
    f = open(f"test{i + 1}.inp", "w")
    for j in range(10 ** 6):
        f.write(str(test[i][j]) + " ")

    f.close()
