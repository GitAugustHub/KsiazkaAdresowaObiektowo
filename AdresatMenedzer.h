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
    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata();
    void wyswietlWyszukanychAdresatow();
    int podajIdWybranegoAdresata();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) 
    {
        plikZAdresatami.wczytajAdresatowZPliku();
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    // nalezy utworzyc setter dla pola idZalogowanego Uzytkownika w tej klasie
    // nalezy utworzyc publiczna metode pobierzAdresatowZalogowanegoUzytkownikaZPliku() i wywolac ja w metodzie logowanieUzytkownika() w klasie KsiazkaAdresowa - po ustawieniu idZUw klasieAdresatMenedzer

};

#endif