from random import randint


def quick_sort(sequence, depth=None, lo_index=None, hi_index=None):
    global recursive
    recursive = depth
    if lo_index is None:
        lo_index = 0
    if hi_index is None:
        hi_index = len(sequence) - 1
    if lo_index >= hi_index:
        return None
    h = partition(sequence, lo_index, hi_index)
    quick_sort(sequence, depth + 1, lo_index, h - 1)
    quick_sort(sequence, depth + 1, h + 1, hi_index)


def partition(sequence, lo_index, hi_index):
    support_element = sequence[lo_index]
    i = lo_index + 1
    j = hi_index
    while True:
        while i < hi_index and sequence[i] < support_element:
            i += 1
        while sequence[j] > support_element:
            j -= 1
        if i >= j:
            break
        sequence[i], sequence[j] = sequence[j], sequence[i]
        i += 1
        j -= 1
    sequence[lo_index], sequence[j] = sequence[j], sequence[lo_index]
    return j


recursive = 0
sequence = []
num = 1000
for k in range(num):
    sequence.append(randint(0, num - 1))
print("Initial list: ", sequence)
depth = 0
quick_sort(sequence, depth)
print("Result list: ", sequence)
print("Recursive depth: ", recursive)