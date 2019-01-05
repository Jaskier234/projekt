#include <iostream>
#include "wczytywanie.h"
#include <fstream>

using namespace std;

int main()
{
    Baza b = wczytaj();


    // dodać cały interfejs
    vector<string> s;
    s.push_back("utwór");
    b.dodawanie( Plyta("Krótka płyta", "Lady pank", 32, s, "pank") );

    s.push_back("utwór 2");
    b.dodawanie( Plyta("Dwa utwory v2.0", "Lady pank", 13, s, "pank") );

    b.sortowanie("czas");

    for(auto it:b.baza)
        it.wyswietl();

    zapisz(b);

    return 0;
}
