#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "PlikZAdresatami.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer; // bez wskaznika na obiekt klasy adresatMenedzer pojawia się błąd <no default constructor exists for class "AdresatMenedzer"> jest to potrzebne by obiekt dopiero byl tworzony po zalogowaniu, wazne jest ustawienie w konstruktorze klasy wartosci wskaznika na NULL
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), plikZAdresatami(nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami) 
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
    void usunAdresata();
    void edytujAdresata();
    int pobierzIdZalogowanegoUzytkownika();
    int przekazIdZalogowanegoUzytkownika();
    void wyswietlAdresatow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyszukiwaniePoImieniu();
    void wyszukiwaniePoNazwisku();
};

#endif
