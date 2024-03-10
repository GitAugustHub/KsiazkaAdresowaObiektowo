#include "AdresatMenedzer.h"
#include "KsiazkaAdresowa.h"

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata)
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

void AdresatMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    idZalogowanegoUzytkownika = uzytkownikMenedzer.przekazIdZalogowanegoUzytkownika();
}

int AdresatMenedzer::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocnicze metodyPomocnicze;
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int AdresatMenedzer::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    MetodyPomocnicze metodyPomocnicze;
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void pobierzAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = 
}
void wyswietlDaneAdresata();
void wyswietlWyszukanychAdresatow();
int podajIdWybranegoAdresata();