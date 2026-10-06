# K-Way Merge Trace Table

Initial Min Heap contains the first element from each list: 10, 20, 15.

| Step | Removed minimum | Next element inserted | Heap after operation |
|---:|---:|---:|---|
| 0 | — | 10, 20, 15 | 10, 20, 15 |
| 1 | 10 | 30 | 15, 20, 30 |
| 2 | 15 | 35 | 20, 30, 35 |
| 3 | 20 | 40 | 30, 35, 40 |
| 4 | 30 | 50 | 35, 40, 50 |
| 5 | 35 | 55 | 40, 50, 55 |
| 6 | 40 | 60 | 50, 55, 60 |
| 7 | 50 | 70 | 55, 60, 70 |
| 8 | 55 | 75 | 60, 70, 75 |
| 9 | 60 | 80 | 70, 75, 80 |
| 10 | 70 | — | 75, 80 |
| 11 | 75 | — | 80 |
| 12 | 80 | — | Empty |

## Final merged sequence

10, 15, 20, 30, 35, 40, 50, 55, 60, 70, 75, 80

## Operation record

- Key comparisons: 19
- Heap swaps: 9
