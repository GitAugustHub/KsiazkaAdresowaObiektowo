#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <stdio.h> // zamiast <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class AdresatMenedzer
{
    int idZalogowanegoUzytkownika;
    // nalezy utworzyc setter dla pola idZalogowanego Uzytkownika w tej klasie
    // nalezy utworzyc publiczna metode pobierzAdresatowZalogowanegoUzytkownikaZPliku() i wywolac ja w metodzie logowanieUzytkownika() w klasie KsiazkaAdresowa - po ustawieniu idZUw klasieAdresatMenedzer

};

#endif