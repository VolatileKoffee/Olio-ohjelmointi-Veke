#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include <string>
#include "pankkitili.h"
using namespace std;

class Luottotili : public Pankkitili // child class : parent class
{
public:
    Luottotili(string, double);
    bool deposit(double) override;
    bool withdraw(double) override;
protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
