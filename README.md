# K-Way Merge Using Min Heap and Pairwise Merge

## DSA Assignment

### Problem
A financial system receives three already sorted transaction lists:

- L1 = 10, 30, 50, 70
- L2 = 20, 40, 60, 80
- L3 = 15, 35, 55, 75

The task is to:
1. Represent the lists using suitable data structures.
2. Implement K-way merge using a Min Heap.
3. Show important heap states during execution.
4. Implement simple pairwise merging.
5. Compare the two approaches.
6. Analyze time and space complexity.
7. Determine the better approach when the number of sorted files increases.

## Data Structure
The three sorted lists are represented using C integer arrays. The K-way merge uses a Min Heap containing one current element from each list. Each heap node stores:
- value
- source list number
- index of the element in that list

## Algorithms

### K-way merge using Min Heap
1. Insert the first element of every sorted list into the Min Heap.
2. Remove the minimum element from the heap.
3. Add it to the merged output.
4. Insert the next element from the same source list.
5. Repeat until the heap becomes empty.

### Pairwise merge
1. Merge L1 and L2.
2. Merge the result with L3.
3. The final array is the sorted result.

## Input
The input is stored in `input/input.txt`.

## Expected Output
Both methods produce:

`10 15 20 30 35 40 50 55 60 70 75 80`

## Execution Results
For the given implementation and input:

- K-way Min Heap: 19 key comparisons and 9 heap swaps.
- Pairwise merge: 18 element comparisons.
- The small test case has nearly equal operation counts.
- For a large number of sorted files, K-way merge with a Min Heap is more suitable because its time complexity is O(N log k), where N is the total number of elements and k is the number of sorted lists.

## Complexity
| Method | Time Complexity | Extra Working Space |
|---|---|---|
| K-way Min Heap | O(N log k) | O(k) |
| Pairwise merge | O(Nk) for simple sequential merging in the worst case | O(N) for intermediate result |

## Conclusion
For the given three small lists, pairwise merging performs slightly fewer element comparisons. However, when the number of sorted files increases, K-way merging using a Min Heap is the better and more scalable approach.
