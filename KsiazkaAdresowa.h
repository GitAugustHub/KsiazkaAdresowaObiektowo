#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer; // dlaczego musi tu być * ? ponieważ pojawia się błąd <no default constructor exists for class "AdresatMenedzer">
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), plikZAdresatami(nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami) 
    {
    };
    bool czyUzytkownikJestZalogowany();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void dodajAdresata();
    int pobierzIdZalogowanegoUzytkownika();
    int przekazIdZalogowanegoUzytkownika();
    void wyswietlAdresatow();
};

#endif
