from random import randint
import time

start_time = time.time()

import sys
sys.setrecursionlimit(1500)
depth = 0
compare = 0
swap = 0

def quick_sort(sequince, lo_index=None, hi_index=None):
    global depth
    depth += 1
    if lo_index is None:
        lo_index = 0
    if hi_index is None:
        hi_index = len(sequince)-1
    if lo_index >= hi_index:
        return None
    h = partition(sequince, lo_index, hi_index)
    quick_sort(sequince, lo_index, h-1)
    quick_sort(sequince, h+1, hi_index)


def partition(sequince, lo_index, hi_index):
    global compare
    global swap
    support_element = sequince[lo_index]
    i = lo_index + 1
    j = hi_index
    while True:
        while i < hi_index and sequince[i] < support_element:
            i += 1
            compare += 1
        while sequince[j] > support_element:
            j -= 1
            compare += 1
        if i >= j:
            compare += 1
            break
        sequince[i], sequince[j] = sequince[j], sequince[i]
        i += 1
        j -= 1
    sequince[lo_index], sequince[j] = sequince[j], sequince[lo_index]
    swap += 1
    return j


sequince = []
num = 1000
for k in range(num):
    sequince.append(num - k)

#print("Initial list: ", sequince)

quick_sort(sequince, depth)

#print("Result list: ", sequince)
print("Recursive depth: ", depth)
print("Swap: ", swap)
print("Compare: ", compare)
print("--- %s seconds ---" % (time.time() - start_time))