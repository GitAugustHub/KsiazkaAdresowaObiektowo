#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    int idOstatniegoAdresata;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    string pobierzLiczbe();
    Adresat pobierzDaneAdresata();
    int pobierzUzytkownikaZDanychOddzielonychPionowymiKreskami();
    int zwrocNumerLiniiSzukanegoAdresata();
    void usunWybranaLinieWPliku();
    int pobierzZPlikuIdOstatniegoAdresata();
    void usunPlik();
    void zmienNazwePliku();
    
public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {}; // konstruktor z dostepem do chronionej nazwy pliku
    void dopiszAdresataDoPliku();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku; 
    int pobierzIdOstatniegoAdresata();
    void usunAdresata();
    
};

#endif