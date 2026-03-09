// ****************************************************************
//
// Repeat Programming Project 11 from Chapter 10 but use an
// array to store the movie ratings instead of separate variables
// ****************************************************************
#include <iostream>
#include <string>

using namespace std;

class Movie
{
private:
	string name;
	string mpaaRating;
	int ratings[5];

public:
	Movie(const string& n = "", const string& r = "")
	{
		name = n;
		mpaaRating = r;
		for (int i = 0; i < 5; i++)
		{
			ratings[i] = 0;
		}
	}

	void setName(const string& n)
	{
		name = n;
	}

	void setRating(const string& r)
	{
		mpaaRating = r;
	}

	string getName() const
	{
		return name;
	}

	string getRating() const
	{
		return mpaaRating;
	}

	void addRating(int rating)
	{
		if (rating >= 1 && rating <= 5)
		{
			ratings[rating - 1]++;
		}
	}

	double getAverage() const
	{
		int weightedSum = 0;
		int totalRatings = 0;

		for (int i = 0; i < 5; i++)
		{
			const int starValue = i + 1;
			weightedSum += starValue * ratings[i];
			totalRatings += ratings[i];
		}

		if (totalRatings == 0)
		{
			return 0.0;
		}

		return static_cast<double>(weightedSum) / totalRatings;
	}
};



int main()
{
	Movie movies[4] = {
		Movie("The Adjustment Bureau", "PG-13"),
		Movie("I Am Number Four", "PG-13"),
		Movie("Finding Nemo", "G"),
		Movie("Inception", "PG-13")
	};

	movies[0].addRating(5);
	movies[0].addRating(5);
	movies[0].addRating(4);
	movies[0].addRating(4);
	movies[0].addRating(5);

	movies[1].addRating(3);
	movies[1].addRating(2);
	movies[1].addRating(2);
	movies[1].addRating(4);
	movies[1].addRating(1);

	movies[2].addRating(5);
	movies[2].addRating(4);
	movies[2].addRating(5);
	movies[2].addRating(5);
	movies[2].addRating(4);

	movies[3].addRating(5);
	movies[3].addRating(4);
	movies[3].addRating(4);
	movies[3].addRating(5);
	movies[3].addRating(5);

	for (int i = 0; i < 4; i++)
	{
		cout << movies[i].getName() << "," << movies[i].getRating()
			<< " Average rating: " << movies[i].getAverage() << endl;
	}

	char c;
	cin >> c;
	return 0;
}
