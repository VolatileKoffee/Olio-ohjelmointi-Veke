#include "chef.h"
#include <iostream>
using namespace std;

Chef::Chef(string n):chefName(n)
{
    cout << "Chef constructor. Starting.." << endl;
}

Chef::~Chef()
{
    cout << "Chef destructor. Ending.." <<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int salad)
{
    int portions = salad / 5;
    return portions;
}

int Chef::makeSoup(int soup)
{
    int portions = soup / 3;
    return portions;
}

