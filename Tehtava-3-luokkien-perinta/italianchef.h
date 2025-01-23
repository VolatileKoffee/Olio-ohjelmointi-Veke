#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include <string>
#include "chef.h"
using namespace std;

class ItalianChef : public Chef {
public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string,int,int);
private:
    int makepizza(int,int);
    string password = "pizza";
    //int flour; //unused
    //int water; //unused
protected:
};

#endif // ITALIANCHEF_H
