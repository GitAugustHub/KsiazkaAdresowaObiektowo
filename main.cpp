#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("/Users/macbook/Desktop/PROGRAM/PROJEKTY/C++_projekty/16_KsiazkaAdresowaObiektowoProjektArtura/Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    return 0;
}
// dla wylogowania we wszystkich klasach idZalogowU musi byc wyzerowane tak jak vector Adresaci