# Dijkstra's Algorithm for Single Source Shortest Path

Last updated: 03/06/2019

Given a starting node in a weighted, directed graph with nonnegative weights only, visit every connected node and determine the minimum distance to each such node. Optionally, output the shortest path to a specific destination node using the shortest-path tree from the predecessor array `pred[]`. `dijkstra()` applies to a global, pre-populated adjacency list `adj[]` which must only consist of nodes numbered with integers between 1 (inclusive) and the total number of nodes (inclusive).

Since the default sorting criterion of `set` is non-decreasing, we can simulate a min-heap by picking the iterator to the first element in the container.

Dijkstra's algorithm may be modified to support negative edge weights by allowing nodes to be re-visited (removing the erase on the relaxation step). This is known as the Shortest Path Faster Algorithm (SPFA), which has a larger running time of $O(nm)$ on the number of nodes and edges respectively. While it is as slow in the worst case as the Bellman-Ford algorithm, the SPFA still tends to outperform in the average case.

## Variables

- `n`: number of nodes.
- `m`: number of edges.
- `vector <int> adj[]`: 1-indexed graph adjacency list.
- `dist[]`: array containing the distance from source node to each node, after running `dijkstra()`.
- `pred[]`: array containing the predecessor for each node, after running `dijkstra()`.

## Time Complexity

- $O(n\log{}m)$ for `dijkstra()`.
- $O(n)$ for `getPath()`.

## Space Complexity

- $O(n+m)$ for storage of the graph.
- $O(n)$ auxiliary space.

## Validation

| Online Judge | Problem Name               | Submission ID |
| ------------ | -------------------------- | ------------- |
| SPOJ         | [Easy Dijkstra Problem][1] | 23870017      |

[1]: https://cp-algorithms.com/graph/dijkstra_sparse.html

## References

- [A3C5](https://github.com/alxli/Algorithm-Anthology/blob/master/Section-2-Graph-Theory/2.2.2%20Shortest%20Path%20(Dijkstra's).cpp)
- [CP-Algorithms](https://cp-algorithms.com/graph/dijkstra_sparse.html)
