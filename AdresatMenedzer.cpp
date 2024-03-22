#include "AdresatMenedzer.h"
#include "KsiazkaAdresowa.h"


void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    metodyPomocnicze.czyscEkran();
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    cout << "Nowy adresat zostal dodany" << endl;
    else
    cout << "Nie udalo sie dodac nowego adresata" << endl;
    metodyPomocnicze.czekajNaWcisniecieKlawisza();

}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);

    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    string imie;
    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();
    adresat.ustawImie(imie);
    // adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    string nazwisko;
    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    adresat.ustawNazwisko(nazwisko);
    // adresat.ustawNazwisko(nazwisko) = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.ustawNazwisko(nazwisko));

    string numerTelefonu;
    cout << "Podaj numer telefonu: ";
    numerTelefonu = metodyPomocnicze.wczytajLinie();
    adresat.ustawNumerTelefonu(numerTelefonu);

    string email;
    cout << "Podaj email: ";
    email = metodyPomocnicze.wczytajLinie();
    adresat.ustawEmail(email);

    string adres;
    cout << "Podaj adres: ";
    adres = metodyPomocnicze.wczytajLinie();
    adresat.ustawAdres(adres);

    return adresat;
}

int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return ID_ZALOGOWANEGO_UZYTKOWNIKA;
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

void AdresatMenedzer::pobierzAdresatowZalogowanegoUzytkownikaZPliku()
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:         " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    metodyPomocnicze.czyscEkran();
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    metodyPomocnicze.czekajNaWcisniecieKlawisza();
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = metodyPomocnicze.wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}


void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    metodyPomocnicze.czyscEkran();
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        metodyPomocnicze.wczytajLinie();
        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    metodyPomocnicze.czekajNaWcisniecieKlawisza();
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    metodyPomocnicze.czyscEkran();
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        metodyPomocnicze.wczytajLinie();
        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    metodyPomocnicze.czekajNaWcisniecieKlawisza();
}

void AdresatMenedzer::usunAdresata()
{
    
    int idUsuwanegoAdresata = 0;

    metodyPomocnicze.czyscEkran();
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranaLinieWPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                metodyPomocnicze.czekajNaWcisniecieKlawisza();
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                metodyPomocnicze.czekajNaWcisniecieKlawisza();
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        metodyPomocnicze.czekajNaWcisniecieKlawisza();
    }
}