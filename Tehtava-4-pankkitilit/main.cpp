#include <iostream>
#include "asiakas.h"
using namespace std;

int main()
{
    Asiakas bankuserOne("Petteri",1000); // first bank account object
    bankuserOne.showSaldo();

    cout << "Debit-talletus: ";
    int debitdepo;
    cin >> debitdepo;
    bankuserOne.talletus(debitdepo);

    cout << "Debit-nosto: ";
    int debitdraw;
    cin >> debitdraw;
    bankuserOne.nosto(debitdraw);

    cout << "Credit-nosto: ";
    int creditdraw;
    cin >> creditdraw;
    bankuserOne.luotonNosto(creditdraw);

    cout << "Credit-talletus: ";
    int creditdepo;
    cin >> creditdepo;
    bankuserOne.luotonMaksu(creditdepo);

    bankuserOne.showSaldo();


    Asiakas bankuserTwo("Bertta",2000); // second bank account object
    bankuserTwo.showSaldo();

    cout << "Tilin nimi: " << bankuserOne.getNimi() << endl;

    cout << "Tilisiirto henkilolta: " << bankuserOne.getNimi() << ", henkilolle: " << bankuserTwo.getNimi() << endl;
    int transferamount;
    cin >> transferamount;
    bankuserOne.tiliSiirto(transferamount,bankuserTwo);

    cout << "Tilin nimi: " << bankuserTwo.getNimi() << endl;;
    bankuserTwo.showSaldo();

    return 0;
}
