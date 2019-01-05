#include <vector>
#include <string>

using namespace std;

struct Plyta
{
    string nazwa;
    string wykonawcy;
    int liczba_sekund;
    vector <string> utwory;
    string rodzaj;

    Plyta (string, string, int, vector <string>, string);
    void wyswietl();
};

