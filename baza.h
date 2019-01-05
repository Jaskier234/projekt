#include <iostream>
#include "plyta.h"
#include <vector>

using namespace std;

struct Baza
{
    //każda nazwa albumu występuje tylko raz
    vector <Plyta> baza;

    void dodawanie (Plyta);
    void usuwanie (string);
    void wyszukaj_album (string);
    void wyszukaj_utwor (string);
    void sortowanie (string);
};
