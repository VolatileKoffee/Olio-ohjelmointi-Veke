#include <iostream>
#include <cstdlib>
#include <ctime>
int game(int maxnum);
using namespace std;

int main()
{
    srand(time(0)); //randomizing game seed for each round
    int variableMaxnum = rand()%100+1; //variable maximum cap between 1-100
    cout << "Guess a number between 1-" << variableMaxnum << "!" << endl;

    int guessesInGame = game(variableMaxnum);
    cout << "Total guesses: " << guessesInGame<< endl;

    return 0;
}

int game(int maxnum){

    int secretNum = rand() % maxnum + 1;        //drawing a secret number between 0-maxnum and adding +1

    //cout << "Debug:" << secretNum << endl; //FOR ERROR CHECKING

    int gamestate = 0;                                //game ON or OFF
    int playerGuess;                                  //a guess
    int playerGuessesSum = 0;                         //total guesses of a player

    while(gamestate == 0){
        cin >> playerGuess;
        playerGuessesSum++;

        if (playerGuess == secretNum){                //right answer
            cout << "Right guess!" << endl;
            gamestate = 1;

        }else{                                        //wrong answer
            cout << "Wrong guess! ";

            if (playerGuess > secretNum){                       //bigger than secret number
                cout << "Hint: Guess was too high" << endl;
            }else if(playerGuess < secretNum){                  //smaller than secret number
                cout << "Hint: Guess was too low" << endl;
            }
        }
    }
    return playerGuessesSum;
}
