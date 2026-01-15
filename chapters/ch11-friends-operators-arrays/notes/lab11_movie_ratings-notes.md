# Lab 11: Movie Ratings - Notes

## Goal

This lab is all about putting arrays inside a class. You'll build a `Movie` class that tracks how many people gave it 1-star, 2-star, 3-star, 4-star, and 5-star ratings. Instead of having five separate variables, you'll use a single array to hold these counts. Then you'll compute the average rating by doing a weighted average calculation. It's a practical example of encapsulating related data.

## Plan

Here's how to tackle this lab step-by-step:

1. **Define the Movie class** - Add private members for the movie name (string), MPAA rating (string), and a ratings array (int array with 5 elements).

2. **Decide on array indexing** - Choose whether `ratings[0]` represents 1-star or if you'll use `ratings[1]` for 1-star (wasting index 0). Either works, just be consistent.

3. **Write the constructor** - Takes two parameters (name and MPAA rating). Initialize all elements of the ratings array to 0 using a loop or `{0}` syntax.

4. **Implement getters and setters** - Simple functions to get/set the movie name and MPAA rating. These are straightforward one-liners.

5. **Implement addRating(int rating)** - Validate that rating is between 1 and 5, then increment the corresponding array element. For example, if rating is 3, increment `ratings[2]` (or `ratings[3]` depending on your indexing).

6. **Implement getAverage()** - Loop through the ratings array. For each index, multiply the star value by the count and add to a sum. Also count total ratings. Return sum / total. Handle the case where no ratings exist yet.

7. **Build main()** - Create an array of 4+ Movie objects. Add various ratings to each movie. Print each movie's name, MPAA rating, and average rating in a nice format.

## Tricky Parts

Watch out for these common issues:

- **Zero-initializing the array** - In the constructor, you must set all elements of the ratings array to 0. You can use a loop or initialize it like `ratings{0}` in an initializer list (C++11).

- **Array indexing confusion** - If you use `ratings[0]` for 1-star, then `ratings[rating-1]` is the right index. If you use `ratings[1]` for 1-star, then `ratings[rating]` is correct. Pick one and stick with it.

- **Validating input in addRating()** - Don't let someone add a rating of 0, 6, or -3. Check if `rating >= 1 && rating <= 5` before using it as an array index, or you could crash.

- **Division by zero in getAverage()** - If no one has rated the movie, the total count is 0, and you can't divide by 0. Return 0.0 or handle it with an if-statement before dividing.

- **Integer division** - If you calculate the average using `int / int`, you'll get integer division (4/3 = 1). Make sure to use `double` or cast to `double` before dividing.

- **Weighted average formula** - Don't just average the counts—you need to weight them. For each star level, multiply (star level) * (count) and sum those up, then divide by total ratings.

## Test Ideas

Try these scenarios to verify your class works:

- Movie with 5 ratings: three 5-stars, two 4-stars → average should be (5*3 + 4*2) / 5 = 23/5 = 4.6
- Movie with all the same rating (e.g., five 3-star ratings) → average should be exactly 3.0
- Movie with a mix: one 1-star, one 2-star, one 3-star, one 4-star, one 5-star → average = (1+2+3+4+5)/5 = 3.0
- Movie with no ratings yet → should return 0.0 or handle gracefully without crashing
- Add many ratings to one movie (like 20 ratings) and verify the average is correct
- Try adding an invalid rating (like 6 or 0) → should be ignored and not crash
- Create 4 movies with different MPAA ratings (G, PG, PG-13, R) and different average scores, then print a nice table

This lab builds on basic class skills and adds array manipulation. Take your time with the weighted average calculation—sketch it out on paper first if needed!
