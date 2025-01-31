#include "asiakas.h"
#include <iostream>
using namespace std;

Asiakas::Asiakas(string name, double creditlimit):nimi(name),kayttotili(name),luottotili(name,creditlimit)
{
    cout << "Pankkitili luotu henkilolle: " << name << endl;
    cout << "Luottotili luotu henkilolle: " << name << ", luottoraja: " << creditlimit << endl;
    cout << "Asiakkuus luotu henkilolle: " << name << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Debit-tilin saldo: " << kayttotili.getBalance() << endl;           // private member from Pankkitili-class
    cout <<  "Credit-tilin saldo: " << luottotili.getBalance() << endl << endl; // private member from Luottotili-class
}

bool Asiakas::talletus(double debitDeposit)
{
    return kayttotili.deposit(debitDeposit);
}

bool Asiakas::nosto(double debitDraw)
{
    return kayttotili.withdraw(debitDraw);
}

bool Asiakas::luotonMaksu(double creditDepo)
{
    return luottotili.deposit(creditDepo);
}

bool Asiakas::luotonNosto(double creditDraw)
{
    return luottotili.withdraw(creditDraw);
}

bool Asiakas::tiliSiirto(double transfer, Asiakas &tili) //Asiakas & = reference to Asiakas-object (bank account)
{
    if (transfer > kayttotili.getBalance()){
        cout << "Virhe tilisiirrossa: varat liian pienet." << endl;
        return false;
    } else if (transfer < 0){
        cout << "Virhe tilisiirrossa: negatiivinen summa." << endl;
        return false;
    } else {
        cout << "Summa "<< transfer << " siirretaan tilille: " << tili.getNimi() << endl;
        cout << "Petteri Pankkitili: ";
        kayttotili.withdraw(transfer);

        cout << tili.getNimi() << " Pankkitili: ";
        tili.kayttotili.deposit(transfer);

        return true;
    }
}
