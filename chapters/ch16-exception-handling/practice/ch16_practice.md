# Chapter 16: Exception Handling - Practice Problems

## Small Problems

**1. Division Safety**  
Write a function that divides two numbers. Throw a runtime_error if the divisor is zero. In main, use try-catch to handle it gracefully and let the user try again.

**2. Age Validator**  
Create a program that asks for age. Throw an invalid_argument if the input contains non-numeric characters, and throw an out_of_range if the age is negative or over 150.

**3. Array Bounds Checker**  
Write a function that accesses an array element at a given index. Throw an out_of_range exception if the index is negative or >= array size. Test with valid and invalid indices.

**4. Multiple Exception Types**  
Make a function that processes a score (0-100). Throw invalid_argument if it's not numeric, out_of_range if it's outside 0-100, and runtime_error if some other processing fails. Catch all three separately in main.

**5. File Validation**  
Ask the user for a filename. Check if it's empty (throw invalid_argument) or contains illegal characters like / or \ (throw runtime_error). Catch and handle appropriately.

## Medium Problems

**1. Calculator with Validation**  
Build a calculator that asks for an operator (+, -, *, /) and two numbers. Throw invalid_argument for unknown operators, runtime_error for division by zero, and handle all numeric input validation. Keep asking until the user quits.

**2. Password Strength Checker**  
Write a function that validates a password. Throw different exceptions for: too short (< 8 chars), no uppercase letter, no lowercase letter, no digit, no special character. Catch each exception type and tell the user what's wrong. Let them retry until they provide a valid password.

**3. Temperature Converter with Limits**  
Create a program that converts temperatures between Celsius and Fahrenheit. Throw out_of_range if Celsius is below absolute zero (-273.15°C) or above 10000°C. Throw invalid_argument for bad input format. Handle edge cases and let users convert multiple temperatures in one session.
