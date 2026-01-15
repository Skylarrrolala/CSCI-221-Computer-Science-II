# Lab 16: Histogram with Exception Handling - Notes

## Goal

This lab is all about using exceptions to validate user input. Instead of just checking with if-statements, you'll practice throwing exceptions when input is bad (contains letters, negative numbers, numbers too big) and catching them gracefully. You'll build a histogram that shows how many times each number from 1 to 10 was entered, displayed with asterisks. It's a practical combo of exception handling and data visualization.

## Plan

Here's the step-by-step approach:

1. **Set up the histogram array** - Create an `int` array with 10 elements (or 11 if you want to use indices 1-10 directly). Initialize all elements to 0.

2. **Ask for the number of inputs** - Prompt the user for how many numbers they'll enter. Store this in a variable to control your loop.

3. **Create a try-catch structure** - Wrap your input loop in a try-catch block. You'll need at least two catch blocks: one for `invalid_argument` (non-numeric input) and one for `out_of_range` (numbers outside 1-10).

4. **Read input as a string** - Inside the try block, read the user's input as a `string` first (not directly as an `int`). This lets you validate it before converting.

5. **Validate for digits only** - Write a helper function or inline code to check if every character in the string is a digit. If you find any letter, space, or symbol, throw an `invalid_argument` exception.

6. **Convert to int and validate range** - Use `stoi()` to convert the string to an integer. Then check if it's between 1 and 10. If not, throw an `out_of_range` exception.

7. **Increment the count** - If the input passes both validations, increment the appropriate element in your histogram array.

8. **Print the histogram** - After collecting all inputs, loop through your array and print each number with the corresponding number of asterisks. For example, if the user entered 3 five times, print "3: *****".

## Tricky Parts

Watch out for these common issues:

- **String validation** - You need to check EVERY character in the string. Use a loop and `isdigit(c)` from `<cctype>` or check if `c >= '0' && c <= '9'`. Don't forget edge cases like empty strings or just spaces.

- **Throwing the right exception type** - Use standard exception classes like `invalid_argument("message")` for non-numeric input and `out_of_range("message")` for numbers outside 1-10. Include a descriptive message.

- **Catching in the right order** - Catch specific exceptions before general ones. Put `invalid_argument` and `out_of_range` before any generic `exception` catch.

- **What to do when you catch** - Decide whether to ask the user to re-enter that number, skip it and move on, or count it as a failed attempt. The lab might specify this; if not, choose a reasonable approach and document it.

- **Array indexing** - If the user enters 5, should you increment `counts[5]` or `counts[4]`? Decide whether to use indices 1-10 (waste index 0) or 0-9 (subtract 1 from input). Be consistent.

- **Negative numbers** - The string "-5" contains only digits and a minus sign. You need to check for the minus sign too, or convert first and then check the integer value.

- **Leading zeros or spaces** - Input like " 05" or "007" might cause issues depending on how you validate. Think about trimming whitespace first.

## Test Ideas

Try these scenarios to verify your exception handling works:

- Enter all valid numbers (like five 5's, three 2's) → should build histogram correctly without errors
- Enter a letter or word (like "abc" or "seven") → should throw `invalid_argument`, catch it, and handle gracefully
- Enter a number too small (like 0 or -3) → should throw `out_of_range`
- Enter a number too large (like 11 or 100) → should throw `out_of_range`
- Mix of valid and invalid inputs → see how many valid ones get counted
- Enter exactly 10 inputs, all different (1-10 once each) → histogram should show one asterisk for each number
- Enter the same number multiple times → that line should have multiple asterisks
- Test edge cases: empty input, just spaces, numbers with leading zeros

Example histogram output if user entered: 3, 5, 3, 7, 5, 3, 5
```
1: 
2: 
3: ***
4: 
5: ***
6: 
7: *
8: 
9: 
10: 
```

This lab combines exception handling with practical input validation. Take your time with the string checking logic—it's the trickiest part!
