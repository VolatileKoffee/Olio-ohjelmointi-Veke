#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string fname):nimi(fname)
{
    cout << "Creating follower: " << fname << endl;
}

string Seuraaja::getNimi() // returns name
{
    return nimi;
}

void Seuraaja::paivitys(string msg) // function prints given message // shares parameter with postita()-function
{
    cout << "Follower " << getNimi() << " got message: " << msg << endl;
}
