# Chapter 18: Standard Template Library and C++11 - Practice Problems

## Small Problems

**1. Vector Basics**  
Create a vector of strings for a shopping list. Add 5 items, print them all with a range-based for loop, remove the last item, then print the updated list.

**2. Auto Keyword Practice**  
Create a vector of doubles. Use auto to declare variables for an iterator, the result of size(), and individual elements in a loop. Print everything to verify.

**3. Map for Phone Book**  
Use a map to create a simple phone book (name -> phone number). Add 4-5 entries, look up a few names, try to look up a name that doesn't exist, and print all entries.

**4. Vector Algorithms**  
Create a vector of integers with random values. Use STL algorithms to sort it, reverse it, and find a specific value. Print results after each operation.

**5. String Manipulation**  
Create a string with a sentence. Use string methods to find the length, convert to uppercase (loop and use toupper), count how many spaces it has, and extract a substring.

## Medium Problems

**1. Grade Manager with Vector**  
Build a program that stores student names (vector<string>) and their corresponding grades (vector<double>). Add functions to insert a student, find a student's grade, calculate class average, and find the top student. Use range-based for loops and auto where appropriate.

**2. Word Frequency Counter**  
Read words from user input (until they type "done"). Use a map<string, int> to count how many times each word appears. Display the results sorted by frequency (you'll need to transfer to a vector of pairs and sort that).

**3. Set Operations**  
Create two sets of integers (use set<int>). Implement functions to find the union (all unique elements from both), intersection (elements in both), and difference (elements in first but not second). Use STL algorithms like set_union or write your own loops.
