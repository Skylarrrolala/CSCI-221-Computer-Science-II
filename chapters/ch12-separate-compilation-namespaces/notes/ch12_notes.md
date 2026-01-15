# Chapter 12: Separate Compilation and Namespaces - Concept Notes

## What this chapter is about

As programs grow, keeping everything in one file becomes messy. This chapter teaches you how to split your code across multiple files using header files (`.h`) and implementation files (`.cpp`). You'll also learn about namespaces, which prevent name conflicts when different parts of code use the same names. Quiz 4 covers this organizational structure, which is essential for larger projects.

## Key ideas in plain words

- **Separate compilation means splitting code** into multiple files that are compiled independently then linked together.
- **Header files (`.h`) contain declarations** - class definitions, function prototypes, constants.
- **Implementation files (`.cpp`) contain definitions** - the actual code for functions and methods.
- **Include guards prevent double inclusion** - `#ifndef`, `#define`, `#endif` around header content.
- **`#include "myfile.h"` is for your own files**, while `#include <iostream>` is for system libraries.
- **Namespaces group related code** and prevent name collisions (like `std::cout`).
- **`using namespace std;` brings all std names** into scope (convenient but not always recommended in headers).
- **You can create your own namespaces** to organize your code.
- **Scope resolution operator `::`** specifies which namespace or class a name belongs to.
- **Compilation happens in stages** - preprocessing, compiling to object files, then linking into executable.

## Tiny C++ examples

### Example 1: Header file with include guards
```cpp
// calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
};

#endif
```
**Explanation:** Include guards ensure that even if `calculator.h` is included multiple times, its content is only processed once. The `#ifndef` checks if `CALCULATOR_H` is not defined yet.

### Example 2: Implementation file
```cpp
// calculator.cpp
#include "calculator.h"

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}
```
**Explanation:** The `.cpp` file includes its own header and provides the actual code for the methods. Use `ClassName::` to specify which class the function belongs to.

### Example 3: Using the class in main
```cpp
// main.cpp
#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    Calculator calc;
    cout << calc.add(5, 3) << endl;      // prints 8
    cout << calc.subtract(10, 4) << endl; // prints 6
    return 0;
}
```
**Explanation:** The main file includes the header to know about the Calculator class. The actual implementation is in `calculator.cpp`, which gets linked later.

### Example 4: Simple namespace
```cpp
namespace MathUtils {
    const double PI = 3.14159;
    
    double circleArea(double radius) {
        return PI * radius * radius;
    }
}

// Usage:
double area = MathUtils::circleArea(5.0);
// Or:
using namespace MathUtils;
double area2 = circleArea(3.0);
```
**Explanation:** Everything inside `namespace MathUtils` is scoped to that namespace. Use `::` to access them, or `using namespace` to bring names into scope.

## How to build something small

Here's how to organize a simple class across files:

1. **Create the header file** - `MyClass.h` with include guards at top and bottom
2. **Declare your class** - Put the class definition (with member declarations) in the header
3. **Don't put implementations in the header** - Only prototypes and inline functions (very short ones)
4. **Create the implementation file** - `MyClass.cpp` that includes `MyClass.h`
5. **Implement member functions** - Use `MyClass::functionName()` syntax for each function
6. **Create your main file** - `main.cpp` that includes `MyClass.h`
7. **Compile separately** - `g++ -c MyClass.cpp` and `g++ -c main.cpp` create `.o` files
8. **Link together** - `g++ MyClass.o main.o -o program` creates the executable

## Common mistakes to avoid

- **Forgetting include guards** - Without them, including the header twice causes redefinition errors.
- **Putting implementations in headers** - Usually don't put function bodies in `.h` files (except inline or template code).
- **Wrong include syntax** - Use `#include "myfile.h"` for your files, `#include <system>` for standard library.
- **Circular includes** - If A.h includes B.h and B.h includes A.h, you get compilation errors. Use forward declarations.
- **Not including your own header in .cpp** - Always `#include "ClassName.h"` at the top of `ClassName.cpp`.
- **Forgetting namespace scope** - Writing `cout` without `std::` when you haven't used `using namespace std;`.
- **Using `using namespace` in headers** - This pollutes the namespace for anyone who includes your header. Avoid it.
- **Typos in include guard names** - If the guard name doesn't match across `#ifndef`, `#define`, and `#endif`, it won't work.

## Practice checklist

- [ ] I can create a header file with proper include guards.
- [ ] I can separate a class declaration (in .h) from its implementation (in .cpp).
- [ ] I can compile multiple .cpp files separately and link them together.
- [ ] I understand what namespaces are and how to use the `::` operator.
- [ ] I know when to use `#include "file.h"` vs `#include <file>`.
- [ ] I can explain why include guards are necessary.
