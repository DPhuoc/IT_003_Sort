import os
import numpy as np 
import out
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd
import statistics

# os.system('python3 sortNumpy.py')
# sortinC = ['quicksort', 'mergesort', 'heapsort', 'sortc++']
# for i in sortinC:
#     os.system(f'g++ {i}.cpp -o {i} && ./{i} && rm {i}')

numpySort = out.numpySort
quickSort = out.quickSort
mergeSort = out.mergeSort
heapSort = out.heapSort
cppSort = out.cppSort
for i in cppSort:
    print(i)
print(statistics.mean(cppSort))

Testcase = [_ % 10 + 1 for _ in range(50)]
Time = [numpySort, quickSort, mergeSort, heapSort, cppSort]
Time = [item for sublist in Time for item in sublist]
Algorithms = ['sort (Numpy)'] * 10 + ['Quicksort'] * 10 + ['Mergesort'] * 10 + ['Heapsort'] * 10 + ['sort (C++)'] * 10

# export to csv
df = pd.DataFrame({'Testcase': Testcase, 'Time': Time, 'Algorithms': Algorithms})
df.to_csv('data.csv', index=False)
palette = ['#629fcb', '#ffa556', '#6bbd6b', '#e36968', "#8f79d8"]

sns.set(style="whitegrid")
ax = sns.catplot(
    x='Testcase', y='Time', hue='Algorithms',
    data=df, kind='bar',
    height=5, aspect=2,
    palette=palette,
)
ax.set(xlabel='Testcase', ylabel='Time (s)')

# save plot

plt.savefig('graph.png')

