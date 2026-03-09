// File Name: humanplayer.h
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Header file for the HumanPlayer derived class

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

namespace guessinggame
{
    class HumanPlayer : public Player
    {
        public:
            virtual int getGuess();
            // Returns the players next guess, an integer between
            // 0 and 99 (inclusive)

    };
}

#endif
