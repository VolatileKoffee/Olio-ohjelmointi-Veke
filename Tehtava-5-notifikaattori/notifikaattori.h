#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include "seuraaja.h"
using namespace std;

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *);
    void poista(Seuraaja *);
    void tulosta();
    void postita(string);
private:
    Seuraaja *seuraajat = nullptr; // head points to null until data is inserted
};

#endif // NOTIFIKAATTORI_H
