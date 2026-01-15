# Classes and Object-Oriented Programming

## 📖 Conceptual Overview

**What is a Class?**
A class is a blueprint for creating objects. It encapsulates data (member variables) and functions (member functions/methods) that operate on that data.

**Key OOP Principles:**
- **Encapsulation**: Hide implementation details, expose clean interface
- **Abstraction**: Show only essential features
- **Information Hiding**: Use private/public access specifiers

## 🎯 Core Concepts

### 1. Class Declaration and Definition

**PSEUDOCODE Pattern:**
```
CLASS ClassName:
    PRIVATE:
        // Data members (variables)
        dataType memberVariable1
        dataType memberVariable2
    
    PUBLIC:
        // Constructor
        CONSTRUCTOR ClassName(parameters):
            initialize member variables
        
        // Member functions
        FUNCTION functionName(parameters) -> returnType:
            // implementation
        
        // Destructor
        DESTRUCTOR ~ClassName():
            cleanup resources
```

**Thinking Steps:**
1. Identify what data the object should contain
2. Determine which data should be private (most data)
3. Design public interface (what operations are needed?)
4. Decide on constructors (default, parameterized, copy)
5. Consider if destructor is needed (dynamic memory?)

### 2. Constructors

**Types to Consider:**
```
PSEUDOCODE:

// Default Constructor
CONSTRUCTOR ClassName():
    SET all members to default values

// Parameterized Constructor  
CONSTRUCTOR ClassName(param1, param2):
    SET member1 = param1
    SET member2 = param2
    VALIDATE inputs if necessary

// Copy Constructor
CONSTRUCTOR ClassName(other_object):
    COPY all members from other_object
    FOR dynamic memory:
        PERFORM deep copy (not shallow!)
```

**Edge Cases:**
- What if parameters are invalid?
- What if object is created with no parameters?
- What happens during copying with pointers?

### 3. Member Functions (Methods)

**PSEUDOCODE Pattern:**
```
// Accessor (Getter) - const function
FUNCTION getMember() -> dataType:
    RETURN memberVariable
    // Note: Mark as const - doesn't modify object

// Mutator (Setter)
FUNCTION setMember(newValue) -> void:
    IF newValue is valid:
        SET memberVariable = newValue
    ELSE:
        HANDLE error (exception, return false, etc.)

// Utility Function
FUNCTION processData() -> resultType:
    PERFORM calculations using member variables
    RETURN result
```

**Best Practices:**
- Use `const` for functions that don't modify the object
- Validate input in setters
- Keep functions focused (single responsibility)

### 4. Destructors

**PSEUDOCODE Pattern:**
```
DESTRUCTOR ~ClassName():
    IF member variables use dynamic memory:
        DELETE/DEALLOCATE all dynamic memory
    IF file handles are open:
        CLOSE files
    PERFORM any necessary cleanup
```

**When Needed:**
- When class uses `new` operator
- When class manages resources (files, connections)
- When class allocates memory

## 💡 Step-by-Step Example: BankAccount Class

**Step 1: Identify Requirements**
- Store account number, owner name, balance
- Allow deposits and withdrawals
- Check balance
- Prevent negative balance

**Step 2: Design the Class Structure**
```
PSEUDOCODE:

CLASS BankAccount:
    PRIVATE:
        string accountNumber
        string ownerName
        double balance
    
    PUBLIC:
        // Constructor
        CONSTRUCTOR BankAccount(accNum, owner, initialBalance):
            SET accountNumber = accNum
            SET ownerName = owner
            IF initialBalance >= 0:
                SET balance = initialBalance
            ELSE:
                SET balance = 0  // Edge case: negative initial
        
        // Deposit money
        FUNCTION deposit(amount) -> bool:
            IF amount > 0:
                ADD amount to balance
                RETURN true
            ELSE:
                RETURN false  // Edge case: negative deposit
        
        // Withdraw money
        FUNCTION withdraw(amount) -> bool:
            IF amount > 0 AND amount <= balance:
                SUBTRACT amount from balance
                RETURN true
            ELSE:
                RETURN false  // Edge cases: negative or insufficient
        
        // Get balance (const function)
        FUNCTION getBalance() -> double:
            RETURN balance
```

**Step 3: Consider Edge Cases**
- Empty account number?
- Negative initial balance?
- Withdraw more than balance?
- Deposit negative amount?
- What about zero amounts?

**Step 4: Implement in C++ (YOUR TURN!)**

## 🧪 Testing Ideas

**Test Cases to Implement:**
```
1. Normal Construction:
   - Create account with valid data
   - Verify all members initialized correctly

2. Edge Case Construction:
   - Negative initial balance → should default to 0
   - Empty strings → how to handle?

3. Deposit Tests:
   - Positive amount → balance increases
   - Negative amount → rejected, balance unchanged
   - Zero amount → decide on behavior

4. Withdrawal Tests:
   - Valid amount (< balance) → balance decreases
   - Amount > balance → rejected
   - Negative amount → rejected
   - Exact balance amount → balance becomes 0

5. Boundary Tests:
   - Very large numbers
   - Very small positive numbers
   - Account with zero balance
```

## 📊 Complexity Analysis

**Member Function Complexity:**
- Constructor: O(1) - constant time initialization
- Getter/Setter: O(1) - direct access
- Deposit/Withdraw: O(1) - simple arithmetic

**Space Complexity:**
- O(1) per object - fixed amount of data

**Note:** Complexity increases if members are complex (e.g., vectors, strings with operations)

## 🎯 Practice Exercises

**Exercise 1: Student Class**
Design a Student class with:
- Private: studentID, name, GPA, courses (array or vector)
- Public: constructors, add course, calculate GPA, getters

Consider:
- What if GPA is out of range (0-4)?
- Maximum number of courses?
- Invalid student ID?

**Exercise 2: Rectangle Class**
- Private: length, width
- Public: constructors, area, perimeter, setters with validation

Edge cases:
- Negative dimensions?
- Zero dimensions?
- Very large dimensions?

**Exercise 3: Date Class**
- Private: day, month, year
- Public: constructors, isValid, nextDay, print

Edge cases:
- Invalid dates (Feb 30)?
- Leap years?
- Month/year boundaries?

## 🔑 Key Takeaways

1. **Always initialize member variables** in constructors
2. **Use private for data**, public for interface
3. **Validate inputs** in setters and constructors
4. **Mark read-only functions as const**
5. **Consider edge cases** during design
6. **Test boundary conditions** thoroughly

## 🚀 Implementation Challenge

Now implement one of the practice exercises in C++! Remember:
1. Write class declaration in .h file
2. Implement methods in .cpp file (or inline if simple)
3. Write test driver program
4. Test all edge cases
5. Verify no memory leaks (if using dynamic memory)

## 📚 Related Topics
- Next: [Dynamic Memory Management](02-dynamic-memory.md) - for classes with pointers
- See also: [Templates](03-templates.md) - for generic classes

---
**Remember:** Design first, code second. Think about edge cases before they become bugs!
