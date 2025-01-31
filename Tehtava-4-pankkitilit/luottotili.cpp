#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>
using namespace std;

Luottotili::Luottotili(string cname, double creditcap):Pankkitili(cname),luottoRaja(-creditcap)
{

}

bool Luottotili::deposit(double cdepo) // Credit deposit function
{
    if (saldo + cdepo > 0){
        cout << "Luottotalletus liian suuri!" << endl;
        return false;

    } else if (cdepo <= 0){
        cout << "Luoton talletusvirhe: negatiivinen summa!" << endl;
        return false;

    } else {
        saldo += cdepo;
        cout << "Luottotalletus onnistui summalla " << cdepo << ". Luottosaldo: " << saldo << endl;
        return true;
    }
}

bool Luottotili::withdraw(double cdraw) // Credit withdraw function
{
    if (cdraw <= 0){
        cout << "Luoton nostovirhe: nolla tai negatiivinen summa!" << endl;
        return false;

    } else if (cdraw - saldo < luottoRaja){
        cout << "Luoton nosto liian suuri! Max. nosto: " << endl;
        return false;

    } else {
        saldo -= cdraw;
        cout << "Luoton nosto onnistui summalla " << cdraw << ". Luottosaldo: " << saldo << endl;
        return true;
    }
}
