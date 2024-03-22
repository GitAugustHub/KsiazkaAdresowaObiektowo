#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    MetodyPomocnicze metodyPomocnicze;
    KsiazkaAdresowa ksiazkaAdresowa("/Users/macbook/Desktop/PROGRAM/PROJEKTY/C++_projekty/16_KsiazkaAdresowaObiektowoProjektArtura/Uzytkownicy.txt", "/Users/macbook/Desktop/PROGRAM/PROJEKTY/C++_projekty/16_KsiazkaAdresowaObiektowoProjektArtura/Adresaci.txt", "/Users/macbook/Desktop/PROGRAM/PROJEKTY/C++_projekty/16_KsiazkaAdresowaObiektowoProjektArtura/Adresaci_tymczasowy.txt");

    char wybor;

    while (true)
    {
        if (!ksiazkaAdresowa.czyUzytkownikJestZalogowany())
        {
            metodyPomocnicze.czyscEkran();
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                metodyPomocnicze.czekajNaWcisniecieKlawisza();
                break;
            }
        }
        else 
        {
            metodyPomocnicze.czyscEkran();
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
            cout << "4. Wyswietl adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> wybor;

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukiwaniePoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukiwaniePoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                // ksiazkaAdresowa.edytujAdresata();
                cout << "Edytowanie jeszcze nie działa" << endl;
                cin.get();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                metodyPomocnicze.czekajNaWcisniecieKlawisza();
                break;
            }
        }
    }

    return 0;
}
// dla wylogowania we wszystkich klasach idZalogowU musi byc wyzerowane tak jak vector Adresaci