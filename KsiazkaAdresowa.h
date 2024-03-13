#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer; // bez wskaznika na obiekt klasy adresatMenedzer pojawia się błąd <no default constructor exists for class "AdresatMenedzer"> jest to potrzebne by obiekt dopiero byl tworzony po zalogowaniu, wazne jest ustawienie w konstruktorze klasy wartosci wskaznika na NULL
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string NAZWA_PLIKU_Z_UZYTKOWNIKAMI, string NAZWA_PLIKU_Z_ADRESATAMI, string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI) : uzytkownikMenedzer(NAZWA_PLIKU_Z_UZYTKOWNIKAMI), plikZAdresatami(NAZWA_PLIKU_Z_ADRESATAMI, NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI) 
    {
        adresatMenedzer = NULL; //wazne jest ustawienie w konstruktorze klasy wartosci wskaznika na NULL by nie wskazywal jakiegos istotnego miejsca w pamieci
    };
    ~KsiazkaAdresowa() // destruktor sprzata po klasie
    {
        delete adresatMenedzer; // usuwamy to co wskazywal wskaznik
        adresatMenedzer = NULL;
    };
    bool czyUzytkownikJestZalogowany();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    int pobierzIdZalogowanegoUzytkownika();
    int przekazIdZalogowanegoUzytkownika();
    void wyswietlAdresatow();
};

#endif
