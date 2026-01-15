# Chapter 10: Defining Classes - Concept Notes

## What this chapter is about

Classes are the foundation of object-oriented programming (OOP) in C++. A class bundles related data (member variables) and functions (member functions/methods) into a single unit. This lets you model real-world things like an Odometer, BankAccount, or Student. Lab 10 has you build an Odometer class, and Quiz 2 tests your understanding of constructors, encapsulation, and public vs. private members.

## Key ideas in plain words

- **A class is a blueprint** for creating objects. The class defines what data and functions an object will have.
- **An object is an instance** of a class. You can create many objects from one class definition.
- **Encapsulation means hiding data** - make member variables `private` and provide `public` functions to access them.
- **A constructor is a special function** that runs automatically when you create an object. It initializes the object's data.
- **Member functions (methods) operate on the object's data** - they can access private variables directly.
- **The `this` pointer** refers to the current object (usually implicit, but you can use it explicitly).
- **Getters (accessors) return private data**, while **setters (mutators) modify private data** with validation.
- **The destructor** (`~ClassName()`) runs when an object is destroyed, useful for cleanup.
- **Public members are accessible from anywhere**, while **private members are only accessible inside the class**.
- **Initializer lists** in constructors are more efficient than assigning in the body.

## Tiny C++ examples

### Example 1: Simple class definition
```cpp
class Rectangle {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) { }
    
    double getArea() {
        return width * height;
    }
    
    double getWidth() { return width; }
    void setWidth(double w) { width = w; }
};
```
**Explanation:** This class stores width and height privately. The constructor initializes them using an initializer list. Public functions provide controlled access.

### Example 2: Using the class
```cpp
Rectangle rect(5.0, 3.0);     // create object, calls constructor
cout << rect.getArea() << endl;  // prints 15
rect.setWidth(10.0);           // change width
cout << rect.getArea() << endl;  // prints 30
```
**Explanation:** Creating `rect` calls the constructor with arguments 5.0 and 3.0. You call member functions using dot notation.

### Example 3: Constructor with validation
```cpp
class BankAccount {
private:
    double balance;
    
public:
    BankAccount(double initial) {
        if (initial >= 0) {
            balance = initial;
        } else {
            balance = 0;  // don't allow negative starting balance
        }
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() { return balance; }
};
```
**Explanation:** The constructor validates that initial balance isn't negative. The deposit function only adds positive amounts. This is encapsulation protecting data integrity.

## How to build something small

Here's how to create a simple Counter class:

1. **Define the class structure** - `class Counter { private: ... public: ... };`
2. **Add a private data member** - `int count;` to track the current count
3. **Write a constructor** - Initialize `count` to 0 (or a starting value passed as parameter)
4. **Create an increment method** - `void increment() { count++; }`
5. **Create a decrement method** - `void decrement() { if (count > 0) count--; }` (prevent negative)
6. **Add a getter** - `int getCount() { return count; }` to read the current value
7. **Test in main** - Create a Counter object, call increment a few times, print the count
8. **Consider adding a reset method** - `void reset() { count = 0; }` for extra functionality

## Common mistakes to avoid

- **Making data members public** - This breaks encapsulation. Keep data `private` and provide public getters/setters.
- **Forgetting the constructor name** - The constructor MUST have the exact same name as the class, with no return type.
- **Not initializing member variables** - Always initialize in the constructor. Uninitialized data causes unpredictable bugs.
- **Using `return` in a constructor** - Constructors have no return type, not even `void`. Don't write `return;`.
- **Forgetting semicolon after class** - The class definition ends with `};` (note the semicolon after the brace).
- **Confusing dot (.) and arrow (->)** - Use dot for objects: `obj.method()`, arrow for pointers: `ptr->method()`.
- **Trying to access private members from main** - You can't write `rect.width = 5;` if `width` is private. Use a setter.
- **Not using const for getters** - Getters should be `const`: `int getCount() const` to indicate they don't modify the object.

## Practice checklist

- [ ] I can define a class with private data members and public member functions.
- [ ] I can write a constructor that initializes member variables.
- [ ] I can create objects from a class and call their member functions.
- [ ] I understand why we use encapsulation (private data, public interface).
- [ ] I can write both getters and setters for class members.
- [ ] I can explain the difference between a class and an object.
