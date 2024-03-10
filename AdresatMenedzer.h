#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <stdio.h> // zamiast <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
{
    const int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    Adresat podajDaneNowegoAdresata(); 
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlWyszukanychAdresatow();
    int podajIdWybranegoAdresata();

public:
    AdresatMenedzer(string NAZWAPLIKUZADRESATAMI, string NAZWATYMCZASOWEGOPLIKUZADRESATAMI, int IDZALOGOWANEGOUZYTKOWNIKA)
        : plikZAdresatami(NAZWAPLIKUZADRESATAMI, NAZWATYMCZASOWEGOPLIKUZADRESATAMI), idZalogowanegoUzytkownika(IDZALOGOWANEGOUZYTKOWNIKA)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdZalogowanegoUzytkownika();
    // nalezy utworzyc setter dla pola idZalogowanego Uzytkownika w tej klasie
    void pobierzAdresatowZalogowanegoUzytkownikaZPliku();
    // i wywolac ja w metodzie logowanieUzytkownika() w klasie KsiazkaAdresowa - po ustawieniu idZUw klasieAdresatMenedzer

};

#endif