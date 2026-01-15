# Chapter 15: Inheritance - Concept Notes

## What this chapter is about

Inheritance is a key OOP concept where you create new classes based on existing ones. A derived class (child) inherits data and functions from a base class (parent), then adds or modifies behavior. This promotes code reuse and models "is-a" relationships (like "a Dog is an Animal"). Lab 15 involves inheritance and polymorphism in a guessing game, and Quiz 6 tests your understanding of base/derived classes, virtual functions, and constructors.

## Key ideas in plain words

- **A base class (or parent/superclass) is inherited by a derived class** (child/subclass).
- **Derived classes get all public and protected members** of the base class automatically.
- **Private members are inherited but not directly accessible** - use public/protected getters instead.
- **Virtual functions enable polymorphism** - you can override them in derived classes for different behavior.
- **A base class pointer can point to a derived object** - this is polymorphism in action.
- **`virtual` in the base class** lets derived classes override a function to provide their own version.
- **Pure virtual functions** (= 0) make a class abstract - you can't create objects of it, only derive from it.
- **Constructors are called in order**: base first, then derived.
- **Destructors should be virtual** if you're using polymorphism, so the right destructor is called.
- **`protected` access** means accessible in the class and its derived classes, but not from outside.

## Tiny C++ examples

### Example 1: Basic inheritance
```cpp
class Animal {
protected:
    string name;
    
public:
    Animal(string n) : name(n) { }
    
    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) { }  // call base constructor
    
    void bark() {
        cout << name << " says Woof!" << endl;
    }
};
```
**Explanation:** `Dog` inherits from `Animal`, so it automatically gets the `name` member and `eat()` function. The Dog constructor calls the Animal constructor to initialize `name`.

### Example 2: Virtual functions and polymorphism
```cpp
class Shape {
public:
    virtual double getArea() {  // virtual = can be overridden
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) { }
    
    double getArea() override {  // override base version
        return 3.14159 * radius * radius;
    }
};

// Usage:
Shape* s = new Circle(5.0);  // base pointer to derived object
cout << s->getArea() << endl;  // calls Circle's getArea()
delete s;
```
**Explanation:** The base class `Shape` has a virtual `getArea()`. When you override it in `Circle`, calling `getArea()` on a base pointer invokes the derived version (polymorphism).

### Example 3: Constructor chaining
```cpp
class Vehicle {
protected:
    int wheels;
    
public:
    Vehicle(int w) : wheels(w) {
        cout << "Vehicle created with " << w << " wheels" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() : Vehicle(4) {  // call base constructor with 4
        cout << "Car created" << endl;
    }
};

// Creating Car prints:
// Vehicle created with 4 wheels
// Car created
```
**Explanation:** When you create a `Car`, the `Vehicle` constructor runs first (prints its message), then the `Car` constructor runs. Always call base constructor in the initializer list.

## How to build something small

Here's how to create a simple inheritance hierarchy for different employees:

1. **Define the base class** - `class Employee` with name, ID, and a virtual `calculatePay()` function
2. **Add protected or public data members** - Store common data like name and ID
3. **Write a base constructor** - Initialize the common data members
4. **Make calculatePay() virtual** - So derived classes can override it with their own logic
5. **Create a derived class** - `class HourlyEmployee : public Employee`
6. **Add derived-specific data** - Like hourly rate and hours worked
7. **Override calculatePay()** - Implement the specific formula for hourly employees
8. **Test polymorphism** - Create an `Employee*` pointer to an `HourlyEmployee` object and call `calculatePay()`

## Common mistakes to avoid

- **Forgetting `virtual` in base class** - Without it, you don't get polymorphism. The base version always gets called.
- **Not calling base constructor** - Derived constructors must explicitly call the base constructor in the initializer list.
- **Making destructors non-virtual** - If you use polymorphism (base pointer to derived object), make the base destructor virtual.
- **Trying to access private base members** - Use `protected` instead of `private` if derived classes need direct access.
- **Forgetting `public` in inheritance** - Write `class Derived : public Base`. Without `public`, members become private.
- **Overriding without matching signature** - The function signature (name, parameters) must exactly match the base class.
- **Creating objects of abstract classes** - If a class has a pure virtual function (`= 0`), you can't instantiate it.
- **Deleting through base pointer without virtual destructor** - This only calls the base destructor, leaking derived class resources.

## Practice checklist

- [ ] I can create a base class and a derived class that inherits from it.
- [ ] I can use `protected` members that are accessible in derived classes.
- [ ] I can write a virtual function in the base class and override it in the derived class.
- [ ] I understand how to use a base class pointer to point to a derived class object.
- [ ] I can explain what polymorphism means and when virtual functions are needed.
- [ ] I can write constructors for derived classes that call base class constructors.
