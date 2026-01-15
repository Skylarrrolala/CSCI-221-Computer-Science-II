# Algorithm Analysis

## 📖 Conceptual Overview

**What is Algorithm Analysis?**
The process of determining how efficient an algorithm is in terms of time (speed) and space (memory).

**Why Analyze Algorithms?**
- Predict performance before implementing
- Compare different solutions objectively
- Choose best algorithm for your constraints
- Understand scalability as input grows

**Key Questions:**
1. How fast does it run?
2. How much memory does it use?
3. How does it scale with larger inputs?

## 🎯 Core Concepts

### 1. Big-O Notation

**What is Big-O?**
Mathematical notation describing how runtime or space grows as input size (n) increases.

**Focus:** Worst-case upper bound (pessimistic estimate)

**Common Complexities (Best to Worst):**
```
O(1)        - Constant
O(log n)    - Logarithmic
O(n)        - Linear
O(n log n)  - Linearithmic
O(n²)       - Quadratic
O(n³)       - Cubic
O(2^n)      - Exponential
O(n!)       - Factorial
```

**Visualization (n=1000):**
```
O(1):       1 operation
O(log n):   ~10 operations
O(n):       1,000 operations
O(n log n): ~10,000 operations
O(n²):      1,000,000 operations
O(2^n):     More than atoms in universe (impossible!)
```

### 2. Analyzing Time Complexity

**Step-by-Step Process:**

**Step 1: Identify Basic Operations**
Count most frequent/significant operations (comparisons, assignments, arithmetic)

**Step 2: Express as Function of Input Size**
How many times does operation execute?

**Step 3: Drop Constants and Lower Terms**
Focus on dominant term as n→∞

**Step 4: Express in Big-O**

**Example 1: Simple Loop**
```
PSEUDOCODE:
FUNCTION sumArray(arr: array, n: int) -> int:
    sum = 0                    // 1 operation
    FOR i from 0 to n-1:      // n iterations
        sum += arr[i]          // 1 operation per iteration
    RETURN sum                 // 1 operation

ANALYSIS:
T(n) = 1 + n×1 + 1 = n + 2
Drop constants: n
Big-O: O(n) - Linear time
```

**Example 2: Nested Loops**
```
PSEUDOCODE:
FUNCTION printPairs(arr: array, n: int):
    FOR i from 0 to n-1:          // n iterations
        FOR j from 0 to n-1:      // n iterations
            OUTPUT arr[i], arr[j]  // 1 operation

ANALYSIS:
Outer loop: n times
Inner loop: n times per outer iteration
Total: n × n = n²
Big-O: O(n²) - Quadratic time
```

**Example 3: Logarithmic**
```
PSEUDOCODE:
FUNCTION binarySearch(arr: array, target: int, n: int):
    left = 0
    right = n-1
    
    WHILE left <= right:
        mid = (left + right) / 2
        
        IF arr[mid] == target:
            RETURN mid
        ELSE IF arr[mid] < target:
            left = mid + 1      // Eliminate left half
        ELSE:
            right = mid - 1     // Eliminate right half
    
    RETURN -1

ANALYSIS:
Each iteration halves search space
n → n/2 → n/4 → n/8 → ... → 1
How many times? log₂(n) times
Big-O: O(log n) - Logarithmic time
```

### 3. Common Complexity Patterns

**O(1) - Constant Time:**
```
EXAMPLES:
- Array access: arr[5]
- Variable assignment: x = 10
- Arithmetic: a + b
- Hash table lookup (average)

PSEUDOCODE:
FUNCTION getFirst(arr: array) -> int:
    RETURN arr[0]  // Always 1 operation

CHARACTERISTIC: Same time regardless of input size
```

**O(log n) - Logarithmic Time:**
```
EXAMPLES:
- Binary search
- Balanced tree operations
- Some divide-and-conquer algorithms

CHARACTERISTIC: Halves problem size each step
Very efficient for large n!
```

**O(n) - Linear Time:**
```
EXAMPLES:
- Single loop through array
- Linear search
- Finding min/max in unsorted array

PSEUDOCODE:
FUNCTION findMax(arr: array, n: int) -> int:
    max = arr[0]
    FOR i from 1 to n-1:
        IF arr[i] > max:
            max = arr[i]
    RETURN max

CHARACTERISTIC: Time grows proportionally with input
```

**O(n log n) - Linearithmic Time:**
```
EXAMPLES:
- Merge sort
- Heap sort
- Quicksort (average case)

CHARACTERISTIC: Common for efficient sorting algorithms
Best possible for comparison-based sorting
```

**O(n²) - Quadratic Time:**
```
EXAMPLES:
- Nested loops (both size n)
- Bubble sort
- Selection sort
- Insertion sort

PSEUDOCODE:
FUNCTION bubbleSort(arr: array, n: int):
    FOR i from 0 to n-1:           // O(n)
        FOR j from 0 to n-i-1:     // O(n)
            IF arr[j] > arr[j+1]:
                SWAP arr[j], arr[j+1]

CHARACTERISTIC: Becomes slow for large n
```

**O(2^n) - Exponential Time:**
```
EXAMPLES:
- Naive Fibonacci
- Generating all subsets
- Solving Tower of Hanoi

PSEUDOCODE:
FUNCTION fibonacci(n: int) -> int:
    IF n <= 1:
        RETURN n
    RETURN fibonacci(n-1) + fibonacci(n-2)

CHARACTERISTIC: Doubles with each increment of n
Impractical for n > ~30-40
```

### 4. Space Complexity

**What is Space Complexity?**
Amount of memory used by algorithm as function of input size.

**Types of Space:**
1. **Fixed Space:** Constants, simple variables
2. **Variable Space:** Depends on input (arrays, recursive call stack)

**Example 1: O(1) Space**
```
FUNCTION sumArray(arr: array, n: int) -> int:
    sum = 0  // Only one variable
    FOR i from 0 to n-1:
        sum += arr[i]
    RETURN sum

SPACE: O(1) - constant space (ignoring input array)
```

**Example 2: O(n) Space**
```
FUNCTION copyArray(arr: array, n: int) -> array:
    newArr = new array[n]  // Additional array of size n
    FOR i from 0 to n-1:
        newArr[i] = arr[i]
    RETURN newArr

SPACE: O(n) - array size grows with input
```

**Example 3: Recursive Space**
```
FUNCTION factorial(n: int) -> int:
    IF n <= 1:
        RETURN 1
    RETURN n * factorial(n-1)

SPACE: O(n) - call stack depth of n
Each call adds frame to stack
```

## 💡 Step-by-Step Analysis Examples

### Example 1: Linear Search

**PSEUDOCODE:**
```
FUNCTION linearSearch(arr: array, n: int, target: int) -> int:
    FOR i from 0 to n-1:
        IF arr[i] == target:
            RETURN i
    RETURN -1
```

**Analysis:**
- Best case: O(1) - target is first element
- Worst case: O(n) - target is last or not present
- Average case: O(n) - expect to check n/2 elements
- Space: O(1) - only loop variable

### Example 2: Selection Sort

**PSEUDOCODE:**
```
FUNCTION selectionSort(arr: array, n: int):
    FOR i from 0 to n-2:              // Outer loop: n-1 times
        minIndex = i
        FOR j from i+1 to n-1:        // Inner loop: decreases each time
            IF arr[j] < arr[minIndex]:
                minIndex = j
        SWAP arr[i], arr[minIndex]
```

**Analysis:**
```
Outer loop iterations: (n-1)
Inner loop iterations:
    i=0: (n-1) comparisons
    i=1: (n-2) comparisons
    i=2: (n-3) comparisons
    ...
    i=n-2: 1 comparison

Total: (n-1) + (n-2) + ... + 1
     = n(n-1)/2
     = (n² - n)/2
     = 1/2 n² - 1/2 n

Drop constants and lower terms: n²

TIME: O(n²) in all cases (best, worst, average)
SPACE: O(1) - sorts in place
```

### Example 3: Merge Sort

**PSEUDOCODE:**
```
FUNCTION mergeSort(arr: array, left: int, right: int):
    IF left < right:
        mid = (left + right) / 2
        
        // Divide
        mergeSort(arr, left, mid)      // Sort left half
        mergeSort(arr, mid+1, right)   // Sort right half
        
        // Conquer
        merge(arr, left, mid, right)   // Merge sorted halves

FUNCTION merge(arr: array, left: int, mid: int, right: int):
    // Create temp arrays
    // Copy data
    // Merge back - O(n) operation
```

**Analysis:**
```
Recurrence relation: T(n) = 2T(n/2) + O(n)
    2T(n/2): Two recursive calls on half-size problems
    O(n): Merge operation

Using Master Theorem or recursion tree:
    Level 0: n operations (1 merge of n elements)
    Level 1: n operations (2 merges of n/2 elements each)
    Level 2: n operations (4 merges of n/4 elements each)
    ...
    Height: log n levels
    
    Total: n × log n

TIME: O(n log n) in all cases
SPACE: O(n) for temporary arrays
```

## 🧪 Complexity Comparison

**Sorting Algorithms:**
| Algorithm | Best | Average | Worst | Space | Stable? |
|-----------|------|---------|-------|-------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

**Search Algorithms:**
| Algorithm | Prerequisite | Time | Space |
|-----------|-------------|------|-------|
| Linear Search | None | O(n) | O(1) |
| Binary Search | Sorted array | O(log n) | O(1) or O(log n) |
| Hash Table | Hash function | O(1) avg | O(n) |

## 🎯 Practice Exercises

**Exercise 1: Analyze These Functions**

```
A) FUNCTION mysteryA(n):
       FOR i from 1 to n:
           FOR j from 1 to i:
               OUTPUT i, j

B) FUNCTION mysteryB(n):
       i = 1
       WHILE i < n:
           OUTPUT i
           i = i * 2

C) FUNCTION mysteryC(n):
       FOR i from 1 to n:
           FOR j from 1 to n:
               FOR k from 1 to n:
                   OUTPUT i, j, k

D) FUNCTION mysteryD(arr, n):
       IF n == 1:
           RETURN arr[0]
       mid = n/2
       left = mysteryD(arr[0..mid], mid)
       right = mysteryD(arr[mid..n], n-mid)
       RETURN max(left, right)
```

**Answers:**
- A: O(n²) - inner loop runs i times, sum = 1+2+...+n = n(n+1)/2
- B: O(log n) - i doubles each time (1,2,4,8,...)
- C: O(n³) - three nested loops
- D: O(n) - finds max by divide-and-conquer

**Exercise 2: Best Data Structure?**

For each scenario, choose optimal data structure and justify:
1. Implement undo feature (many operations)
2. Process tasks in order received
3. Check if element exists (many lookups)
4. Maintain sorted data with frequent insertions
5. Store hierarchical data (parent-child relationships)

## ⚠️ Common Pitfalls

### 1. Confusing Best/Average/Worst Case
```
NOT THE SAME:
- Best case: O(1)
- Average case: O(n)
- Worst case: O(n)

Always specify which case!
```

### 2. Forgetting Hidden Loops
```
TRICKY:
FUNCTION example(arr, n):
    FOR i from 0 to n-1:
        arr.sort()  // sort() is O(n log n)!

LOOKS like O(n), but actually O(n² log n)!
```

### 3. Ignoring Space Complexity
```
Algorithm A: O(n) time, O(1) space
Algorithm B: O(n log n) time, O(n) space

Which is better? Depends on constraints!
If memory limited: choose A
If time critical: choose B
```

## 🔑 Key Takeaways

1. **Big-O shows growth rate** - how algorithm scales
2. **Drop constants and lower terms** - O(3n² + 5n + 2) = O(n²)
3. **Analyze worst case** - unless specified otherwise
4. **Consider both time AND space** - trade-offs exist
5. **Nested loops multiply** - O(n) × O(n) = O(n²)
6. **Logarithmic = efficient** - dividing problem is powerful
7. **Exponential = avoid** - impractical for large inputs
8. **Choose right algorithm** - based on your constraints

## 🚀 Implementation Challenge

**Level 1: Basic Analysis**
1. Write functions with different complexities (O(1), O(n), O(n²))
2. Measure actual runtime with different input sizes
3. Verify Big-O predictions with experiments
4. Graph results

**Level 2: Compare Algorithms**
1. Implement bubble sort and merge sort
2. Test with arrays of size: 100, 1000, 10000
3. Measure and compare runtimes
4. Verify O(n²) vs O(n log n) difference

**Level 3: Optimize**
1. Find inefficient code (e.g., O(n³))
2. Optimize to better complexity
3. Prove improvement through analysis
4. Test with benchmarks

## 📚 Related Topics
- Previous: [Recursion](07-recursion.md) - recursive complexity analysis
- See also: All previous topics - analyze their complexities
- Related: Sorting algorithms, search algorithms, data structures

## 📖 Complexity Cheat Sheet

**Quick Reference:**
```
O(1)      < O(log n) < O(n)      < O(n log n) < 
O(n²)     < O(n³)    < O(2^n)    < O(n!)

GOOD      ←←←←←←←←←←←←←←←←←←←←←→→→→→→→→→      BAD

For n = 1,000,000:
O(log n) ≈ 20 operations
O(n) = 1,000,000 operations
O(n²) = 1,000,000,000,000 operations (trillion!)
```

---
**Remember:** Algorithm analysis helps you choose wisely. A clever algorithm can be millions of times faster than a naive one!
