/*
 * CSCI 221 - Chapter 10 Lab: Odometer Class
 * 
 * This lab practices defining a class with private data members,
 * a constructor, and member functions to track miles and fuel usage.
 * 
 * IMPORTANT: This is a scaffold. Fill in the TODO sections with your implementation.
 */

#include <iostream>
using namespace std;

class Odometer {
private:
    // TODO: Declare a variable for total miles driven (double or int?)
    
    // TODO: Declare a variable for fuel efficiency in miles per gallon (mpg)
    
public:
    // TODO: Write a constructor that takes one parameter (mpg)
    // The constructor should set miles to 0 and store the mpg value
    
    // TODO: Write a reset() function that sets miles back to 0
    
    // TODO: Write an addMiles() function that takes miles as a parameter
    // and adds them to the total miles driven
    
    // TODO: Write a getGallonsUsed() function that returns the gallons of fuel used
    // FORMULA: gallons = miles / mpg
    
    // TODO: Optional - write a getMiles() function to return current miles
    // This helps with testing/printing
};

// TODO: Implement the Odometer constructor
// HINT: Use an initializer list or assign in the body

// TODO: Implement the reset() member function

// TODO: Implement the addMiles() member function
// Remember to add the parameter miles to the total

// TODO: Implement the getGallonsUsed() member function
// Return miles divided by mpg

// TODO: Implement getMiles() if you added it

int main() {
    // TODO: Create an Odometer object for a car with 25 mpg
    
    // TODO: Simulate a trip - add some miles (e.g., 100 miles)
    
    // TODO: Print how many gallons were used for that trip
    // HINT: Call getGallonsUsed()
    
    // TODO: Add more miles for another trip
    
    // TODO: Print total gallons used so far
    
    // TODO: Reset the odometer to 0
    
    // TODO: Add miles for a new trip after reset
    
    // TODO: Print gallons used (should only count miles since reset)
    
    // TODO: Create a second Odometer object with different mpg (e.g., 30 mpg)
    
    // TODO: Simulate trips with the second car and compare fuel usage
    
    return 0;
}
