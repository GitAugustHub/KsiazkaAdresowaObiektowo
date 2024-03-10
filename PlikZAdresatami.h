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
    const string nazwaTymczasowegoPlikuZAdresatami;
    int idOstatniegoAdresata;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    // int pobierzUzytkownikaZDanychOddzielonychPionowymiKreskami();
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    int pobierzZPlikuIdOstatniegoAdresata();
    void usunPlik(string nazwaPlikuZRozszerzeniem); // moze przeniesc do metodPomocniczych?
    void zmienNazwePliku(string staraNazwa, string nowaNazwa); // moze przeniesc do metodPomocniczych?
    
public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI, string NAZWATYMCZASOWEGOPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI), nazwaTymczasowegoPlikuZAdresatami(NAZWATYMCZASOWEGOPLIKUZADRESATAMI) 
    {
    }; // konstruktor z dostepem do chronionych nazw plikow
    
    void dopiszAdresataDoPliku();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika); 
    int pobierzIdOstatniegoAdresata();
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    
};

#endif