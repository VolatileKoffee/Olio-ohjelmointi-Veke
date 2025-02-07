#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

using namespace std;

int main()
{
    Notifikaattori noti;

    Seuraaja first("Abel");
    Seuraaja second("Bert");
    Seuraaja third("Carl");
    Seuraaja fourth("Dann");

    noti.lisaa(&first);
    noti.lisaa(&second);
    noti.lisaa(&third);
    noti.lisaa(&fourth);
    noti.tulosta();

    noti.postita("This is message 1.");

    noti.poista(&second); // skipping or "deleting" node

    noti.postita("This is message 2.");

    noti.lisaa(&second); // adding deleted node again

    noti.postita("This is message 3.");

    return 0;
}
