# Chapter 11: Friends, Overloaded Operators, Arrays in Classes - Concept Notes

## What this chapter is about

This chapter extends your class-building skills with three powerful features: friend functions (special access to private data), operator overloading (making operators like `+` or `<<` work with your classes), and using arrays as class members (like in Lab 11's Movie Ratings). These tools let you make classes that feel like built-in types and can manage collections of data internally. Quiz 3 covers these concepts.

## Key ideas in plain words

- **A friend function can access private members** of a class, even though it's not a member function itself.
- **Operator overloading lets you redefine operators** (like `+`, `==`, `<<`) to work with your custom classes.
- **Arrays as member variables** store multiple values inside one object (like tracking rating counts).
- **The copy constructor** creates a new object as a copy of an existing one (important for classes with dynamic memory).
- **The assignment operator (`=`) can be overloaded** to control how one object is assigned to another.
- **`friend` breaks encapsulation carefully** - use it sparingly, mainly for operator overloading.
- **Overloading `<<` for output** lets you print your objects with `cout << myObject;`.
- **Member arrays need initialization** in the constructor, often with a loop to set all elements.
- **Const correctness matters** - use `const` on functions that don't modify the object.
- **Deep copy vs. shallow copy** - if your class has pointers, you need to manually copy what they point to.

## Tiny C++ examples

### Example 1: Class with member array
```cpp
class Grades {
private:
    int scores[5];
    int count;
    
public:
    Grades() : count(0) {
        for (int i = 0; i < 5; i++) {
            scores[i] = 0;  // initialize array
        }
    }
    
    void addScore(int score) {
        if (count < 5) {
            scores[count] = score;
            count++;
        }
    }
    
    double getAverage() {
        if (count == 0) return 0.0;
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += scores[i];
        }
        return (double)sum / count;
    }
};
```
**Explanation:** The `scores` array is a member variable. The constructor initializes all elements to 0. Methods can loop through the array to calculate things like averages.

### Example 2: Overloading the + operator
```cpp
class Point {
private:
    int x, y;
    
public:
    Point(int x, int y) : x(x), y(y) { }
    
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
    
    void print() { cout << "(" << x << ", " << y << ")"; }
};

// Usage:
Point p1(1, 2);
Point p2(3, 4);
Point p3 = p1 + p2;  // calls operator+
p3.print();  // prints (4, 6)
```
**Explanation:** Overloading `operator+` lets you add two Point objects using `+` syntax. The function returns a new Point with summed coordinates.

### Example 3: Friend function for output
```cpp
class Box {
private:
    int width, height;
    
public:
    Box(int w, int h) : width(w), height(h) { }
    
    friend ostream& operator<<(ostream& out, const Box& b) {
        out << "Box(" << b.width << " x " << b.height << ")";
        return out;
    }
};

// Usage:
Box b(5, 10);
cout << b << endl;  // prints: Box(5 x 10)
```
**Explanation:** The `friend` keyword lets the `operator<<` function access private `width` and `height`. This enables convenient printing with `cout`.

## How to build something small

Here's how to create a simple class with an array of scores:

1. **Define the class** - Include a private array (e.g., `int data[10]`) and a count variable
2. **Initialize in constructor** - Use a loop to set all array elements to 0
3. **Add an insert method** - Check if there's room, then add to `data[count++]`
4. **Write a sum method** - Loop through the array and add up all values
5. **Write an average method** - Call sum and divide by count (watch for divide by zero)
6. **Test with valid data** - Create an object, insert several scores, print average
7. **Test edge cases** - Try inserting more than the array can hold, or computing average with no data
8. **Optional: overload <<** - Add a friend function to print the array nicely

## Common mistakes to avoid

- **Not initializing member arrays** - Arrays don't auto-initialize to 0. You must do it in the constructor.
- **Array index out of bounds** - Always check if the index is valid before accessing `array[index]`.
- **Forgetting to return `*this` in operator=** - The assignment operator should `return *this;` for chaining.
- **Shallow copy with pointers** - If your class has a pointer member, the default copy constructor just copies the pointer, not what it points to.
- **Making friend functions member functions** - A friend is NOT a member. Don't use `ClassName::` before it.
- **Overloading operators that don't make sense** - Don't overload `+` to do subtraction. Keep operations intuitive.
- **Not using const in operator overloading** - Parameters should be `const Type&` if they're not modified.
- **Forgetting the return type** - `operator+` should return a new object (usually), not void.

## Practice checklist

- [ ] I can define a class with an array as a member variable.
- [ ] I can initialize a member array in the constructor.
- [ ] I can write methods that loop through the member array.
- [ ] I understand what a friend function is and when to use it.
- [ ] I can overload a simple operator like `+` or `==`.
- [ ] I can overload `<<` to print my class objects with cout.
