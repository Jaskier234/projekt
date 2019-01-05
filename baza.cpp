#include "baza.h"

using namespace std;

void Baza::dodawanie(Plyta a)
{
    for(int i=0; i<baza.size(); i++)
    {
        if(baza[i].nazwa == a.nazwa)
        {
            cout<<"Płyta o podanej nazwie już wystęuje w bazie\n";
            return;
        }
    }
    baza.push_back(a);
}

void Baza::usuwanie(string s)
{
    for(int i=0; i<baza.size(); i++)
    {
        if(baza[i].nazwa == s)
        {
            baza.erase( baza.begin() + i );
            return;
        }
    }
    cout<<"Nie znaleziono podanej płyty\n";
}

void Baza::wyszukaj_album(string s)
{
    for(int i=0; i<baza.size(); i++)
    {
        if(baza[i].nazwa == s)
        {
            baza[i].wyswietl();
            return;
        }
    }
}

void Baza::wyszukaj_utwor(string s)
{
    for(int i=0; i<baza.size(); i++)
    {
        for(int j=0; j<baza[i].utwory.size(); j++)
        {
            if(baza[i].utwory[j] == s)
            {
                baza[i].wyswietl();
            }
        }
    }
}

bool cmp(Plyta a, Plyta b, string kryt)
{
    if(kryt == "nazwa")
        return a.nazwa < b.nazwa;

    if(kryt == "wykonawca")
        return a.wykonawcy < b.wykonawcy;

    if(kryt == "czas")
        return a.liczba_sekund < b.liczba_sekund;

    if(kryt == "gatunek")
        return a.rodzaj < b.rodzaj;

    cout<<"Niepoprawne kryterium\n";
}

void Baza::sortowanie(string kryt)
{
    int n = baza.size();
    for(int i=1; i<n; i++)
    {
        int it = i;
        while( it > 0 && cmp(baza[it],baza[it-1],kryt) /*baza[it] < baza[it-1]*/ )
        {
            Plyta p = baza[it-1];
            baza[it-1] = baza[it];
            baza[it] = p;
            it--;
        }
    }
}
