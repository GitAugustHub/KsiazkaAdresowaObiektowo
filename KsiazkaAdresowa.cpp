#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    idZalogowanegoUzytkownika = pobierzIdZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        return true;
    }
    else return false;
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer -> dodajAdresata(); // z uwagi na AdresatMeneger *KsiazkaAdresowa::adresatMeneger
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::przekazIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void KsiazkaAdresowa::wyswietlAdresatow()
{
    adresatMenedzer -> wyswietlWszystkichAdresatow();
}