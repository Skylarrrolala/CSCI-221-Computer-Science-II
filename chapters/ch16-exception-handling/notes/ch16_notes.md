# Chapter 16: Exception Handling - Concept Notes

## What this chapter is about

Exception handling is C++'s mechanism for dealing with errors in a controlled, organized way. Instead of checking return values or letting the program crash, you "throw" an exception when something goes wrong and "catch" it where you can handle it. Lab 16 uses exceptions to validate user input for a histogram, and Quiz 7 tests your understanding of try-catch blocks, throwing exceptions, and standard exception types.

## Key ideas in plain words

- **An exception is an object thrown when an error occurs** - it represents what went wrong.
- **`throw` sends an exception** to signal that something failed (like bad input or division by zero).
- **`try` blocks contain code** that might throw exceptions - you wrap risky code in try.
- **`catch` blocks handle exceptions** - they specify what to do if a particular exception is thrown.
- **Exceptions propagate up the call stack** until they find a matching catch block.
- **Standard exception classes** like `invalid_argument`, `out_of_range`, `runtime_error` are provided by C++.
- **You can throw any type** - integers, strings, or custom exception classes.
- **Multiple catch blocks** can handle different exception types after one try block.
- **Catch blocks are checked in order** - put specific exceptions before general ones.
- **If no catch matches, the program terminates** - uncaught exceptions crash the program.

## Tiny C++ examples

### Example 1: Basic throw and catch
```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int age;
        cout << "Enter your age: ";
        cin >> age;
        
        if (age < 0) {
            throw invalid_argument("Age cannot be negative");
        }
        
        cout << "Your age is " << age << endl;
    }
    catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```
**Explanation:** If the user enters a negative age, we throw an `invalid_argument` exception. The catch block handles it by printing the error message from `e.what()`.

### Example 2: Multiple catch blocks
```cpp
try {
    string input;
    cout << "Enter a number (1-10): ";
    cin >> input;
    
    // Check if it's numeric
    for (char c : input) {
        if (!isdigit(c)) {
            throw invalid_argument("Not a number");
        }
    }
    
    int num = stoi(input);
    
    if (num < 1 || num > 10) {
        throw out_of_range("Number out of range");
    }
    
    cout << "Valid number: " << num << endl;
}
catch (invalid_argument& e) {
    cout << "Invalid input: " << e.what() << endl;
}
catch (out_of_range& e) {
    cout << "Range error: " << e.what() << endl;
}
```
**Explanation:** Two different exception types are caught separately. If the input has letters, we throw `invalid_argument`. If it's out of range, we throw `out_of_range`.

### Example 3: Rethrowing an exception
```cpp
void processData(int value) {
    try {
        if (value == 0) {
            throw runtime_error("Cannot process zero");
        }
        // ... process value ...
    }
    catch (runtime_error& e) {
        cout << "Local handling: " << e.what() << endl;
        throw;  // rethrow to let caller handle too
    }
}

int main() {
    try {
        processData(0);
    }
    catch (runtime_error& e) {
        cout << "Main caught: " << e.what() << endl;
    }
    return 0;
}
```
**Explanation:** The `throw;` statement rethrows the current exception. This lets you do some local handling but still pass the exception up to the caller.

## How to build something small

Here's how to add exception handling to a simple division function:

1. **Write a division function** - Takes two integers and returns their quotient
2. **Check for division by zero** - Before dividing, check if the divisor is 0
3. **Throw an exception if zero** - `throw runtime_error("Division by zero");`
4. **Wrap the call in try** - In main, put the function call inside a try block
5. **Add a catch block** - Catch `runtime_error` and print an error message
6. **Test with zero** - Call the function with 0 as divisor to trigger the exception
7. **Test with valid input** - Call with normal values to verify it works when no exception is thrown
8. **Add input validation** - Throw `invalid_argument` if input isn't numeric

## Common mistakes to avoid

- **Catching exceptions by value instead of reference** - Use `catch (Exception& e)` not `catch (Exception e)` to avoid copying.
- **Wrong order of catch blocks** - Put specific exceptions before general ones, or the general one catches everything first.
- **Not including the exception header** - `#include <stdexcept>` for `invalid_argument`, `out_of_range`, `runtime_error`, etc.
- **Throwing without a try-catch** - If you throw but don't catch anywhere, the program crashes with "terminate called".
- **Empty catch blocks** - `catch (...) { }` silently ignores all exceptions, hiding bugs. At least log the error.
- **Forgetting e.what()** - Standard exceptions have a `what()` method that returns the error message string.
- **Using exceptions for normal control flow** - Exceptions are for errors, not for regular program logic (they're slow).
- **Not validating before converting** - Before using `stoi()`, check if the string is actually numeric, or it throws.

## Practice checklist

- [ ] I can write a try-catch block to handle exceptions.
- [ ] I can throw an exception using `throw` with a standard exception type.
- [ ] I can catch different exception types with multiple catch blocks.
- [ ] I understand what `e.what()` does and how to use it.
- [ ] I know when to use `invalid_argument`, `out_of_range`, and `runtime_error`.
- [ ] I can explain why exception handling is better than just using if-else for errors.
