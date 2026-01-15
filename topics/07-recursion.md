# Recursion

## 📖 Conceptual Overview

**What is Recursion?**
A function that calls itself to solve a problem by breaking it into smaller instances of the same problem.

**Key Idea:** Solve big problem by solving smaller versions of it, until reaching a simple "base case."

**Real-World Analogies:**
- Russian nesting dolls (matryoshka)
- Looking up word in dictionary that uses other words
- Mirrors reflecting each other
- Tree branches splitting into smaller branches

**Two Essential Parts:**
1. **Base Case**: Simplest form, stops recursion
2. **Recursive Case**: Calls itself with simpler input

## 🎯 Core Concepts

### 1. Anatomy of Recursive Function

**PSEUDOCODE Pattern:**
```
FUNCTION recursiveFunction(parameters):
    // BASE CASE - stopping condition
    IF problem is simple enough:
        RETURN direct solution
    
    // RECURSIVE CASE - solve using smaller problem
    ELSE:
        // 1. Make problem smaller
        // 2. Call function on smaller problem
        // 3. Combine results
        RETURN recursiveFunction(smaller_parameters)
```

**Critical Elements:**
1. **Progress toward base case** - each call must get closer
2. **Base case must be reached** - or infinite recursion!
3. **Combine results** - use recursive call result to build answer

### 2. Simple Examples

**Example 1: Factorial**
```
Mathematical: n! = n × (n-1)!
Base case: 0! = 1

PSEUDOCODE:

FUNCTION factorial(n: int) -> int:
    // BASE CASE
    IF n == 0 OR n == 1:
        RETURN 1
    
    // RECURSIVE CASE
    ELSE:
        RETURN n * factorial(n - 1)

TRACE factorial(4):
    factorial(4)
    = 4 * factorial(3)
    = 4 * (3 * factorial(2))
    = 4 * (3 * (2 * factorial(1)))
    = 4 * (3 * (2 * 1))
    = 4 * (3 * 2)
    = 4 * 6
    = 24

COMPLEXITY: O(n) time, O(n) space (call stack)
```

**Example 2: Sum of Array**
```
Sum of array = first element + sum of rest

PSEUDOCODE:

FUNCTION sumArray(arr: array, size: int) -> int:
    // BASE CASE: empty array
    IF size == 0:
        RETURN 0
    
    // RECURSIVE CASE
    ELSE:
        RETURN arr[0] + sumArray(arr+1, size-1)
        // Or: arr[size-1] + sumArray(arr, size-1)

TRACE sumArray([1,2,3,4], 4):
    = 1 + sumArray([2,3,4], 3)
    = 1 + (2 + sumArray([3,4], 2))
    = 1 + (2 + (3 + sumArray([4], 1)))
    = 1 + (2 + (3 + (4 + sumArray([], 0))))
    = 1 + (2 + (3 + (4 + 0)))
    = 1 + (2 + (3 + 4))
    = 1 + (2 + 7)
    = 1 + 9
    = 10
```

### 3. Fibonacci Sequence

**Problem:** fib(n) = fib(n-1) + fib(n-2)

**PSEUDOCODE:**
```
FUNCTION fibonacci(n: int) -> int:
    // BASE CASES
    IF n == 0:
        RETURN 0
    IF n == 1:
        RETURN 1
    
    // RECURSIVE CASE
    ELSE:
        RETURN fibonacci(n-1) + fibonacci(n-2)

TRACE fibonacci(5):
                    fib(5)
                   /      \
              fib(4)      fib(3)
             /     \      /     \
        fib(3)   fib(2) fib(2) fib(1)
        /   \     /  \   /  \
    fib(2) fib(1) ...  ...  ...
     / \
  fib(1) fib(0)

Result: 0, 1, 1, 2, 3, 5, 8, 13...

COMPLEXITY: O(2^n) time - VERY SLOW!
           O(n) space (max call stack depth)

NOTE: Many repeated calculations! fib(3) computed multiple times.
```

**Optimization: Memoization**
```
FUNCTION fibonacciMemo(n: int, memo: array) -> int:
    // Check if already calculated
    IF memo[n] != -1:
        RETURN memo[n]
    
    // BASE CASES
    IF n == 0:
        RETURN 0
    IF n == 1:
        RETURN 1
    
    // Calculate and store
    SET memo[n] = fibonacciMemo(n-1, memo) + fibonacciMemo(n-2, memo)
    RETURN memo[n]

COMPLEXITY: O(n) time - each value calculated once
           O(n) space - memo array + call stack
```

### 4. String Reversal

**PSEUDOCODE:**
```
FUNCTION reverseString(str: string, index: int) -> string:
    // BASE CASE: reached end
    IF index == length(str):
        RETURN ""
    
    // RECURSIVE CASE
    ELSE:
        // Reverse rest + current character
        RETURN reverseString(str, index+1) + str[index]

TRACE reverseString("ABC", 0):
    = reverseString("ABC", 1) + 'A'
    = (reverseString("ABC", 2) + 'B') + 'A'
    = ((reverseString("ABC", 3) + 'C') + 'B') + 'A'
    = (("" + 'C') + 'B') + 'A'
    = ("C" + 'B') + 'A'
    = "CB" + 'A'
    = "CBA"
```

### 5. Binary Search (Recursive)

**PSEUDOCODE:**
```
FUNCTION binarySearch(arr: array, target: int, left: int, right: int) -> int:
    // BASE CASE: not found
    IF left > right:
        RETURN -1
    
    // Calculate middle
    SET mid = (left + right) / 2
    
    // BASE CASE: found
    IF arr[mid] == target:
        RETURN mid
    
    // RECURSIVE CASES
    ELSE IF target < arr[mid]:
        // Search left half
        RETURN binarySearch(arr, target, left, mid-1)
    ELSE:
        // Search right half
        RETURN binarySearch(arr, target, mid+1, right)

COMPLEXITY: O(log n) time - halves search space each call
           O(log n) space - call stack depth
```

## 💡 Step-by-Step Example: Tower of Hanoi

**Problem:** Move n disks from source to destination using auxiliary peg.
- Only one disk moved at a time
- Larger disk never on top of smaller disk

**Thinking Process:**
1. To move n disks from A to C using B:
   - Move (n-1) disks from A to B using C
   - Move largest disk from A to C
   - Move (n-1) disks from B to C using A

**PSEUDOCODE:**
```
FUNCTION hanoi(n: int, source: string, dest: string, aux: string) -> void:
    // BASE CASE: only one disk
    IF n == 1:
        OUTPUT "Move disk 1 from " + source + " to " + dest
        RETURN
    
    // RECURSIVE CASE
    // Step 1: Move n-1 disks to auxiliary
    CALL hanoi(n-1, source, aux, dest)
    
    // Step 2: Move largest disk to destination
    OUTPUT "Move disk " + n + " from " + source + " to " + dest
    
    // Step 3: Move n-1 disks from auxiliary to destination
    CALL hanoi(n-1, aux, dest, source)

TRACE hanoi(3, "A", "C", "B"):
    Move 2 disks A→B using C
        Move 1 disk A→C using B
            Output: "Move disk 1 from A to C"
        Output: "Move disk 2 from A to B"
        Move 1 disk C→B using A
            Output: "Move disk 1 from C to B"
    Output: "Move disk 3 from A to C"
    Move 2 disks B→C using A
        Move 1 disk B→A using C
            Output: "Move disk 1 from B to A"
        Output: "Move disk 2 from B to C"
        Move 1 disk A→C using B
            Output: "Move disk 1 from A to C"

COMPLEXITY: O(2^n) time - each disk doubles moves
           O(n) space - call stack depth
```

## 🧪 Testing Ideas

**Basic Recursion Tests:**
```
1. Base Case Test:
   - factorial(0) → 1
   - factorial(1) → 1
   - sumArray([], 0) → 0
   - fibonacci(0) → 0

2. Small Input Tests:
   - factorial(3) → 6
   - sumArray([5], 1) → 5
   - fibonacci(5) → 5
   - reverseString("A", 0) → "A"

3. Normal Cases:
   - factorial(5) → 120
   - sumArray([1,2,3,4,5], 5) → 15
   - fibonacci(10) → 55
   - reverseString("Hello", 0) → "olleH"

4. Edge Cases:
   - Large n (test stack overflow limit)
   - Negative numbers (if applicable)
   - Empty inputs
   - Maximum recursion depth
```

**Application Tests:**
```
5. Binary Search:
   - Search in empty array
   - Search first element
   - Search last element
   - Search middle element
   - Search non-existing element

6. Tower of Hanoi:
   - n=1 disk → 1 move
   - n=2 disks → 3 moves
   - n=3 disks → 7 moves
   - Verify 2^n - 1 total moves

7. Tree Traversal:
   - Empty tree
   - Single node tree
   - Balanced tree
   - Skewed tree
```

## 📊 Complexity Analysis

**Common Recursive Patterns:**

| Pattern | Example | Time | Space | Notes |
|---------|---------|------|-------|-------|
| Linear | factorial(n) | O(n) | O(n) | One recursive call |
| Binary | fibonacci(n) | O(2^n) | O(n) | Two recursive calls |
| Logarithmic | binarySearch(n) | O(log n) | O(log n) | Halves problem |
| Linearithmic | mergeSort(n) | O(n log n) | O(n) | Divide and conquer |

**Space Complexity:**
- Call stack grows with recursion depth
- Each call adds frame to stack
- Maximum depth determines space usage
- Can cause stack overflow if too deep

**Optimization Techniques:**
1. **Memoization**: Store computed results
2. **Tail Recursion**: Last operation is recursive call (compiler can optimize)
3. **Iterative Conversion**: Sometimes iteration is better

## 🎯 Practice Exercises

**Exercise 1: Power Function**
Calculate base^exponent recursively.

```
HINT:
base^exp = base × base^(exp-1)
base^0 = 1
```

Consider:
- Negative exponents?
- Zero base?
- Optimization for even exponents?

**Exercise 2: Palindrome Checker**
Check if string is palindrome recursively.

```
HINT:
Compare first and last characters
Recursively check middle substring
```

**Exercise 3: Count Digits**
Count number of digits in integer.

```
HINT:
If n < 10: return 1
Else: return 1 + countDigits(n/10)
```

**Exercise 4: Array Maximum**
Find maximum element in array recursively.

```
HINT:
max(arr, n) = max(arr[n-1], max(arr, n-1))
Base: one element
```

**Exercise 5: GCD (Greatest Common Divisor)**
Euclidean algorithm recursively.

```
HINT:
gcd(a, b) = gcd(b, a % b)
gcd(a, 0) = a
```

**Exercise 6: Permutations**
Generate all permutations of string.

```
HINT:
For each character:
  Fix it
  Permute remaining characters
```

## ⚠️ Common Pitfalls

### 1. Missing Base Case
```
BAD:
    FUNCTION factorial(n):
        RETURN n * factorial(n-1)
    // Never stops! Stack overflow!

GOOD:
    FUNCTION factorial(n):
        IF n <= 1:
            RETURN 1
        RETURN n * factorial(n-1)
```

### 2. Not Progressing Toward Base
```
BAD:
    FUNCTION bad(n):
        IF n == 0:
            RETURN 0
        RETURN bad(n)  // Same n! Infinite loop!

GOOD:
    FUNCTION good(n):
        IF n == 0:
            RETURN 0
        RETURN good(n-1)  // Smaller n
```

### 3. Stack Overflow
```
BAD:
    factorial(1000000)  // Too many recursive calls!

GOOD:
    Use iterative version for large inputs
    Or use tail recursion optimization
```

### 4. Inefficient Recursion
```
BAD:
    fibonacci(50)  // O(2^50) - takes forever!

GOOD:
    Use memoization
    Or convert to iterative with two variables
```

## 🔄 Recursion vs. Iteration

**When to Use Recursion:**
- Problem naturally recursive (tree traversal, divide-and-conquer)
- Code is cleaner and more readable
- Stack space not a concern
- Problem size moderate

**When to Use Iteration:**
- Simple sequential processing
- Stack space limited
- Performance critical
- Very large inputs

**Conversion Example:**
```
RECURSIVE factorial:
    FUNCTION factorial(n):
        IF n <= 1: RETURN 1
        RETURN n * factorial(n-1)

ITERATIVE factorial:
    FUNCTION factorial(n):
        result = 1
        FOR i from 2 to n:
            result *= i
        RETURN result
```

## 🔑 Key Takeaways

1. **Always have base case** - or infinite recursion!
2. **Progress toward base** - each call must be simpler
3. **Trust the recursion** - assume smaller problem solved
4. **Watch stack depth** - can overflow with deep recursion
5. **Consider efficiency** - some recursive solutions very slow
6. **Memoization helps** - cache results to avoid recalculation
7. **Draw recursion tree** - visualize to understand
8. **Test base cases** - most bugs here!

## 🚀 Implementation Challenge

**Level 1: Basic Recursion**
Implement:
1. Factorial
2. Sum of array
3. Power function
4. Count digits
5. String reversal

Test edge cases thoroughly!

**Level 2: Intermediate**
Implement:
1. Binary search (recursive)
2. Fibonacci with memoization
3. GCD (Euclidean)
4. Palindrome checker
5. Tower of Hanoi

**Level 3: Advanced**
Implement:
1. Merge sort
2. Quick sort
3. Generate permutations
4. N-Queens problem
5. Subset sum problem

**Bonus: Convert to Iterative**
Take any recursive solution and convert to iterative version.
Compare performance and code clarity.

## 📚 Related Topics
- Previous: [Queues](06-queues.md) - uses recursion in some implementations
- Next: [Algorithm Analysis](08-algorithm-analysis.md) - analyze recursive complexity
- See also: [Linked Lists](04-linked-lists.md) - many recursive operations
- Related: [Stacks](05-stacks.md) - call stack in recursion

---
**Remember:** Recursion is powerful but requires careful thought. Always define base case first, then build recursive case. Draw the recursion tree to visualize!!
