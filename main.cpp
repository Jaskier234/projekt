#include <iostream>
#include "wczytywanie.h"
#include <fstream>

using namespace std;

int main()
{
    Baza b = wczytaj();

    vector<string> s;
   // s.push_back("utw�r");
    b.dodawanie( Plyta("Nie mam poj�cia", "Lady pank", 132, s, "pank") );

    zapisz(b);

    return 0;
}
