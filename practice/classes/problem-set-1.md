# Problem Set 1: Classes and Object-Oriented Programming

## Problem 1: Book Class 🟢 Easy

**Description:**
Design a `Book` class to represent books in a library system.

**Requirements:**
- Private members: title (string), author (string), ISBN (string), pages (int), available (bool)
- Public members:
  - Constructor with all parameters
  - Default constructor
  - Getters for all members
  - Setter for available status
  - `display()` method to print book information
  - `isLongBook()` method - returns true if pages > 500

**Example Usage:**
```cpp
Book book1("1984", "George Orwell", "978-0451524935", 328, true);
book1.display();
// Output: Title: 1984, Author: George Orwell, ISBN: 978-0451524935, Pages: 328, Available: Yes

if (book1.isLongBook()) {
    cout << "This is a long book!" << endl;
}
```

**Edge Cases to Consider:**
- Empty strings for title/author?
- Negative page numbers?
- Invalid ISBN format?
- What should default constructor initialize values to?

**Test Ideas:**
1. Create book with valid data
2. Create book with default constructor
3. Test all getters
4. Change availability and verify
5. Test isLongBook() with pages = 500, 501, 499
6. Test display() output format

**YOUR TASK:** Implement this class in C++!

---

## Problem 2: Rectangle Class with Validation 🟡 Medium

**Description:**
Create a `Rectangle` class with proper input validation.

**Requirements:**
- Private members: length (double), width (double)
- Public members:
  - Constructor with length and width (must validate!)
  - Default constructor (creates 1x1 rectangle)
  - Getters for length and width
  - Setters with validation (must be > 0)
  - `area()` method
  - `perimeter()` method
  - `isSquare()` method
  - `resize(factor)` method - multiply dimensions by factor

**Validation Rules:**
- Length and width must be positive (> 0)
- If invalid value provided, set to 1.0 and return false from setter
- Constructor should validate and default to 1.0 for invalid values

**Example Usage:**
```cpp
Rectangle rect(5.0, 3.0);
cout << "Area: " << rect.area() << endl;          // 15.0
cout << "Perimeter: " << rect.perimeter() << endl; // 16.0

rect.resize(2.0);  // Now 10.0 x 6.0
cout << "New area: " << rect.area() << endl;      // 60.0

Rectangle square(4.0, 4.0);
if (square.isSquare()) {
    cout << "This is a square!" << endl;
}
```

**Edge Cases:**
- Zero length or width?
- Negative values?
- Very small values (0.0001)?
- Very large values?
- Resize with negative factor?
- Resize with zero?

**Test Ideas:**
1. Valid rectangle creation
2. Invalid values in constructor → defaults to 1x1
3. Setter with invalid value → should fail and keep old value
4. Area and perimeter calculations
5. isSquare() with equal and unequal dimensions
6. resize() with various factors (0.5, 2.0, 1.0)
7. resize() with invalid factors

**Complexity Analysis:**
- All operations: O(1)
- Space: O(1) per object

**YOUR TASK:** Implement with comprehensive validation!

---

## Problem 3: Student Grade Manager 🟡 Medium

**Description:**
Create a `Student` class that manages student information and grades.

**Requirements:**
- Private members:
  - name (string)
  - studentID (string)
  - grades (dynamic array of doubles)
  - numGrades (int)
  - capacity (int)
- Public members:
  - Constructor with name and ID
  - Destructor (clean up dynamic memory!)
  - Copy constructor (deep copy!)
  - Assignment operator (deep copy!)
  - `addGrade(grade)` - add grade (resize if needed)
  - `getAverage()` - calculate average of all grades
  - `getLetterGrade()` - return letter based on average (A, B, C, D, F)
  - `display()` - show student info and grades

**Grading Scale:**
- A: 90-100
- B: 80-89
- C: 70-79
- D: 60-69
- F: Below 60

**Example Usage:**
```cpp
Student student("Alice", "12345");
student.addGrade(95.0);
student.addGrade(87.5);
student.addGrade(92.0);

cout << "Average: " << student.getAverage() << endl;  // 91.5
cout << "Grade: " << student.getLetterGrade() << endl; // A

// Test copy
Student student2 = student;  // Uses copy constructor
student2.addGrade(100.0);    // Should not affect student
```

**Edge Cases:**
- No grades added yet → average?
- Invalid grade values (negative, > 100)?
- Adding many grades → test resize
- Copy empty student?
- Self-assignment?

**Test Ideas:**
1. Create student with no grades
2. Add single grade
3. Add multiple grades
4. Test average calculation
5. Test letter grade boundaries (89.9 vs 90.0)
6. Test copy constructor - modify copy, verify original unchanged
7. Test assignment operator - modify assigned, verify original unchanged
8. Test self-assignment (student1 = student1)
9. Add many grades to trigger resize
10. Use valgrind to check for memory leaks

**Complexity Analysis:**
- addGrade(): O(1) amortized (O(n) when resize needed)
- getAverage(): O(n) - must sum all grades
- Other operations: O(1)
- Space: O(n) where n = number of grades

**Memory Management:**
- MUST implement Big Three (destructor, copy constructor, assignment)
- Start with small capacity (e.g., 5), double when full
- Don't forget to delete[] in destructor!

**YOUR TASK:** Implement with proper memory management!

---

## Problem 4: Date Class 🔴 Hard

**Description:**
Create a robust `Date` class with validation and operations.

**Requirements:**
- Private members: day (int), month (int), year (int)
- Public members:
  - Constructor with day, month, year (validate!)
  - Default constructor (today's date or 1/1/2000)
  - Getters and setters (with validation!)
  - `isValid()` - check if date is valid
  - `isLeapYear()` - check if year is leap year
  - `nextDay()` - advance to next day
  - `previousDay()` - go to previous day
  - `daysBetween(otherDate)` - calculate days between dates
  - `display()` - format: MM/DD/YYYY
  - Comparison operators: ==, <, >, <=, >=

**Validation Rules:**
- Month: 1-12
- Day: 1-31, but depends on month:
  - January (1), March (3), May (5), July (7), August (8), October (10), December (12): 31 days
  - April (4), June (6), September (9), November (11): 30 days
  - February (2): 28 days (29 in leap year)
- Year: 1900-2100 (reasonable range)
- Leap year: divisible by 4, except century years must be divisible by 400

**Example Usage:**
```cpp
Date date1(2, 28, 2024);  // Leap year
date1.display();          // 02/28/2024

date1.nextDay();
date1.display();          // 02/29/2024 (valid in leap year)

date1.nextDay();
date1.display();          // 03/01/2024

Date date2(12, 31, 2023);
date2.nextDay();
date2.display();          // 01/01/2024

Date invalid(2, 30, 2024); // Invalid - Feb doesn't have 30 days
if (!invalid.isValid()) {
    cout << "Invalid date!" << endl;
}
```

**Edge Cases:**
- Leap years (2020, 2024) vs non-leap (2021, 2100)
- Month boundaries (Jan 31 → Feb 1)
- Year boundaries (Dec 31 → Jan 1 next year)
- Invalid dates (Feb 30, April 31, etc.)
- Century years (1900 not leap, 2000 is leap)
- Very large year differences for daysBetween()

**Test Ideas:**
1. Valid date creation
2. Invalid date detection (Feb 30, Apr 31, invalid month/year)
3. Leap year detection (2020: yes, 2021: no, 2000: yes, 1900: no)
4. nextDay() at month boundary
5. nextDay() at year boundary
6. nextDay() Feb 28 in leap year
7. nextDay() Feb 28 in non-leap year
8. previousDay() at month boundary
9. previousDay() at year boundary
10. Date comparisons (earlier, equal, later)
11. daysBetween() same date (0)
12. daysBetween() consecutive dates (1)
13. daysBetween() across year boundary

**Algorithm Hints:**

Leap year:
```
IF year divisible by 400:
    RETURN true
ELSE IF year divisible by 100:
    RETURN false
ELSE IF year divisible by 4:
    RETURN true
ELSE:
    RETURN false
```

Days in month:
```
IF month is 1, 3, 5, 7, 8, 10, 12:
    RETURN 31
ELSE IF month is 4, 6, 9, 11:
    RETURN 30
ELSE IF month is 2:
    IF isLeapYear():
        RETURN 29
    ELSE:
        RETURN 28
```

**Complexity:**
- All operations: O(1) except daysBetween()
- daysBetween(): O(days) if you count day by day, or O(1) with date formula

**Bonus Challenge:** Implement daysBetween() in O(1) using date formulas!

**YOUR TASK:** Implement a bulletproof Date class!

---

## Evaluation Criteria

For each problem, your solution should:
1. ✅ Compile without errors or warnings
2. ✅ Follow proper class design (encapsulation, initialization)
3. ✅ Handle all edge cases gracefully
4. ✅ Include appropriate validation
5. ✅ Be well-commented and readable
6. ✅ Include no memory leaks (if using dynamic memory)
7. ✅ Have comprehensive test driver program

## 🚀 Next Steps

After completing these problems:
1. Review your solutions for code quality
2. Test with various inputs including edge cases
3. Analyze the complexity of your operations
4. Refactor for clarity and efficiency
5. Move on to Problem Set 2 (Dynamic Memory)!

---
**Remember:** Focus on understanding, not just completing. If you struggle, review the [Classes topic guide](../../topics/01-classes.md) first!
