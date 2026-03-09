// File Name: player.h
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Header file for the Player base class

#ifndef PLAYER_H
#define PLAYER_H

namespace guessinggame
{
    class Player
    {
        public:
            virtual int getGuess();
            // Returns the players next guess, an integer between
            // 0 and 99 (inclusive)

    };
}

#endif
