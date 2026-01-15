# Lab 10: Odometer Class - Notes

## Goal

This lab is your first complete class definition from scratch. You'll create an `Odometer` class that tracks how many miles a car has driven and calculates fuel usage based on the car's miles-per-gallon (mpg) rating. It's a simple but practical example of encapsulation—keeping data private and providing public methods to interact with it.

## Plan

Here's the step-by-step approach to build this lab:

1. **Define the class structure** - Write `class Odometer` with a private section for data (miles and mpg) and a public section for member functions.

2. **Add private data members** - Decide whether to use `double` or `int` for miles (double is safer for precision) and mpg.

3. **Write the constructor** - Takes one parameter (the car's mpg rating), sets miles to 0, and stores the mpg value. Use an initializer list for cleaner code.

4. **Implement reset()** - Simple function that sets miles back to 0. No parameters, no return value.

5. **Implement addMiles()** - Takes a parameter (miles driven) and adds it to the total miles. Think about validation—should you allow negative miles?

6. **Implement getGallonsUsed()** - Returns miles divided by mpg. This is a simple calculation but important to get right.

7. **Build main() test program** - Create one or two Odometer objects, simulate trips by calling addMiles(), print results with getGallonsUsed(), test the reset function.

## Tricky Parts

Common issues to watch for:

- **Constructor syntax** - Remember the constructor has the same name as the class and no return type. Use an initializer list: `Odometer(double m) : miles(0), mpg(m) { }`

- **Accessing private members** - Your member functions can access private data directly (just use `miles` and `mpg`), but main() cannot—it must use public functions.

- **Const correctness** - Functions like `getGallonsUsed()` don't modify the object, so they should be marked `const`: `double getGallonsUsed() const`

- **Division by zero** - If mpg is 0, you'll crash when dividing. Consider validating mpg in the constructor (must be > 0).

- **Integer division** - If you use `int` for miles and mpg, dividing them gives integer division (100/25 = 4, not 4.0). Use `double` to avoid this.

- **Forgetting to call reset()** - If you want to start fresh tracking, you must explicitly call `reset()`. Adding miles just keeps accumulating.

## Test Ideas

Try these scenarios to verify your class works correctly:

- Create an odometer with 25 mpg, drive 100 miles → should use 4 gallons
- Drive another 50 miles → total should be 6 gallons (150 miles / 25 mpg)
- Call reset(), then drive 75 miles → should show 3 gallons (not 9)
- Create two cars with different mpg (one efficient, one gas guzzler) and compare their fuel usage for the same trip distance
- Test with fractional miles (like 123.5 miles) to make sure doubles work correctly
- Try adding 0 miles → shouldn't crash or do anything weird
- Print miles before and after reset to confirm it goes back to 0

This lab is straightforward if you take it one function at a time. Focus on getting the constructor and one function working first, then build from there!
