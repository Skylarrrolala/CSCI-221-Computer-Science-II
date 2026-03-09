// File Name: main.cpp
// Author: Dararithy Heng
// Email Address: d_heng@mail.fhsu.edu
// Project Number: 15.10
// Description: Number-guessing game


#include <iostream>
#include <cstdlib>
#include "player.h"
#include "computerplayer.h"
#include "humanplayer.h"
using namespace std;
using namespace guessinggame;

bool checkForWin(int guess, int answer) 
{ 
    cout << "You guessed " << guess << ". ";
    if (answer == guess) 
    { 
        cout << "You're right! You win!" << endl; 
        return true; 
    } 
    else if (answer < guess) 
        cout << "Your guess is too high." << endl; 
    else 
        cout << "Your guess is too low." << endl; 
    return false; 
} 
 
void play(Player &player1, Player &player2) 
{ 
    int answer = 0, guess = 0; 
    answer = rand() % 100;
    bool win = false; 
 
    while (!win) 
    { 
        cout << "Player 1's turn to guess." << endl; 
        guess = player1.getGuess(); 
        win = checkForWin(guess, answer); 
        if (win) return; 
 
        cout << "Player 2's turn to guess." << endl; 
        guess = player2.getGuess(); 
        win = checkForWin(guess, answer); 
    }
}

int main()
{
    srand(time(0));

    HumanPlayer human;
    ComputerPlayer computer;

    play(human, computer);

    return 0;
}
