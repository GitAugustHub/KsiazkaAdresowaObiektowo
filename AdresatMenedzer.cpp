#include "AdresatMenedzer.h"

Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    adresat.ustawId(++idOstatniegoAdresata);

    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    string imie;
    cout << "Podaj imie: ";
    adresat.ustawImie(imie);
    // adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    string nazwisko;
    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(nazwisko);
    // adresat.ustawNazwisko(nazwisko) = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.ustawNazwisko(nazwisko));

    string numerTelefonu;
    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(numerTelefonu);

    string email;
    cout << "Podaj email: ";
    adresat.ustawEmail(email);

    string adres;
    cout << "Podaj adres: ";
    adresat.ustawAdres(adres);

    return adresat;
}


void wyswietlDaneAdresata();
void wyswietlWyszukanychAdresatow();
int podajIdWybranegoAdresata();