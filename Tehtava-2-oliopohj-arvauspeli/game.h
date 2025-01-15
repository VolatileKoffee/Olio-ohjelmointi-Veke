#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game(int);  //constructor
    ~Game();    //destructor
    void play();
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
    void printGameResult();
protected:
};

#endif // GAME_H
