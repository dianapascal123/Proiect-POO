#pragma once
#include <iostream>

using namespace std;
class Multime_perechi;
class Pereche
{
    friend class Multime_perechi;
    int x, y;
public:
    Pereche (int = 0, int = 0);
    Pereche (const Pereche&);
    Pereche& operator = (const Pereche&);
    friend istream& operator >> (istream&, Pereche&);
    friend ostream& operator << (ostream&, Pereche&);
    friend istream& operator >> (istream&, Multime_perechi&);
    friend ostream& operator << (ostream&, Multime_perechi&);
};


