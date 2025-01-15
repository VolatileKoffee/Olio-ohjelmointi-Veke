#include <iostream>
#include "game.h"

using namespace std;

int main() {
    cout << "Enter the number limit for the game:" << endl;
    int inputmaxnum;
    cin >> inputmaxnum;

    Game game(inputmaxnum);
    game.play();

    return 0;
}
