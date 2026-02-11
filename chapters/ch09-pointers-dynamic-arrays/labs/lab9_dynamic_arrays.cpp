/*
 * CSCI 221 - Chapter 9 Lab: Dynamic Arrays
 * 
 * This lab practices dynamic memory allocation, growing/shrinking arrays,
 * and pointer reassignment.
 * 
 * IMPORTANT: This is a scaffold. Fill in the TODO sections with your implementation.
 */

#include <iostream>
#include <string>
using namespace std;

// Function declarations
string* addEntry(string* dynamicArray, int& size, string newEntry);
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);

int main() {
    // TODO: Declare an int variable to track the current size (start at 5)
    int curr = 5; 
    // TODO: Allocate a dynamic array of 5 strings using 'new'
    
    // TODO: Initialize the array with 5 starting names
    
    // TODO: Print the initial array of names
    
    // TODO: Call addEntry() to add a new name
    // REMEMBER: Reassign the returned pointer back to your array variable!
    // Example: dynamicArray = addEntry(dynamicArray, size, "NewName");
    
    // TODO: Print the array after adding
    
    // TODO: Call addEntry() one or two more times with different names
    
    // TODO: Print the array again
    
    // TODO: Call deleteEntry() to remove an existing name
    // REMEMBER: Reassign the returned pointer!
    
    // TODO: Print the array after deletion
    
    // TODO: Try deleteEntry() on a name that doesn't exist (should return same array)
    
    // TODO: Print final array
    
    // TODO: Delete the final dynamic array to avoid memory leak
    // Use: delete[] dynamicArray;
    
    return 0;
}

/**
 * Adds a new entry to the dynamic array by creating a larger array.
 * 
 * @param dynamicArray - pointer to the current dynamic array
 * @param size - reference to current size (will be incremented)
 * @param newEntry - the new string to add at the end
 * @return pointer to the new (larger) dynamic array
 */
string* addEntry(string* dynamicArray, int& size, string newEntry) {
    // TODO: Create a new dynamic array that's one element larger than the current size
    
    // TODO: Copy all existing entries from the old array to the new array
    // HINT: Use a for loop from 0 to size-1
    
    // TODO: Add the newEntry at the end of the new array (at index size)
    
    // TODO: Increment the size variable (it's passed by reference)
    
    // TODO: Delete the old array to free memory
    // Use: delete[] dynamicArray;
    
    // TODO: Return the pointer to the new array
    
    return nullptr; // Replace this with your new array pointer
}

/**
 * Deletes an entry from the dynamic array by creating a smaller array.
 * 
 * @param dynamicArray - pointer to the current dynamic array
 * @param size - reference to current size (will be decremented if entry found)
 * @param entryToDelete - the string to search for and remove
 * @return pointer to the new (smaller) array if found, or original array if not found
 */
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete) {
    // TODO: Search through the array to find if entryToDelete exists
    // HINT: Use a for loop and check if dynamicArray[i] == entryToDelete
    
    // TODO: If NOT found, return the original dynamicArray (no changes)
    
    // TODO: If found, note the index where it was found
    
    // TODO: Create a new dynamic array that's one element smaller (size - 1)
    
    // TODO: Copy all elements EXCEPT the one being deleted
    // HINT: You'll need to skip over the index you found
    // Example approach:
    //   - Copy elements [0 to foundIndex-1]
    //   - Skip foundIndex
    //   - Copy elements [foundIndex+1 to size-1] into positions [foundIndex to size-2]
    
    // TODO: Decrement the size variable
    
    // TODO: Delete the old array
    
    // TODO: Return the pointer to the new (smaller) array
    
    return nullptr; // Replace this with appropriate return
}
