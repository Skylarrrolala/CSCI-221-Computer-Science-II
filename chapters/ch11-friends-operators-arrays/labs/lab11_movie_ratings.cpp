/*
 * CSCI 221 - Chapter 11 Lab: Movie Ratings
 * 
 * This lab practices using arrays as class members and computing
 * weighted averages from rating counts.
 * 
 * IMPORTANT: This is a scaffold. Fill in the TODO sections with your implementation.
 */

#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    // TODO: Declare a string for the movie title
    
    // TODO: Declare a string for the MPAA rating (G, PG, PG-13, R, etc.)
    
    // TODO: Declare an array to store counts of each rating (1-5 stars)
    // HINT: You need 5 elements (one for each star rating)
    // Consider: ratings[0] for 1-star, ratings[1] for 2-star, etc.
    // OR: ratings[1] for 1-star, ratings[2] for 2-star, etc. (waste index 0)
    
public:
    // TODO: Write a constructor that takes the movie name and MPAA rating
    // The constructor should initialize the ratings array to all zeros
    
    // TODO: Write a getter for the movie name
    
    // TODO: Write a setter for the movie name
    
    // TODO: Write a getter for the MPAA rating
    
    // TODO: Write a setter for the MPAA rating
    
    // TODO: Write addRating(int rating) that increments the count for that rating
    // VALIDATION: Only accept ratings between 1 and 5
    // If rating is 1, increment ratings[0] (or ratings[1] depending on your design)
    
    // TODO: Write getAverage() that returns the average rating as a double
    // FORMULA: sum of (rating * count) / total number of ratings
    // Example: if you have 3 people rate 5-stars and 2 people rate 3-stars:
    //          average = (5*3 + 3*2) / 5 = 21/5 = 4.2
    // WATCH OUT: What if no one has rated the movie yet? (division by zero)
};

// TODO: Implement the Movie constructor
// HINT: Initialize the ratings array in the constructor body or with a loop

// TODO: Implement getName()

// TODO: Implement setName()

// TODO: Implement getMPAA() or getRating()

// TODO: Implement setMPAA() or setRating()

// TODO: Implement addRating(int rating)
// Check if rating is between 1 and 5, then increment the appropriate index

// TODO: Implement getAverage()
// Loop through the ratings array to calculate weighted sum and total count
// Return sum / count (watch for divide by zero!)

int main() {
    // TODO: Create an array of at least 4 Movie objects
    // EXAMPLE: Movie movies[4] = { Movie("Inception", "PG-13"), ... };
    
    // TODO: Add several ratings to each movie using addRating()
    // Example:
    //   movies[0].addRating(5);
    //   movies[0].addRating(4);
    //   movies[0].addRating(5);
    
    // TODO: Loop through the array of movies and print each one's info
    // Print: name, MPAA rating, and average rating
    
    // TODO: Test edge cases:
    // - A movie with no ratings (should handle gracefully, maybe return 0.0)
    // - A movie with all 5-star ratings
    // - A movie with mixed ratings
    
    return 0;
}
