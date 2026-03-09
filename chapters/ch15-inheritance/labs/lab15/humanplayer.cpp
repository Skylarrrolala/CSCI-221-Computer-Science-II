// File Name: humanplayer.cpp
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Implementation of the HumanPlayer derived class

#include <iostream>
#include "humanplayer.h"
using namespace std;

namespace guessinggame
{
    int HumanPlayer::getGuess()
    {
        int guess;
        cout << "Enter a guess (0-99): ";
        cin >> guess;
        return guess;
    }
   
}
