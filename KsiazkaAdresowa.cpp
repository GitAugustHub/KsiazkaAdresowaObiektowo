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
    idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
    cout << idZalogowanegoUzytkownika;
    cin.get();
    // w tym miejscu UzytkownikManager powinien pobrac idZalogowanegoUzytkownika przy pomocy gettera
}