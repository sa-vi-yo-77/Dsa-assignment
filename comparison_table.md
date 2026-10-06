# Algorithm Comparison Table

| Feature | K-way Merge with Min Heap | Simple Pairwise Merge |
|---|---|---|
| Main data structure | Min Heap | Arrays |
| Number of active elements | At most k | Depends on intermediate result |
| Given-input comparisons | 19 key comparisons | 18 element comparisons |
| Swaps | 9 heap swaps | Not required |
| Time complexity | O(N log k) | O(Nk) for simple sequential merging |
| Extra working space | O(k) heap | O(N) intermediate result |
| Suitable for many sorted files | Yes | Less suitable |
| Implementation | Slightly more complex | Simple |
| Scalability | High | Lower for sequential merging |
| Best use | Many sorted files/streams | Small number of sorted arrays |

## Important observation

For the given small input, pairwise merging uses slightly fewer element comparisons. However, the K-way Min Heap approach scales better when k, the number of sorted files, becomes large.
