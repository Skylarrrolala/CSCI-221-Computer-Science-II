# Chapter 17: Templates - Concept Notes

## What this chapter is about

Templates let you write generic code that works with any data type. Instead of writing separate functions for `int`, `double`, `string`, etc., you write one template and the compiler generates the specific versions you need. This is how the Standard Template Library (STL) works. Quiz 8 covers function templates and class templates, which are foundational for understanding the STL in Chapter 18.

## Key ideas in plain words

- **Templates are blueprints for functions or classes** that work with any type.
- **Function templates** let you write one function that works with multiple data types.
- **Class templates** let you create generic classes (like a Stack that works with any type).
- **The compiler generates code** for each type you use - this is called template instantiation.
- **`template <typename T>` or `template <class T>`** declares a type parameter named `T`.
- **You can have multiple type parameters** - `template <typename T, typename U>`.
- **Template code usually goes in header files** - the compiler needs to see the full definition.
- **Templates are checked at compile time** - errors appear when you use the template with a specific type.
- **Specialization** lets you provide a custom version for a specific type.
- **Templates enable code reuse** without sacrificing type safety.

## Tiny C++ examples

### Example 1: Simple function template
```cpp
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Usage:
int maxInt = getMax(5, 10);           // T = int
double maxDbl = getMax(3.5, 2.1);     // T = double
string maxStr = getMax("apple", "banana");  // T = string
```
**Explanation:** The compiler generates three versions of `getMax`: one for `int`, one for `double`, one for `string`. You write the function once, use it with any type that supports `>`.

### Example 2: Function template with two types
```cpp
template <typename T, typename U>
void printPair(T first, U second) {
    cout << "(" << first << ", " << second << ")" << endl;
}

// Usage:
printPair(5, 3.14);        // T = int, U = double
printPair("Name", 42);     // T = const char*, U = int
```
**Explanation:** `T` and `U` can be different types. The compiler figures out the types from the arguments you pass.

### Example 3: Class template
```cpp
template <typename T>
class Box {
private:
    T value;
    
public:
    Box(T v) : value(v) { }
    
    T getValue() { return value; }
    
    void setValue(T v) { value = v; }
};

// Usage:
Box<int> intBox(42);
Box<string> strBox("Hello");

cout << intBox.getValue() << endl;   // prints 42
cout << strBox.getValue() << endl;   // prints Hello
```
**Explanation:** `Box<int>` and `Box<string>` are different classes generated from the same template. You must specify the type in angle brackets when creating template class objects.

### Example 4: Template with array
```cpp
template <typename T>
T findMin(T arr[], int size) {
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Usage:
int nums[] = {5, 2, 8, 1, 9};
int minNum = findMin(nums, 5);  // returns 1
```
**Explanation:** The template works with any array type that supports the `<` operator. Works for `int`, `double`, `string`, etc.

## How to build something small

Here's how to create a simple generic swap function:

1. **Write the template declaration** - `template <typename T>` before the function
2. **Define the function signature** - `void swap(T& a, T& b)` using the type parameter
3. **Implement the swap logic** - Use a temporary variable to exchange values
4. **Test with integers** - Call `swap(x, y)` where x and y are ints
5. **Test with doubles** - Call `swap(a, b)` where a and b are doubles
6. **Test with strings** - Call `swap(s1, s2)` where s1 and s2 are strings
7. **Verify it works** - Print values before and after to confirm they swapped
8. **Note: no need to specify <type>** - The compiler deduces it from arguments

## Common mistakes to avoid

- **Putting template code in .cpp files** - Templates usually need to be in headers so the compiler can generate code at compile time.
- **Forgetting `<typename>` or `<class>`** - You must use `template <typename T>` before template functions/classes.
- **Not specifying type for class templates** - For function templates, the compiler can deduce the type, but for classes you must write `Box<int>`.
- **Using operations the type doesn't support** - If your template uses `<`, the type must have `operator<` defined.
- **Confusing template parameters with function parameters** - `T` is a type (like `int`), not a variable.
- **Mixing typename and class keywords** - They mean the same thing in template declarations, but be consistent.
- **Not understanding instantiation** - The template itself isn't code—it's a blueprint. Code is generated when you use it.
- **Template errors are verbose** - Compiler errors for templates can be very long. Look for the root cause, not every line.

## Practice checklist

- [ ] I can write a simple function template with one type parameter.
- [ ] I can use a function template with different data types.
- [ ] I can define a class template and create objects from it.
- [ ] I understand that templates are instantiated at compile time.
- [ ] I know why template code usually goes in header files.
- [ ] I can explain the difference between `typename T` and a regular type like `int`.
