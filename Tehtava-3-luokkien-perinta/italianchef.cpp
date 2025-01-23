#include "italianchef.h"
#include <iostream>
using namespace std;

ItalianChef::ItalianChef(string m):Chef(m)
{
    cout << "ItalianChef constructor. Starting.." << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef destructor. Ending.." << endl;
}

bool ItalianChef::askSecret(string p, int f, int w)
{
    cin >> p; //input for password "pizza"
    cin >> f; //input for flour units
    cin >> w; //input for water units
    if ((password.compare(p)) == 0){
        cout << "Password OK!" << endl;
        makepizza(f,w);
        return true;
    } else {
        cout << "Wrong password." << endl;
        return false;
    }
}

int ItalianChef::makepizza(int f, int w)
{
    int pizzas = min(f,w) / 5;
    cout << "Italian chef made " << pizzas << " secret pizza(s) with "<< f << " flour and " << w << " water!" << endl;
    return pizzas;
}
