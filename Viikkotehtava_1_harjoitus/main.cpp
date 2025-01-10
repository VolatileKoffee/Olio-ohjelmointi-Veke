#include <iostream>

int main()
{
    int a = 4;
    int b = 5;
    int alkutulos, kertominen, lopputulos;

    alkutulos = a * b;  //a ja b kerrotaan keskenään
    kertominen = alkutulos * 2; //kerrotaan kahdella
    lopputulos = kertominen + 1; //lisätään tulokseen yksi

    std::cout << lopputulos << std::endl;
    return 0;
}
