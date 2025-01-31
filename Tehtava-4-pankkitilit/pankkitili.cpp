#include "pankkitili.h"
#include <iostream>
using namespace std;

Pankkitili::Pankkitili(string bname):omistaja(bname){}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double bdepo) // Debit deposit function
{
    if (bdepo < 0){
        cout << "Debit-talletusvirhe: summa liian pieni tai negatiivinen!" << endl;
        return false;

    } else {
        saldo = saldo + bdepo;
        cout << "Debit-talletus onnistui summalla " << bdepo << ". Debit-saldo: " << saldo << endl;
        return true;
    }
}

bool Pankkitili::withdraw(double bdraw) // Debit withdraw function
{
    if (bdraw > saldo){
        cout << "Debit-nostovirhe: saldo liian pieni. Saldo: " << saldo << endl;
        return false;

    } else if (bdraw < 0){
        cout << "Debit-nostovirhe: nosto negatiivinen!" << endl;
        return false;

    } else {
        saldo = saldo - bdraw;
        cout << "Debit-nosto onnistui summalla " << bdraw << ". Debit-saldo: " << saldo << endl;
        return true;
    }
}
