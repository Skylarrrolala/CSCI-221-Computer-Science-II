// ****************************************************************
//
// Repeat Programming Project 11 from Chapter 10 but use an
// array to store the movie ratings instead of separate variables
// ****************************************************************
#include <iostream>
#include <string>

using namespace std;

class Movie
…



int main()
{
	Movie m1("The Adjustment Bureau", "PG-13");
	m1.addRating(5);
	m1.addRating(5);
	m1.addRating(4);
	m1.addRating(4);
	m1.addRating(5);
	cout << m1.getName() << "," << m1.getRating() <<
		" Average rating: " << m1.getAverage() << endl;

	Movie m2("I Am Number Four", "PG-13");
	m2.addRating(3);
	m2.addRating(2);
	m2.addRating(2);
	m2.addRating(4);
	m2.addRating(1);
	cout << m2.getName() << "," << m2.getRating() <<
		" Average rating: " << m2.getAverage() << endl;

    char c;
    cin >> c;
    return 1;
}
