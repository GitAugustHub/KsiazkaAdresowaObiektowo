#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    int konwersjaStringNaInt(string liczba);
    string wczytajLinie();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int wczytajLiczbeCalkowita();
};

#endif
