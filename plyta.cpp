#include <iostream>
#include "plyta.h"
#include <vector>

Plyta::Plyta(string n, string w, int ls, vector <string> u, string r )
{
    nazwa = n;
    wykonawcy = w;
    liczba_sekund = ls;
    utwory = u;
    rodzaj = r;
}

void Plyta::wyswietl()
{
    cout<<nazwa<<endl;
}
