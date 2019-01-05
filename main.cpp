#include <iostream>
#include "wczytywanie.h"
#include <fstream>

using namespace std;

int main()
{
    Baza b = wczytaj();

    vector<string> s;
   // s.push_back("utwór");
    b.dodawanie( Plyta("Nie mam pojêcia", "Lady pank", 132, s, "pank") );

    zapisz(b);

    return 0;
}
