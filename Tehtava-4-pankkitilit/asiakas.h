#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <string>
#include "pankkitili.h"
#include "luottotili.h"
using namespace std;

class Asiakas // includes both, Pankkitili and Luottotili classes
{
public:
    Asiakas(string,double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto(double,Asiakas &);
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
