// File Name: computerplayer.cpp
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Implementation of the ComputerPlayer derived class

#include "computerplayer.h"
#include <cstdlib>

namespace guessinggame
{
    int ComputerPlayer::getGuess()
    {
        int guess = rand() % 100;
        return guess;
    }
   
}
