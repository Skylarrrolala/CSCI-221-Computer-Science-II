/*
 * CSCI 221 - Chapter 16 Lab: Histogram with Exception Handling
 * 
 * This lab practices throwing and catching exceptions for input validation.
 * You'll build a histogram of numbers 1-10 and reject invalid input.
 * 
 * IMPORTANT: This is a scaffold. Fill in the TODO sections with your implementation.
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// TODO: Optional helper function to check if a string contains only digits
// bool isDigitsOnly(const string& str);

// TODO: Optional helper function to read and validate a number
// Throws exceptions for invalid input
// int readValidNumber();

// TODO: Optional helper function to print the histogram
// void printHistogram(const int counts[], int size);

int main() {
    // TODO: Declare an array to store counts for numbers 1-10
    // HINT: You need 10 elements (or 11 if you want to use indices 1-10)
    
    // TODO: Initialize all counts to 0
    
    // TODO: Ask the user how many numbers they want to enter
    
    // TODO: Read that many numbers in a loop
    
    // TODO: For each input:
    //   1. Read as a string first (using getline or cin >> stringVar)
    //   2. Check if it contains any non-digit characters
    //      - If yes, throw an exception (e.g., invalid_argument)
    //   3. Convert string to int (use stoi() or similar)
    //   4. Check if the number is between 1 and 10
    //      - If not, throw an out_of_range exception
    //   5. If valid, increment the count for that number
    
    // TODO: Wrap the input reading in a try-catch block
    // STRUCTURE:
    //   try {
    //       // read and validate input
    //   }
    //   catch (invalid_argument& e) {
    //       // handle non-numeric input
    //       // maybe print error and ask again, or skip this input
    //   }
    //   catch (out_of_range& e) {
    //       // handle out-of-range numbers
    //   }
    
    // TODO: After collecting all valid inputs, print the histogram
    // For each number 1-10, print the number and a row of asterisks
    // Example output:
    //   1: ***
    //   2: *****
    //   3: **
    //   etc.
    
    // TODO: Consider what to do if user enters invalid input:
    // - Ask them to re-enter?
    // - Skip that input and continue?
    // - Count it as an error and show how many errors occurred?
    
    return 0;
}

// TODO: Implement isDigitsOnly() if you created it
// Loop through each character in the string
// If any character is not a digit (use isdigit()), return false

// TODO: Implement readValidNumber() if you created it
// Read input as string
// Call isDigitsOnly() and throw exception if false
// Convert to int using stoi()
// Check range 1-10 and throw if out of range
// Return the valid number

// TODO: Implement printHistogram() if you created it
// Loop through indices 1-10 (or 0-9 depending on your array design)
// For each index, print the number and that many asterisks
// Example: if counts[3] == 5, print "3: *****"
