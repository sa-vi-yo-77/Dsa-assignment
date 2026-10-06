# Conclusion

Both K-way Min Heap merging and pairwise merging correctly produce the sorted transaction sequence:

10 15 20 30 35 40 50 55 60 70 75 80

For the given three lists, the simple pairwise approach performs 18 element comparisons, while the K-way Min Heap implementation performs 19 key comparisons and 9 heap swaps.

Therefore, pairwise merging is slightly smaller in operation count for this particular small input.

However, the main goal is to choose an approach that works well when the number of sorted files increases. K-way merging with a Min Heap has O(N log k) time complexity and O(k) auxiliary heap space. It maintains one active element from each list instead of repeatedly merging large intermediate results.

Hence, **K-way merge using a Min Heap is the recommended approach for merging a large number of sorted files or transaction streams.**
