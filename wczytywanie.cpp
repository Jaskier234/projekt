#include "wczytywanie.h"
#include <iostream>
#include <fstream>

using namespace std;

fstream plik;

void zapisz_int(int b)
{
    char t[4];
    for(int i=0;i<4;i++)
    {
        t[i]=b%256;
        b/=256;
    }
    plik.write(t,4);
}
void zapisz_string(string s)
{
    // długość zawsze krótsza niż 255
    char t[260];
    t[0]=s.length();
    for(unsigned int i=0;i<s.length();i++)
    {
        t[i+1]=s[i];
    }
    plik.write(t,s.length()+1);
}

void zapisz_plyte(Plyta q)
{
    zapisz_string(q.nazwa);
    zapisz_string(q.wykonawcy);
    zapisz_int(q.liczba_sekund);
    zapisz_int(q.utwory.size());
    for(int i=0;i<q.utwory.size();i++)
    {
        zapisz_string(q.utwory[i]);
    }
    zapisz_string(q.rodzaj);
}

void zapisz(Baza d)
{
    plik.open("baza.bin", ios::binary | ios::out );
    zapisz_int(d.baza.size());
    for( int i=0;i<d.baza.size();i++)
    {
       zapisz_plyte (d.baza[i]);
    }
    plik.close();
}


int wczytaj_int()
{
    int x=0, waga=1;
    char t[4];
    plik.read(t,4);
    for (int i=0;i<4;i++)
    {
       x+=((unsigned char)t[i])*waga;
       waga*=256;
    }
    return x;
}
string wczytaj_string()
{
    char t[1];
    plik.read(t,1);
    char b[261];
    plik.read(b,t[0]);
    string k;
    for(int i=0;i<t[0];i++)
    {
        k+=b[i];
    }
    return k;

}

Plyta wczytaj_plyte()
{
    string nazwa = wczytaj_string();
    string wykonawcy = wczytaj_string();
    int ls = wczytaj_int();
    vector <string> utw;
    int n = wczytaj_int();
    for(int i=0; i<n; i++)
        utw.push_back(wczytaj_string());
    string rodzaj = wczytaj_string();
    return Plyta(nazwa,wykonawcy,ls,utw,rodzaj);
}

Baza wczytaj()
{
    plik.open("baza.bin", ios::binary | ios::in );
    int n = wczytaj_int();
    Baza b;
    for(int i=0; i<n; i++)
    {
        b.baza.push_back( wczytaj_plyte() );
    }
    plik.close();
    return b;
}
