#ifndef CHEF_H
#define CHEF_H
#include <string>
using namespace std;

class Chef {
public:
    Chef(string);
    ~Chef();
    string getName();
    int makeSalad(int); //int = annokseen tarvittava määrä aineksia
    int makeSoup(int);  //int = annokseen tarvittava määrä aineksia
private:
protected:
    string chefName;
};

#endif // CHEF_H
