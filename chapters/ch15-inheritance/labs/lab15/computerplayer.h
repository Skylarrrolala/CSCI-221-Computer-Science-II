// File Name: computerplayer.h
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Header file for the ComputerPlayer derived class

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "player.h"

namespace guessinggame
{
    class ComputerPlayer : public Player
    {
        public:
            virtual int getGuess();
            // Returns the players next guess, an integer between
            // 0 and 99 (inclusive)

    };
}

#endif
