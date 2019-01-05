#include "baza.h"

using namespace std;

void Baza::dodawanie(Plyta a)
{
    for(int i=0; i<baza.size(); i++)
    {
        if(baza[i].nazwa == a.nazwa)
        {
            cout<<"P³yta o podanej nazwie ju¿ wystêuje w bazie\n";
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
    cout<<"Nie znaleziono podanej p³yty\n";
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
