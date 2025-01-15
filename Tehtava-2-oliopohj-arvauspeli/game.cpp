#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int inputmaxnum) { //constructor
    srand(time(0));
    numOfGuesses = 0;
    maxNumber = inputmaxnum;

    cout << "Constructor: Game object initialized with '" << maxNumber << "' as a maximum number." << endl;
}

Game::~Game() { //destructor
    cout << "Destructor: Game object cleared" << endl;

}

void Game::play() { //guessing game function
    randomNumber = rand()% maxNumber + 1;
    cout << "Guess the secret number from 1-" << maxNumber << "." << endl;

    int gamestate = 0; //game ON (default state)

    while(gamestate == 0){
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess == randomNumber){
            cout << "That's correct!" << endl;
            gamestate = 1; //game OFF (ending state)
        } else{
            cout << "Wrong guess.";
            if (playerGuess > randomNumber){
                cout << "(Guess was too high.)" << endl;
            } else if(playerGuess < randomNumber){
                cout << "(Guess was too low.)" << endl;
            }
        }
    }
    printGameResult();
}

void Game::printGameResult() { //called after the game has ended
    cout << "Right answer was: " << randomNumber << endl;
    cout << "You made total of " << numOfGuesses << " guess(es)!" << endl;
}
