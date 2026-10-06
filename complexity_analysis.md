# Complexity Analysis

Let:
- N = total number of elements in all sorted lists.
- k = number of sorted lists.
- Each list is already sorted.

## 1. K-way Merge Using Min Heap

At any time the Min Heap contains at most one current element from each of the k lists.

For every output element:
- Remove the minimum from the heap.
- Insert the next element from the same list when available.

Each heap operation takes O(log k) time.

Therefore:

**Time Complexity = O(N log k)**

The heap stores at most k elements:

**Auxiliary Space = O(k)**

If the complete merged output is stored in memory, O(N) output space is also required.

## 2. Pairwise Merge

For this implementation, L1 is merged with L2 first and that result is then merged with L3.

For k lists, sequential pairwise merging can repeatedly process a growing intermediate result. In the worst case this gives:

**Time Complexity = O(Nk)**

The intermediate merged array can require:

**Auxiliary Space = O(N)**

A balanced pairwise merge tree can achieve O(N log k), but the simple sequential pairwise method used in this assignment is less scalable.

## Given Example

K-way Min Heap:
- Key comparisons = 19
- Heap swaps = 9

Pairwise:
- First merge comparisons = 7
- Second merge comparisons = 11
- Total comparisons = 18

The pairwise method performs one fewer element comparison for this small input. This does not mean it is more scalable for a large number of sorted files.

## Scalability

As k increases, the K-way Min Heap keeps only k active elements and processes each output element with O(log k) heap work. This makes it a standard choice for merging many sorted files or streams.
