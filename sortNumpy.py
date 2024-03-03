import numpy as np
from timeit import default_timer as time

print("[Sort Numpy] Running...")

numpySort = []

for i in range(10):
    ar = [_ for _ in open(f"./Testcase/test{i + 1}.inp").read().split()]
    ar = np.array(ar, dtype=float)
    start = time()
    ar = np.sort(ar)
    timer = (time() - start) * 1000
    numpySort.append(timer)
    print(f"Test {i + 1}: {timer:.2f} ms")

print(f"Average: {sum(numpySort) / 10:.2f} ms")

f = open("out.py", "w")
f.write(f"{numpySort = }\n")