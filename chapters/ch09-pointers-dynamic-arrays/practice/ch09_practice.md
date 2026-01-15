# Chapter 9: Pointers and Dynamic Arrays - Practice Problems

## Small Problems

**1. Pointer Basics**  
Write a program that creates two integer variables, then use pointers to swap their values without directly accessing the variables themselves.

**2. Dynamic Single Value**  
Create a program that asks the user for their favorite number, stores it in a dynamically allocated integer, prints it, and then properly deallocates the memory.

**3. Fixed-Size Dynamic Array**  
Allocate a dynamic array of 3 doubles, fill it with user input, print the sum of all elements, then delete the array.

**4. Pointer Arithmetic Walk**  
Create a static array of 5 integers. Use a pointer and pointer arithmetic (not array notation) to print all elements in the array.

**5. Null Pointer Check**  
Write a small function that takes a pointer as a parameter. If it's nullptr, print "Invalid pointer", otherwise print the value it points to.

## Medium Problems

**1. Grow-Only Array**  
Start with a dynamic array of size 3. Let the user keep adding integers until they type -1 to stop. Each time the array fills up, create a larger array (double the size), copy the data, and delete the old one.

**2. Remove Duplicates**  
Create a dynamic array from user input (ask how many numbers first). Write a function that creates a new dynamic array containing only the unique values, then return the new array and update the size.

**3. Dynamic 2D Array**  
Allocate a 2D array dynamically (array of pointers to arrays). Ask the user for dimensions (rows and cols), fill it with a pattern (like row * col), print it in grid format, then properly deallocate all memory.
