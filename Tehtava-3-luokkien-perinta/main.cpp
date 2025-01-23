#include <iostream>
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    Chef masterkokki("Masterchef");
    cout << "Chef's name is: " << masterkokki.getName() << endl;

    cout << "Enter salad ingredients: ";
    int saladinput;
    cin >> saladinput;
    int salad = masterkokki.makeSalad(saladinput);
    cout << saladinput << " ingredients made " << salad << " salads." << endl;

    cout << "Enter soup ingredients: ";
    int soupinput;
    cin >> soupinput;
    int soup = masterkokki.makeSoup(soupinput);
    cout << soupinput << " ingrendients made " << soup << " soups." << endl << endl;

    ItalianChef italykokki("Chef Ferrari");
    cout << "Italian chef's name is: " << italykokki.getName() << endl;

    cout << "Enter italian salad ingredients: ";
    int italiansaladinput;
    cin >> italiansaladinput;
    int italysalad = masterkokki.makeSalad(italiansaladinput);
    cout << italiansaladinput << " ingrendients made " << italysalad << " italian salads." << endl;

    int flourinput = 0, waterinput = 0;
    string pswrdinput;

    italykokki.askSecret(pswrdinput,flourinput,waterinput);
    return 0;
}
