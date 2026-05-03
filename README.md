# Algorithm Design and Analysis — Lab (Sem 4)

> **Language:** C++ | **Subject:** Algorithm Design and Analysis (ADA)
> A complete week-wise collection of ADA lab programs with pseudocode, variable descriptions, complexity analysis, and use cases.

---

## Table of Contents

- [Week 1 — Brute Force & Recursion Fundamentals](#week-1--brute-force--recursion-fundamentals)
- [Week 2 — Searching & Sorting (Basic)](#week-2--searching--sorting-basic)
- [Week 3 — Divide and Conquer Sorting](#week-3--divide-and-conquer-sorting)
- [Week 4 — Greedy & Matrix Algorithms](#week-4--greedy--matrix-algorithms)
- [Week 5 — Greedy Graphs & MST](#week-5--greedy-graphs--mst)
- [Week 6 — Dynamic Programming on Graphs](#week-6--dynamic-programming-on-graphs)
- [Week 7 — Multistage DP & Matrix Chain](#week-7--multistage-dp--matrix-chain)
- [Week 8 — Advanced Dynamic Programming](#week-8--advanced-dynamic-programming)
- [Week 9 — DP Revisited & All-Pairs Shortest Path](#week-9--dp-revisited--all-pairs-shortest-path)
- [Week 10 — Backtracking](#week-10--backtracking)

---

## Week 1 — Brute Force & Recursion Fundamentals

### Program 1: Velocity / Ball Bounce (velocity.cpp)

**Aim**
To calculate the number of times a ball will bounce until its velocity drops below a minimum threshold using recursion.

**Pseudocode**
```
ALGO CountBounces(velocity):
    IF velocity < 1.0:
        RETURN 0
    reducedVelocity ← velocity × 0.575
    RETURN 1 + CountBounces(reducedVelocity)
```

**Variables Used**

| Variable | Description |
|---|---|
| `velocity` | Current velocity of the ball |
| `reducedVelocity` | Velocity after one bounce (energy loss) |
| `1.0` | Minimum threshold to stop bouncing |

**Algorithm Explanation**
The ball loses a fixed fraction of velocity (57.5%) on each bounce. The function recurses until velocity drops below 1.0, counting one bounce per call. When the base case is hit, the count unwinds back to the caller.

**Time Complexity:** O(log n) — velocity reduces exponentially each call.

**Space Complexity:** O(log n) — recursion stack depth equals bounce count.

---

### Program 2: Iterative Power Calculation (iterative_power_calculation.cpp)

**Aim**
To compute the power of a number iteratively and measure its time performance.

**Pseudocode**
```
ALGO ComputePower(base, exp):
    result ← 1
    FOR i ← 0 TO exp - 1:
        result ← result × base
    RETURN result
```

**Variables Used**

| Variable | Description |
|---|---|
| `base` | The base number |
| `exp` | The exponent/power |
| `result` | Accumulated product |
| `i` | Loop counter |

**Algorithm Explanation**
Multiplies base by itself `exp` times using a simple loop. Straightforward but inefficient for large exponents since every multiplication step is performed individually.

**Time Complexity:** O(n) — one multiplication per exponent unit.

**Space Complexity:** O(1) — no extra memory used.

---

### Program 3: Recursive Fast Power (Recursion_power_calculation.cpp)

**Aim**
To compute power of a number efficiently using Divide and Conquer recursion.

**Pseudocode**
```
ALGO FastPower(base, exp):
    IF exp == 0:
        RETURN 1
    result ← FastPower(base, exp / 2)
    IF exp % 2 == 0:
        RETURN result × result
    ELSE:
        RETURN base × result × result
```

**Variables Used**

| Variable | Description |
|---|---|
| `base` | The base number |
| `exp` | The exponent |
| `result` | Stores sub-problem result |

**Algorithm Explanation**
Instead of multiplying one at a time, the exponent is halved at every recursive call. For even exponents, result is squared. For odd exponents, an extra multiply by base is added. This reduces the total operations drastically.

**Time Complexity:** O(log n) — exponent halved each call.

**Space Complexity:** O(log n) — recursion stack depth.

**Use Cases**
- Cryptographic key generation (RSA, DH key exchange) where modular exponentiation with large numbers is required.
- Computer graphics for fast matrix power operations.

---

### Program 4: Horner's Rule for Polynomial Evaluation (Horners_Rule.cpp)

**Aim**
To evaluate a polynomial of degree n at a given point x efficiently using Horner's method.

**Pseudocode**
```
ALGO HornerEvaluation(coeff[], degree, x):
    value ← coeff[degree]
    FOR i ← degree - 1 DOWNTO 0:
        value ← value × x + coeff[i]
    RETURN value
```

**Variables Used**

| Variable | Description |
|---|---|
| `coeff[]` | Array of polynomial coefficients |
| `degree` | Degree of the polynomial |
| `x` | Point at which polynomial is evaluated |
| `value` | Running evaluated result |
| `i` | Loop counter from degree−1 downto 0 |

**Algorithm Explanation**
Horner's method rewrites the polynomial to avoid redundant multiplications. Instead of computing each power separately, it processes coefficients from highest to lowest degree, multiplying by x and adding the next coefficient at each step. This reduces multiplications from O(n²) to O(n).

**Time Complexity:** O(n) — one pass through all coefficients.

**Space Complexity:** O(1) — constant extra space.

**Use Cases**
- Scientific computing and simulation engines where polynomial functions are evaluated millions of times per second.
- Signal processing filters that evaluate transfer functions in real time.

---

### Program 5: Linear Search (Linear_Search.cpp)

**Aim**
To search for a target element in an unsorted array by checking each element sequentially.

**Pseudocode**
```
ALGO LinearSearch(arr[], n, key):
    FOR i ← 0 TO n - 1:
        IF arr[i] == key:
            RETURN i
    RETURN -1
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Input array |
| `n` | Size of the array |
| `key` | Element to search for |
| `i` | Current index being compared |

**Algorithm Explanation**
Each element is compared against the key from index 0. The search terminates on a match (returning the index) or after all elements are checked (returning −1). Worst case occurs when the element is absent.

**Time Complexity:** Best O(1), Worst O(n).

**Space Complexity:** O(1).

**Use Cases**
- Searching in small, unsorted datasets where sorting overhead is not justified.
- Looking up a record in a sequential file or log where random access is unavailable.

---

### Program 6: Missing Number in Consecutive Array (Missing_number.cpp)

**Aim**
To find the single missing number from a sequence of nearly consecutive integers.

**Pseudocode**
```
ALGO FindMissing(arr[], n):
    FOR i ← 1 TO n - 1:
        IF arr[i] ≠ arr[i - 1] + 1:
            RETURN arr[i - 1] + 1
    RETURN arr[n - 1] + 1
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Sorted input array with one number missing |
| `n` | Size of the array |
| `i` | Loop index |

**Algorithm Explanation**
The array is traversed and each adjacent pair is checked. If the difference between consecutive elements is not exactly 1, the missing number is the expected successor of the left element. If no break is found, the missing number comes after the last element.

**Time Complexity:** O(n) — single pass.

**Space Complexity:** O(1).

**Use Cases**
- Data integrity checks in sequential ID systems (employee IDs, invoice numbers).
- Detecting packet loss in ordered network streams.

---

### Program 7: String Permutations (Permuations.cpp)

**Aim**
To generate all permutations of a given string of length n using backtracking recursion.

**Pseudocode**
```
ALGO GeneratePermutations(s, index):
    IF index == length(s):
        RETURN   (one permutation complete)
    FOR i ← index TO length(s) - 1:
        SWAP s[index] ↔ s[i]
        GeneratePermutations(s, index + 1)
        SWAP s[index] ↔ s[i]   (backtrack)
```

**Variables Used**

| Variable | Description |
|---|---|
| `s` | Input string (modified in place) |
| `index` | Current fixed position |
| `i` | Iterator over remaining positions |

**Algorithm Explanation**
One character is fixed at position `index` by swapping it with each character from `index` onward. The function then recurses on the remaining suffix. After the recursive call, the swap is undone (backtracking), restoring the string before trying the next character.

**Time Complexity:** O(n!) — total permutations.

**Space Complexity:** O(n) — recursion stack depth.

**Use Cases**
- Brute-force password cracking tools and wordlist generators.
- Anagram detection in NLP and word puzzle engines.

---

### Program 8: Binary String Generation (Binary_string_generation.cpp)

**Aim**
To generate all 2ⁿ binary strings of length n using recursion.

**Pseudocode**
```
ALGO GenerateBinary(s, pos, n):
    IF pos == n:
        RETURN
    s[pos] ← '0'
    GenerateBinary(s, pos + 1, n)
    s[pos] ← '1'
    GenerateBinary(s, pos + 1, n)
```

**Variables Used**

| Variable | Description |
|---|---|
| `s` | String being built character by character |
| `pos` | Current bit position |
| `n` | Total length of the binary string |

**Algorithm Explanation**
At every position, two choices exist: '0' or '1'. The function explores both branches recursively. Each leaf of the recursion tree represents a complete binary string. Total strings generated equals 2ⁿ.

**Time Complexity:** O(2ⁿ) — one call per binary string.

**Space Complexity:** O(n) — recursion depth equals string length.

**Use Cases**
- Truth table generation for boolean expressions in logic design.
- Generating feature flag combinations for A/B testing systems.

---

### Program 9: Sum of Arrays (Sum_of_Arrays.cpp)

**Aim**
To compute the sum of all elements in an array iteratively and benchmark its time performance.

**Pseudocode**
```
ALGO ComputeSum(arr[], n):
    total ← 0
    FOR i ← 0 TO n - 1:
        total ← total + arr[i]
    RETURN total
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Input array of integers |
| `n` | Size of the array |
| `total` | Accumulator for running sum |
| `i` | Loop counter |

**Algorithm Explanation**
A straightforward linear scan accumulates all array elements into a running total. This serves as a baseline O(n) benchmark for comparison with more complex algorithms.

**Time Complexity:** O(n).

**Space Complexity:** O(1).

---

### Program 10: Towers of Hanoi (Towers_of_Hanoi.cpp)

**Aim**
To solve the classic Tower of Hanoi puzzle for n disks using recursion.

**Pseudocode**
```
ALGO SolveHanoi(n, source, destination, helper):
    IF n == 0:
        RETURN
    SolveHanoi(n - 1, source, helper, destination)
    // Move disk n from source to destination
    SolveHanoi(n - 1, helper, destination, source)
```

**Variables Used**

| Variable | Description |
|---|---|
| `n` | Number of disks |
| `source` | Rod from which disks are moved |
| `destination` | Target rod |
| `helper` | Auxiliary rod used during transfer |

**Algorithm Explanation**
The top n−1 disks are moved from source to helper, the nth (largest) disk moves directly to destination, then the n−1 disks follow from helper to destination. This yields a total of 2ⁿ − 1 moves.

**Time Complexity:** O(2ⁿ) — doubles with each additional disk.

**Space Complexity:** O(n) — recursion stack depth.

**Use Cases**
- Demonstrating exponential blow-up in recursive algorithms.
- Used conceptually in backup rotation schemes (grandfather-father-son strategy).

---

### Program 11: Truth Table / Subset Generation (truth_table.cpp)

**Aim**
To generate all 2ⁿ subsets of a set of size n using recursive state toggling.

**Pseudocode**
```
ALGO GenerateSubsets(index, size, state[]):
    IF index == size:
        COUNT++   (process subset)
        RETURN
    state[index] ← true
    GenerateSubsets(index + 1, size, state)
    state[index] ← false
    GenerateSubsets(index + 1, size, state)
```

**Variables Used**

| Variable | Description |
|---|---|
| `index` | Current element being decided (include/exclude) |
| `size` | Total number of elements |
| `state[]` | Boolean array tracking inclusion |
| `counter` | Counts subsets processed |

**Algorithm Explanation**
Each element independently takes on true (included) or false (excluded). The binary decision tree has 2ⁿ leaves, each representing a unique subset. This is equivalent to generating all rows of an n-variable truth table.

**Time Complexity:** O(2ⁿ).

**Space Complexity:** O(n).

---

## Week 2 — Searching & Sorting (Basic)

### Program 1: Binary Search (Binary_search.cpp)

**Aim**
To search for a key element in a sorted array by repeatedly halving the search space.

**Pseudocode**
```
ALGO BinarySearch(arr[], left, right, key):
    IF left > right:
        RETURN -1
    mid ← left + (right - left) / 2
    IF arr[mid] == key:
        RETURN mid
    ELSE IF arr[mid] > key:
        RETURN BinarySearch(arr, left, mid - 1, key)
    ELSE:
        RETURN BinarySearch(arr, mid + 1, right, key)
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Sorted input array |
| `left` | Left boundary of current search window |
| `right` | Right boundary of current search window |
| `key` | Target element to search |
| `mid` | Middle index of current window |

**Algorithm Explanation**
At each step, the middle element is compared to the key. If they match, the index is returned. If the key is smaller, the right half is discarded; if larger, the left half is discarded. This continues until found or the window collapses.

**Time Complexity:** Best O(1), Average/Worst O(log n).

**Space Complexity:** O(log n) — recursive call stack.

**Use Cases**
- Database indexing engines (B-tree lookups at each level).
- Dictionary and spell-checker word lookups.

---

### Program 2: Insertion Sort (Insertion_sort.cpp)

**Aim**
To sort an array by inserting each element into its correct position within the already-sorted portion.

**Pseudocode**
```
ALGO InsertionSort(arr[], n):
    FOR i ← 1 TO n - 1:
        key ← arr[i]
        j ← i - 1
        WHILE j >= 0 AND arr[j] > key:
            arr[j + 1] ← arr[j]
            j ← j - 1
        arr[j + 1] ← key
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Input array |
| `n` | Size of the array |
| `key` | Element being inserted into sorted portion |
| `i` | Outer loop — current element index |
| `j` | Inner loop — shifts elements rightward |

**Algorithm Explanation**
The array is conceptually split into a sorted left portion and unsorted right portion. In each pass, the first element of the unsorted portion is picked as `key` and shifted leftward past all sorted elements that are greater than it, opening its correct slot.

**Time Complexity:** Best O(n) (already sorted), Worst O(n²) (reverse sorted).

**Space Complexity:** O(1).

**Use Cases**
- Online sorting where elements arrive one at a time and must stay sorted.
- Sorting small arrays (n < 20) where its low overhead beats O(n log n) algorithms.

---

## Week 3 — Divide and Conquer Sorting

### Program 1: Merge Sort (Merge_sort.cpp)

**Aim**
To sort an array using the Divide and Conquer paradigm by recursively splitting and merging.

**Pseudocode**
```
ALGO MergeSort(arr[], left, right):
    IF left >= right:
        RETURN
    mid ← left + (right - left) / 2
    MergeSort(arr, left, mid)
    MergeSort(arr, mid + 1, right)
    Merge(arr, left, mid, right)

ALGO Merge(arr[], left, mid, right):
    i ← left, j ← mid + 1
    WHILE i ≤ mid AND j ≤ right:
        IF arr[i] ≤ arr[j]:
            temp.push(arr[i++])
        ELSE:
            temp.push(arr[j++])
    Copy remaining elements
    Copy temp back to arr[left..right]
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Array to sort |
| `left`, `right` | Current subarray boundaries |
| `mid` | Midpoint index |
| `i`, `j` | Pointers for left and right halves during merge |
| `temp` | Temporary array for merging |

**Algorithm Explanation**
The array is recursively halved until single elements remain (base case). On the way back up the call stack, adjacent sorted halves are merged using two-pointer technique, comparing elements one by one and placing the smaller first.

**Time Complexity:** O(n log n) — all cases.

**Space Complexity:** O(n) — temporary array used during merge.

**Use Cases**
- External sorting of large datasets that don't fit in RAM (merge-based disk sorting).
- Stable sorting requirement: relative order of equal elements is preserved.

---

### Program 2: Quick Sort (Quick_sort.cpp)

**Aim**
To sort an array in place using a pivot-based partitioning strategy.

**Pseudocode**
```
ALGO QuickSort(arr[], low, high):
    IF low < high:
        p ← Partition(arr, low, high)
        QuickSort(arr, low, p - 1)
        QuickSort(arr, p + 1, high)

ALGO Partition(arr[], low, high):
    pivot ← arr[low]
    i ← low
    FOR j ← low + 1 TO high:
        IF arr[j] ≤ pivot:
            i++
            SWAP arr[i] ↔ arr[j]
    SWAP arr[low] ↔ arr[i]
    RETURN i
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Array to sort |
| `low`, `high` | Current partition boundaries |
| `pivot` | Chosen pivot element (first element) |
| `i` | Tracks last position of elements ≤ pivot |
| `j` | Scans array from left to right |
| `p` | Final partition index after placement |

**Algorithm Explanation**
A pivot is placed at its correct sorted position by rearranging all smaller elements to its left and all larger elements to its right. The algorithm then recursively sorts each side. The first element is chosen as pivot here (susceptible to worst case on sorted input).

**Time Complexity:** Best/Average O(n log n), Worst O(n²) (sorted input with first-element pivot).

**Space Complexity:** O(log n) — stack space for recursion.

**Use Cases**
- In-memory sorting of large datasets where cache performance matters (better locality than merge sort).
- Default sort algorithm in many standard libraries (introsort variant).

---

## Week 4 — Greedy & Matrix Algorithms

### Program 1: Brute Force Convex Hull (Brute_force_convex_hull.cpp)

**Aim**
To find the convex hull of a set of 2D points using brute force triangle-interior testing.

**Pseudocode**
```
ALGO BruteHull(pts[], n):
    interior[] ← all false
    FOR i ← 0 TO n - 1:
        FOR j ← i + 1 TO n - 1:
            FOR k ← j + 1 TO n - 1:
                FOR p ← 0 TO n - 1 (p ≠ i, j, k):
                    IF isInside(pts[i], pts[j], pts[k], pts[p]):
                        interior[p] ← true
    hullCount ← count of non-interior points
    RETURN hullCount

ALGO CrossProduct(A, B, C):
    RETURN (B.x - A.x)(C.y - A.y) - (B.y - A.y)(C.x - A.x)
```

**Variables Used**

| Variable | Description |
|---|---|
| `pts[]` | Array of 2D points |
| `interior[]` | Boolean — marks points inside some triangle |
| `i`, `j`, `k` | Triangle vertex indices |
| `p` | Point being tested against current triangle |

**Algorithm Explanation**
Every combination of three points forms a triangle. For each triangle, all remaining points are checked whether they fall inside it using cross-product signs. A point inside any triangle cannot be on the hull. Points not interior to any triangle are hull vertices.

**Time Complexity:** O(n⁴) — four nested loops.

**Space Complexity:** O(n) — interior boolean array.

**Use Cases**
- Baseline reference for validating efficient hull algorithms like Graham Scan or Jarvis March.
- Collision detection prototyping in small 2D physics engines.

---

### Program 2: Fractional Knapsack (Fractional_knapsack.cpp)

**Aim**
To maximize profit by selecting items (or fractions) for a knapsack, comparing three greedy strategies.

**Pseudocode**
```
ALGO FractionalKnapsack(items[], n, capacity):
    Sort items by profit/weight ratio (descending)
    total ← 0.0
    FOR each item:
        IF capacity >= item.weight:
            total += item.profit
            capacity -= item.weight
        ELSE:
            total += (capacity / item.weight) × item.profit
            BREAK
    RETURN total
```

**Variables Used**

| Variable | Description |
|---|---|
| `items[]` | Array of items with profit and weight |
| `n` | Number of items |
| `capacity` | Remaining knapsack capacity |
| `total` | Accumulated profit |

**Algorithm Explanation**
Three greedy strategies are compared: sort by weight (minimize weight used), sort by profit (maximize profit added), and sort by profit/weight ratio (optimal fractional strategy). The ratio strategy is provably optimal for fractional knapsack because it maximizes value per unit of capacity consumed.

**Time Complexity:** O(n²) — bubble sort used for ordering.

**Space Complexity:** O(1).

**Use Cases**
- Resource scheduling where tasks can be partially executed (CPU time slicing).
- Investment portfolio optimization with divisible assets.

---

### Program 3: Matrix Multiplication — Divide and Conquer (Matrix_multiplication_DAC.cpp)

**Aim**
To multiply two n×n matrices using the Divide and Conquer approach.

**Pseudocode**
```
ALGO Multiply(A, B, C, n):
    IF n == 1:
        C[0][0] ← A[0][0] × B[0][0]
        RETURN
    Partition A, B into four n/2 × n/2 submatrices each
    C11 ← Multiply(A11, B11) + Multiply(A12, B21)
    C12 ← Multiply(A11, B12) + Multiply(A12, B22)
    C21 ← Multiply(A21, B11) + Multiply(A22, B21)
    C22 ← Multiply(A21, B12) + Multiply(A22, B22)
    Assemble C from C11, C12, C21, C22
```

**Variables Used**

| Variable | Description |
|---|---|
| `A`, `B` | Input matrices |
| `C` | Result matrix |
| `n` | Matrix dimension |
| `half` | Half the dimension (n/2) |
| `A11..A22`, `B11..B22` | Submatrices after partitioning |
| `T1`, `T2` | Temporary matrices for intermediate products |

**Algorithm Explanation**
Each matrix is split into four equal quadrants. The result quadrants are computed through 8 recursive multiplications and 4 additions. While the recurrence T(n) = 8T(n/2) + O(n²) still gives O(n³), this structure is the foundation for Strassen's improvement.

**Time Complexity:** O(n³).

**Space Complexity:** O(n²) — submatrix storage at each recursion level.

---

### Program 4: Strassen's Matrix Multiplication (Strassen_multiplication.cpp)

**Aim**
To multiply two matrices using Strassen's algorithm, reducing recursive multiplications from 8 to 7.

**Pseudocode**
```
ALGO Strassen(A, B):
    IF n == 1: RETURN A[0][0] × B[0][0]
    Split A, B into n/2 × n/2 submatrices
    M1 ← Strassen(A11+A22, B11+B22)
    M2 ← Strassen(A21+A22, B11)
    M3 ← Strassen(A11, B12-B22)
    M4 ← Strassen(A22, B21-B11)
    M5 ← Strassen(A11+A12, B22)
    M6 ← Strassen(A21-A11, B11+B12)
    M7 ← Strassen(A12-A22, B21+B22)
    C11 ← M1 + M4 - M5 + M7
    C12 ← M3 + M5
    C21 ← M2 + M4
    C22 ← M1 - M2 + M3 + M6
```

**Variables Used**

| Variable | Description |
|---|---|
| `A11..A22`, `B11..B22` | Submatrix blocks |
| `M1..M7` | Seven intermediate product matrices |
| `C11..C22` | Result quadrants assembled from M values |

**Algorithm Explanation**
Strassen algebraically rearranges the 8 multiplications into 7 at the cost of more additions. Since matrix addition is cheaper than multiplication for large n, the recurrence T(n) = 7T(n/2) + O(n²) solves to O(n^2.807), a meaningful improvement at large scale.

**Time Complexity:** O(n^2.807) — Strassen's recurrence.

**Space Complexity:** O(n² log n) — submatrix copies at each recursion level.

**Use Cases**
- Large-scale scientific computing and machine learning matrix operations.
- GPU-accelerated deep learning frameworks for weight matrix updates.

---

## Week 5 — Greedy Graphs & MST

### Program 1: Activity Selection (Activity_selection.cpp)

**Aim**
To select the maximum number of non-overlapping activities from a given set, comparing two greedy strategies.

**Pseudocode**
```
ALGO ActivitySelection(tasks[], strategy):
    IF strategy == FINISH_TIME:
        Sort tasks by endTime ascending
    ELSE:
        Sort tasks by (endTime - startTime) ascending
    lastFinish ← -1
    selectedCount ← 0
    FOR each task:
        IF task.startTime >= lastFinish:
            SELECT task
            lastFinish ← task.endTime
            selectedCount++
    RETURN selectedCount
```

**Variables Used**

| Variable | Description |
|---|---|
| `tasks[]` | Array of tasks with id, startTime, endTime |
| `lastFinish` | End time of the last selected activity |
| `selectedCount` | Number of activities selected |

**Algorithm Explanation**
The greedy choice is selecting the activity that ends earliest (finish-time strategy), allowing maximum room for future activities. The duration strategy (shortest activity first) is suboptimal and included for comparison. After sorting, a single scan greedily picks non-overlapping tasks.

**Time Complexity:** O(n log n) — dominated by sorting.

**Space Complexity:** O(1) after sort.

**Use Cases**
- Scheduling conference rooms, CPU jobs, or exam slots with fixed time windows.
- Bandwidth allocation for packet streams with defined transmission windows.

---

### Program 2: Cycle Detection in Undirected Graph (Cycle_detection.cpp — Week 5)

**Aim**
To detect whether an undirected graph contains a cycle using DFS and parent tracking.

**Pseudocode**
```
ALGO DetectCycle(current, parent, seen[], graph):
    seen[current] ← true
    FOR each next in graph[current]:
        IF NOT seen[next]:
            IF DetectCycle(next, current, seen, graph):
                RETURN true
        ELSE IF next ≠ parent:
            RETURN true   (back-edge found)
    RETURN false
```

**Variables Used**

| Variable | Description |
|---|---|
| `current` | Node being explored |
| `parent` | Node from which current was visited |
| `seen[]` | Tracks visited nodes |
| `graph` | Adjacency list |

**Algorithm Explanation**
DFS explores every node. When a visited neighbor is encountered that is not the direct parent, a back-edge exists — confirming a cycle. Parent tracking prevents falsely flagging the undirected edge back to the predecessor.

**Time Complexity:** O(V + E).

**Space Complexity:** O(V) — visited array and recursion stack.

---

### Program 3: Dijkstra's Shortest Path (Dijkstra.cpp)

**Aim**
To find the shortest path from a source vertex to all other vertices in a weighted graph using a min-heap.

**Pseudocode**
```
ALGO Dijkstra(n, source):
    dist[] ← INF for all nodes; dist[source] ← 0
    MinHeap pq; pq.push({0, source})
    WHILE pq not empty:
        (d, u) ← pq.top(); pq.pop()
        IF d ≠ dist[u]: CONTINUE   (stale entry)
        FOR each edge (u → v, weight w):
            IF dist[u] + w < dist[v]:
                dist[v] ← dist[u] + w
                pq.push({dist[v], v})
```

**Variables Used**

| Variable | Description |
|---|---|
| `dist[]` | Shortest distance from source to each node |
| `pq` | Custom min-heap (priority queue) |
| `d`, `u` | Extracted distance and vertex from heap |
| `v`, `w` | Neighbor vertex and edge weight |

**Algorithm Explanation**
Dijkstra maintains a min-heap of (distance, vertex) pairs. At each step the vertex with the smallest tentative distance is extracted. Its neighbors are relaxed — if a shorter path is found, the new distance is pushed to the heap. Stale entries (where `d ≠ dist[u]`) are skipped. A custom heap is used here instead of STL.

**Time Complexity:** O((V + E) log V).

**Space Complexity:** O(V + E).

**Use Cases**
- GPS navigation and map routing (Google Maps, Waze).
- Network routing protocols (OSPF uses Dijkstra internally).

---

### Program 4: Kruskal's MST (Kruskal.cpp)

**Aim**
To find the Minimum Spanning Tree of a graph using Kruskal's greedy edge-selection algorithm.

**Pseudocode**
```
ALGO Kruskal(n, edges[]):
    Sort edges by weight (ascending)
    Initialize Union-Find for n nodes
    minCost ← 0
    FOR each edge (u, v, w) in sorted order:
        IF Find(u) ≠ Find(v):   (no cycle formed)
            minCost += w
            Union(u, v)
    RETURN minCost
```

**Variables Used**

| Variable | Description |
|---|---|
| `edges[]` | All graph edges with u, v, weight |
| `parent[]` | Union-Find parent array |
| `rankValue[]` | Rank for union by rank optimization |
| `minCost` | Total MST cost |

**Algorithm Explanation**
Edges are sorted by weight. Each edge is considered in order: if its two endpoints belong to different components (checked via Union-Find), the edge is safely added to the MST without forming a cycle. Path compression and union by rank make each Find/Union nearly O(1).

**Time Complexity:** O(E log E) — sorting dominates.

**Space Complexity:** O(V + E).

**Use Cases**
- Designing minimum-cost network infrastructure (cables, pipelines, power grids).
- Cluster analysis in machine learning (single-linkage clustering).

---

### Program 5: Prim's MST (Prims_Algo.cpp)

**Aim**
To find the Minimum Spanning Tree starting from a source vertex by greedily adding the cheapest edge at each step.

**Pseudocode**
```
ALGO Prims(n):
    visited[] ← all false
    MinHeap pq; pq.push({0, 0})
    minCost ← 0
    WHILE pq not empty:
        (weight, u) ← pq.top(); pq.pop()
        IF visited[u]: CONTINUE
        visited[u] ← true
        minCost += weight
        FOR each neighbor v of u with weight w:
            IF NOT visited[v]:
                pq.push({w, v})
    RETURN minCost
```

**Variables Used**

| Variable | Description |
|---|---|
| `visited[]` | Tracks nodes included in MST |
| `pq` | Min-heap of (edge weight, vertex) |
| `minCost` | Running total MST cost |

**Algorithm Explanation**
Prim's grows the MST one vertex at a time. Starting from vertex 0, it always picks the minimum-weight edge connecting the current MST to an unvisited vertex. The heap stores candidate edges and the cheapest is extracted each iteration.

**Time Complexity:** O((V + E) log V).

**Space Complexity:** O(V + E).

**Use Cases**
- Dense graph MST where Prim's outperforms Kruskal's (fewer edges to sort).
- Telecommunication network design with a fixed starting hub.

---

## Week 6 — Dynamic Programming on Graphs

### Program 1: Cycle Detection in Directed Graph (Cycle_detection.cpp — Week 6)

**Aim**
To detect cycles in a directed graph using DFS with three-state coloring (unvisited / in-stack / done).

**Pseudocode**
```
ALGO DFS(node):
    visited[node] ← 1   (in progress)
    FOR each neighbor v of node:
        IF visited[v] == 1:
            hasCycle ← true; RETURN
        IF visited[v] == 0:
            DFS(v)
    visited[node] ← 2   (fully processed)
```

**Variables Used**

| Variable | Description |
|---|---|
| `adj[][]` | Adjacency matrix |
| `visited[]` | 0 = unvisited, 1 = in current DFS stack, 2 = done |
| `hasCycle` | Global flag set on cycle detection |

**Algorithm Explanation**
Three states distinguish unvisited nodes (0), nodes currently on the DFS recursion stack (1), and fully processed nodes (2). A cycle exists if DFS reaches a node that is already on the current stack (state 1), which represents a back-edge in the directed graph.

**Time Complexity:** O(V + E).

**Space Complexity:** O(V).

**Use Cases**
- Detecting circular dependencies in package managers (npm, pip).
- Validating that a task dependency graph is a valid DAG before topological scheduling.

---

### Program 2: Multistage Graph — DP (multistage_graph.cpp)

**Aim**
To find the minimum-cost path from source to destination in a multistage graph using backward dynamic programming.

**Pseudocode**
```
ALGO MultistageGraph(cost[][], n):
    dp[n - 1] ← 0; all others ← INF
    FOR i ← n - 2 DOWNTO 0:
        FOR j ← i + 1 TO n - 1:
            IF cost[i][j] ≠ INF:
                IF cost[i][j] + dp[j] < dp[i]:
                    dp[i] ← cost[i][j] + dp[j]
                    path[i] ← j
```

**Variables Used**

| Variable | Description |
|---|---|
| `cost[][]` | Edge cost matrix |
| `dp[]` | Minimum cost from node i to destination |
| `path[]` | Next node on optimal path from i |

**Algorithm Explanation**
The destination node has cost 0. Working backwards, for each node, the cheapest outgoing edge plus the already-computed cost of the target is tried. The minimum is stored. After all nodes are processed, following path[] from node 0 gives the optimal route.

**Time Complexity:** O(V²).

**Space Complexity:** O(V).

**Use Cases**
- Multi-stop logistics routing (warehouse → distribution center → delivery).
- Project scheduling across defined stages with variable transition costs.

---

### Program 3: Single Source Shortest Path — Dijkstra (sssp.cpp)

**Aim**
To compute shortest distances from a single source to all nodes using STL priority queue.

**Pseudocode**
```
ALGO ShortestPath(source, graph):
    dist[] ← INF; dist[source] ← 0
    MinHeap pq; pq.push({0, source})
    WHILE pq not empty:
        (currDist, node) ← pq.top(); pq.pop()
        IF currDist > dist[node]: CONTINUE
        FOR each (neighbor, weight) in graph[node]:
            IF dist[node] + weight < dist[neighbor]:
                dist[neighbor] ← dist[node] + weight
                pq.push({dist[neighbor], neighbor})
```

**Variables Used**

| Variable | Description |
|---|---|
| `dist[]` | Shortest distances from source |
| `pq` | STL priority_queue (min-heap via greater<>) |
| `graph` | Adjacency list: vector of (neighbor, weight) pairs |

**Algorithm Explanation**
This is a cleaner STL-based implementation of Dijkstra using `priority_queue` with `greater<>` comparator for min-heap behavior. Functionally identical to Week 5's version but using standard library containers.

**Time Complexity:** O((V + E) log V).

**Space Complexity:** O(V + E).

---

## Week 7 — Multistage DP & Matrix Chain

### Program 1: Multistage Graph — Backward DP (multistage_backward.cpp)

**Aim**
To find the minimum-cost path in a fixed 8-node multistage graph using backward dynamic programming.

**Pseudocode**
```
ALGO MultistageBackward(cost[][], n):
    dist[n - 1] ← 0; all others ← INF
    FOR i ← n - 2 DOWNTO 0:
        FOR j ← i + 1 TO n - 1:
            IF cost[i][j] ≠ INF AND cost[i][j] + dist[j] < dist[i]:
                dist[i] ← cost[i][j] + dist[j]
                nextNode[i] ← j
    Trace path using nextNode[] from 0
```

**Variables Used**

| Variable | Description |
|---|---|
| `cost[][]` | Hardcoded 8×8 adjacency cost matrix |
| `dist[]` | Minimum cost to destination from node i |
| `nextNode[]` | Stores next hop on optimal path |

**Algorithm Explanation**
The 8-node cost matrix is predefined. DP is filled backward from the destination. At each node, all forward edges are tried and the minimum cumulative cost is recorded. Path reconstruction follows `nextNode[]` from node 0 to node 7.

**Time Complexity:** O(V²).

**Space Complexity:** O(V).

---

### Program 2: Multistage Graph — Forward DP (multistage_forward.cpp)

**Aim**
To find the minimum-cost path using forward dynamic programming (push-based DP).

**Pseudocode**
```
ALGO MultistageForward(cost[][], n):
    dist[0] ← 0; all others ← INF
    FOR i ← 0 TO n - 1:
        IF dist[i] == INF: CONTINUE
        FOR j ← i + 1 TO n - 1:
            IF cost[i][j] ≠ INF AND dist[i] + cost[i][j] < dist[j]:
                dist[j] ← dist[i] + cost[i][j]
                parent[j] ← i
    Reconstruct path backward using parent[]
```

**Variables Used**

| Variable | Description |
|---|---|
| `dist[]` | Minimum cost from source to node j |
| `parent[]` | Previous node on optimal path to j |

**Algorithm Explanation**
Forward DP starts at the source with cost 0 and propagates costs forward through all reachable nodes. At each node i, it tries to improve cost of all reachable j. Path is reconstructed by tracing parent[] backward from destination.

**Time Complexity:** O(V²).

**Space Complexity:** O(V).

---

### Program 3: Matrix Chain Multiplication (mutichain_matrix_multiplication.cpp)

**Aim**
To determine the optimal parenthesization of a matrix chain that minimizes scalar multiplications.

**Pseudocode**
```
ALGO MatrixChainOrder(dims[], n):
    dp[i][i] ← 0 for all i
    FOR length ← 2 TO n:
        FOR i ← 1 TO n - length + 1:
            j ← i + length - 1
            dp[i][j] ← INF
            FOR k ← i TO j - 1:
                cost ← dp[i][k] + dp[k+1][j] + dims[i-1] × dims[k] × dims[j]
                IF cost < dp[i][j]:
                    dp[i][j] ← cost
                    splitPos[i][j] ← k
```

**Variables Used**

| Variable | Description |
|---|---|
| `dims[]` | Dimension array (n+1 values for n matrices) |
| `dp[i][j]` | Minimum multiplications to compute A_i × ... × A_j |
| `splitPos[i][j]` | Optimal split point for parenthesization |
| `length` | Current chain length being optimized |
| `k` | Trial split position |

**Algorithm Explanation**
Bottom-up DP first solves single matrices (cost 0), then chains of length 2, 3, ... n. For each chain, every possible split point is tried and the one with minimum cost is chosen. `splitPos` records where to split, enabling recursive reconstruction of the optimal parenthesization string.

**Time Complexity:** O(n³) — three nested loops.

**Space Complexity:** O(n²) — DP and split tables.

**Use Cases**
- Optimizing matrix multiplication pipelines in scientific computing and neural network inference.
- Query optimization in relational databases (join reordering).

---

## Week 8 — Advanced Dynamic Programming

### Program 1: All-Pairs Shortest Path — Floyd-Warshall (All_pair_shortest_path.cpp)

**Aim**
To compute the shortest path between every pair of vertices in a weighted directed graph.

**Pseudocode**
```
ALGO FloydWarshall(dist[][], n):
    FOR via ← 0 TO n - 1:
        FOR i ← 0 TO n - 1:
            FOR j ← 0 TO n - 1:
                IF dist[i][via] < INF AND dist[via][j] < INF:
                    dist[i][j] ← min(dist[i][j], dist[i][via] + dist[via][j])
```

**Variables Used**

| Variable | Description |
|---|---|
| `dist[][]` | n×n matrix; initially direct edge costs |
| `via` | Intermediate vertex being considered |
| `i`, `j` | Source and destination pair |

**Algorithm Explanation**
The algorithm considers every vertex as a possible intermediate hop. For each intermediate vertex `via`, it checks if routing through it shortens the path from i to j. After all n iterations, `dist[i][j]` holds the shortest path between every pair.

**Time Complexity:** O(V³).

**Space Complexity:** O(V²) — in-place update of distance matrix.

**Use Cases**
- Network topology analysis and router path tables.
- Social network analysis (shortest connection between users).

---

### Program 2: 0/1 Knapsack — DP (Knapsack_0and1.cpp)

**Aim**
To maximize total value of items packed into a knapsack where each item is either taken whole or not at all.

**Pseudocode**
```
ALGO Knapsack01(capacity, weights[], values[], n):
    dp[0..n][0..capacity] ← 0
    FOR item ← 1 TO n:
        FOR cap ← 1 TO capacity:
            dp[item][cap] ← dp[item - 1][cap]   (exclude)
            IF weights[item-1] ≤ cap:
                include ← values[item-1] + dp[item-1][cap - weights[item-1]]
                dp[item][cap] ← max(dp[item][cap], include)
    RETURN dp[n][capacity]
```

**Variables Used**

| Variable | Description |
|---|---|
| `dp[item][cap]` | Maximum value using first `item` items with capacity `cap` |
| `values[]` | Value of each item |
| `weights[]` | Weight of each item |
| `capacity` | Maximum knapsack weight |

**Algorithm Explanation**
The 2D DP table grows both by number of items and available capacity. For each (item, capacity) cell, the decision is: skip the item (inherit previous row) or include it (add its value and look up the remaining capacity row). The optimal substructure ensures correctness.

**Time Complexity:** O(n × W) — n items, W capacity.

**Space Complexity:** O(n × W) — full DP table.

**Use Cases**
- Resource allocation in cloud computing (assign VMs to servers without exceeding capacity).
- Budget-constrained project selection.

---

### Program 3: Longest Common Subsequence (LCS.cpp — Week 8)

**Aim**
To find the length and the actual string of the Longest Common Subsequence of two strings.

**Pseudocode**
```
ALGO LCS(s1, s2):
    dp[0..n][0..m] ← 0
    FOR i ← 1 TO n:
        FOR j ← 1 TO m:
            IF s1[i-1] == s2[j-1]:
                dp[i][j] ← 1 + dp[i-1][j-1]
            ELSE:
                dp[i][j] ← max(dp[i-1][j], dp[i][j-1])
    Backtrack from dp[n][m] to reconstruct LCS string
```

**Variables Used**

| Variable | Description |
|---|---|
| `s1`, `s2` | Input strings |
| `dp[i][j]` | LCS length of s1[0..i-1] and s2[0..j-1] |
| `n`, `m` | Lengths of s1 and s2 |
| `lcs` | Reconstructed LCS string |

**Algorithm Explanation**
When characters at position (i, j) match, the LCS extends by 1 from the diagonal. When they don't match, the best from removing one character from either string is carried forward. Reconstruction traces back through the table, picking matched characters.

**Time Complexity:** O(n × m).

**Space Complexity:** O(n × m).

**Use Cases**
- Diff utilities (git diff, file comparison tools).
- DNA sequence alignment in bioinformatics.

---

### Program 4: Travelling Salesman — Bitmask DP (Travelling_salesman.cpp — Week 8)

**Aim**
To find the minimum-cost Hamiltonian cycle visiting all cities exactly once using DP with bitmask.

**Pseudocode**
```
ALGO TSP(city, visitedMask, dp[][], cost[][]):
    IF visitedMask == (1 << n) - 1:
        RETURN cost[city][0]   (return to start)
    IF dp[city][visitedMask] ≠ -1:
        RETURN dp[city][visitedMask]
    best ← INF
    FOR next ← 0 TO n - 1:
        IF next NOT in visitedMask:
            newMask ← visitedMask | (1 << next)
            best ← min(best, cost[city][next] + TSP(next, newMask, dp, cost))
    dp[city][visitedMask] ← best
    RETURN best
```

**Variables Used**

| Variable | Description |
|---|---|
| `city` | Current city |
| `visitedMask` | Bitmask of visited cities |
| `dp[city][mask]` | Minimum cost from `city` with `mask` visited |
| `cost[][]` | Distance matrix between cities |

**Algorithm Explanation**
Each state is (current city, set of visited cities encoded as bitmask). Memoization avoids recomputing states. Starting from city 0 with only it marked visited, the recursion tries all unvisited cities next and picks the cheapest complete tour.

**Time Complexity:** O(n² × 2ⁿ).

**Space Complexity:** O(n × 2ⁿ).

**Use Cases**
- Route optimization for delivery and logistics (UPS, Amazon routing).
- PCB drilling path optimization to minimize drill head travel.

---

## Week 9 — DP Revisited & All-Pairs Shortest Path

### Program 1: LCS — Variant (LCS.cpp — Week 9)

**Aim**
To compute LCS on a different input pair ("ABCBDAB" / "BDCABA") using identical DP logic, reinforcing the approach.

*(Algorithm, pseudocode, and complexity identical to Week 8 LCS — applied to different strings for additional practice.)*

---

### Program 2: Merge Sort — Revisited (Merge_purge.cpp)

**Aim**
To sort an array using Merge Sort (clean re-implementation with explicit left/right arrays).

**Pseudocode**
```
ALGO MergeSort(arr[], left, right):
    IF left >= right: RETURN
    mid ← left + (right - left) / 2
    MergeSort(arr, left, mid)
    MergeSort(arr, mid + 1, right)
    MergeParts(arr, left, mid, right)

ALGO MergeParts(arr[], left, mid, right):
    Copy left half to L[], right half to R[]
    Two-pointer merge L and R back into arr[left..right]
```

*(Complexity same as Week 3 Merge Sort — O(n log n) time, O(n) space.)*

---

### Program 3: Floyd-Warshall with Negative Cycle Detection (floyd_warshall.cpp)

**Aim**
To compute all-pairs shortest paths and additionally detect the presence of negative cycles.

**Pseudocode**
```
ALGO FloydWarshall(dist[][], n):
    [same triple loop as Week 8]
    // Negative cycle check:
    FOR i ← 0 TO n - 1:
        IF dist[i][i] < 0:
            hasNegativeCycle ← true
```

**Variables Used**

| Variable | Description |
|---|---|
| `dist[][]` | All-pairs distance matrix |
| `k`, `i`, `j` | Intermediate, source, destination indices |
| `hasNegativeCycle` | Flag set if any diagonal entry goes negative |

**Algorithm Explanation**
Identical to Week 8's Floyd-Warshall but with an extra post-processing step. After all pairs are finalized, the diagonal `dist[i][i]` is checked: a negative value means vertex i lies on a negative-weight cycle (a path i → ... → i with net negative cost).

**Time Complexity:** O(V³).

**Space Complexity:** O(V²).

---

### Program 4: TSP — DP Bitmask Variant (travelling_salesman.cpp — Week 9)

**Aim**
To solve TSP with a slightly restructured recursive function (renamed `tspSolve`) on the same cost matrix.

*(Algorithm and complexity same as Week 8 TSP.)*

---

## Week 10 — Backtracking

### Program 1: N-Queens Problem (N_queens.cpp)

**Aim**
To place n queens on an n×n chessboard so that no two queens threaten each other.

**Pseudocode**
```
ALGO Place(queenNum, n, pos[]):
    IF queenNum == n: RETURN true
    FOR col ← 0 TO n - 1:
        IF isSafe(queenNum, col, pos):
            pos[queenNum] ← col
            IF Place(queenNum + 1, n, pos): RETURN true
    RETURN false

ALGO IsSafe(row, col, pos[]):
    FOR prev ← 0 TO row - 1:
        IF pos[prev] == col: RETURN false
        IF |pos[prev] - col| == |prev - row|: RETURN false
    RETURN true
```

**Variables Used**

| Variable | Description |
|---|---|
| `pos[]` | pos[i] = column of queen placed in row i |
| `queenNum` | Row currently being assigned |
| `col` | Column being tried for current row |
| `prev` | Previously placed row for conflict check |

**Algorithm Explanation**
One queen is placed per row. For each row, every column is tried. Before placement, the column is checked against all previously placed queens for same-column and diagonal conflicts. If no valid column exists in a row, the function backtracks to the previous row.

**Time Complexity:** O(n!) — worst case explores all placements.

**Space Complexity:** O(n) — pos array and recursion stack.

**Use Cases**
- Constraint satisfaction problems (CSP) solver design.
- Parallel task scheduling with mutual exclusion constraints.

---

### Program 2: Graph Coloring — Chromatic Number (graph_coloring.cpp)

**Aim**
To color the vertices of a graph such that no two adjacent vertices share the same color, using the minimum number of colors.

**Pseudocode**
```
ALGO AssignColor(node, m, color[], G[][]):
    IF node == n: RETURN true
    FOR c ← 1 TO m:
        IF isValid(node, c, color, G):
            color[node] ← c
            IF AssignColor(node + 1, m, color, G): RETURN true
            color[node] ← 0   (backtrack)
    RETURN false

// Try m = 1, 2, 3, ... until solvable
```

**Variables Used**

| Variable | Description |
|---|---|
| `G[][]` | Adjacency matrix |
| `color[]` | Assigned color per node (0 = uncolored) |
| `m` | Number of colors being tried |
| `n` | Number of nodes |

**Algorithm Explanation**
Starting with m=1, backtracking tries to assign a valid color to each node. A color is valid if no adjacent node already has it. If assignment fails for current m, m is incremented and tried again. The first m that succeeds is the chromatic number.

**Time Complexity:** O(m^V) — m colors tried for each of V vertices.

**Space Complexity:** O(V).

**Use Cases**
- Register allocation in compilers (variables = nodes, conflicts = edges).
- Frequency assignment in cellular networks (adjacent towers = edges).

---

### Program 3: Hamiltonian Cycle (hamiltonian_cycle.cpp)

**Aim**
To find a closed tour visiting every vertex of a graph exactly once using backtracking.

**Pseudocode**
```
ALGO BuildCycle(step, cycle[], adj[][]):
    IF step == n:
        IF adj[cycle[n-1]][cycle[0]] == 1: RETURN true
        ELSE: RETURN false
    FOR candidate ← 1 TO n - 1:
        IF canPlace(candidate, step, cycle, adj):
            cycle[step] ← candidate
            IF BuildCycle(step + 1, cycle, adj): RETURN true
            cycle[step] ← -1   (backtrack)
    RETURN false
```

**Variables Used**

| Variable | Description |
|---|---|
| `cycle[]` | Ordered vertex sequence building the cycle |
| `step` | Current position in cycle being filled |
| `candidate` | Vertex being tried at position `step` |
| `adj[][]` | Adjacency matrix |

**Algorithm Explanation**
Vertex 0 is fixed as start. Each subsequent position is filled with a candidate that is adjacent to the previous vertex and not yet in the cycle. After all n vertices are placed, the last vertex must connect back to vertex 0 to complete the Hamiltonian cycle. If not, backtracking occurs.

**Time Complexity:** O(n!) — all vertex orderings explored in worst case.

**Space Complexity:** O(n).

**Use Cases**
- Circuit board testing (probe path covering all test points once).
- Tournament scheduling (round-robin where each team plays once).

---

### Program 4: Minimum Chromatic Number (min_chromatic_no.cpp)

**Aim**
To find the minimum number of colors needed to color a graph (chromatic number) using backtracking on an adjacency matrix.

*(Algorithm identical to graph_coloring.cpp — uses array-based adjacency matrix instead of vector, same backtracking logic.)*

**Time Complexity:** O(m^V).

**Space Complexity:** O(V).

---

### Program 5: Subset Sum (subset_sum.cpp)

**Aim**
To find and print all subsets of a given set that sum to a target value using backtracking.

**Pseudocode**
```
ALGO GenerateSubsets(arr[], pos, sum, target, temp[], len, count):
    IF sum == target:
        PRINT temp[0..len-1]
        count++
    IF pos == n OR sum > target: RETURN
    temp[len] ← arr[pos]
    GenerateSubsets(arr, pos+1, sum+arr[pos], target, temp, len+1, count)  // include
    GenerateSubsets(arr, pos+1, sum, target, temp, len, count)              // exclude
```

**Variables Used**

| Variable | Description |
|---|---|
| `arr[]` | Input set of integers |
| `pos` | Current element index |
| `sum` | Running sum of included elements |
| `target` | Desired subset sum |
| `temp[]` | Current subset being built |
| `len` | Number of elements currently in temp |
| `count` | Total subsets found |

**Algorithm Explanation**
At every position, two branches are explored: include the current element (add to sum and temp) or exclude it (move on). If sum equals target, the current subset is printed. If sum exceeds target or all elements are processed, the branch is pruned. This explores the full 2ⁿ possibility space with pruning.

**Time Complexity:** O(2ⁿ) — each element is independently included or excluded.

**Space Complexity:** O(n) — recursion depth and temp array.

**Use Cases**
- Cryptographic key splitting and secret sharing schemes.
- Change-making and payment splitting problems.

---

## Complexity Summary

| Week | Algorithm | Time Complexity | Space Complexity |
|---|---|---|---|
| 1 | Velocity / Ball Bounce | O(log n) | O(log n) |
| 1 | Iterative Power | O(n) | O(1) |
| 1 | Recursive Fast Power | O(log n) | O(log n) |
| 1 | Horner's Rule | O(n) | O(1) |
| 1 | Linear Search | O(n) | O(1) |
| 1 | Missing Number | O(n) | O(1) |
| 1 | String Permutations | O(n!) | O(n) |
| 1 | Binary String Generation | O(2ⁿ) | O(n) |
| 1 | Towers of Hanoi | O(2ⁿ) | O(n) |
| 2 | Binary Search | O(log n) | O(log n) |
| 2 | Insertion Sort | O(n²) | O(1) |
| 3 | Merge Sort | O(n log n) | O(n) |
| 3 | Quick Sort | O(n log n) avg | O(log n) |
| 4 | Brute Force Convex Hull | O(n⁴) | O(n) |
| 4 | Fractional Knapsack | O(n²) | O(1) |
| 4 | Matrix Multiply DAC | O(n³) | O(n²) |
| 4 | Strassen Multiplication | O(n^2.807) | O(n² log n) |
| 5 | Activity Selection | O(n log n) | O(1) |
| 5 | Cycle Detection (Undirected) | O(V + E) | O(V) |
| 5 | Dijkstra | O((V+E) log V) | O(V+E) |
| 5 | Kruskal | O(E log E) | O(V+E) |
| 5 | Prim's | O((V+E) log V) | O(V+E) |
| 6 | Cycle Detection (Directed) | O(V + E) | O(V) |
| 6 | Multistage Graph DP | O(V²) | O(V) |
| 6 | SSSP Dijkstra (STL) | O((V+E) log V) | O(V+E) |
| 7 | Multistage Backward DP | O(V²) | O(V) |
| 7 | Multistage Forward DP | O(V²) | O(V) |
| 7 | Matrix Chain Multiplication | O(n³) | O(n²) |
| 8 | Floyd-Warshall | O(V³) | O(V²) |
| 8 | 0/1 Knapsack DP | O(n × W) | O(n × W) |
| 8 | LCS | O(n × m) | O(n × m) |
| 8 | TSP Bitmask DP | O(n² × 2ⁿ) | O(n × 2ⁿ) |
| 9 | Floyd-Warshall + Neg Cycle | O(V³) | O(V²) |
| 10 | N-Queens | O(n!) | O(n) |
| 10 | Graph Coloring | O(mᵛ) | O(V) |
| 10 | Hamiltonian Cycle | O(n!) | O(n) |
| 10 | Subset Sum | O(2ⁿ) | O(n) |

---

*Repository maintained for Algorithm Design and Analysis Lab — Semester 4.*
