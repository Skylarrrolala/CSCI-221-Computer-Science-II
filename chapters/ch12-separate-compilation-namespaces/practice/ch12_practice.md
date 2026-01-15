# Chapter 12: Separate Compilation and Namespaces - Practice Problems

## Small Problems

**1. Split a Simple Class**  
Take your Counter class from Chapter 10 and split it into counter.h (with include guards) and counter.cpp. Create a main.cpp that uses it. Compile all files separately and link them.

**2. Math Utilities Namespace**  
Create a namespace called MathTools with functions for square, cube, and absolute value. Put the declarations in a header file and implementations in a .cpp file. Use the namespace in main.

**3. Multiple Headers**  
Create two simple classes (like Circle and Rectangle) each in their own .h and .cpp files. Make a main file that includes both headers and uses both classes.

**4. Include Guard Practice**  
Write a header file with a simple struct definition. Intentionally include it twice in main (directly and through another header) to see the error, then add include guards to fix it.

**5. Using vs. Scope Resolution**  
Create a namespace with a few functions. In main, call them three different ways: with scope resolution (::), with using declaration for one function, and with using directive for the whole namespace.

## Medium Problems

**1. Multi-File Calculator**  
Build a simple calculator program split into files: operations.h (function prototypes), operations.cpp (add, subtract, multiply, divide), and main.cpp. Use a namespace called Calc for all operations. Compile and link properly.

**2. Library System Organization**  
Create a Book class in book.h/book.cpp and a Library class in library.h/library.cpp. The Library should include the Book header and have methods to add/remove books. Make sure include guards are correct to avoid circular issues.

**3. Two Namespaces Collaboration**  
Create two namespaces (like Geometry and Physics) in separate header/cpp file pairs. Have Geometry contain shapes, and Physics contain functions that calculate properties using Geometry objects. Show proper namespace usage and organization.
