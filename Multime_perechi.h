#pragma once
#include "Pereche.h"
#include "Multime.h"
using namespace std;
class Multime_perechi
{

    int dim;
    Pereche *p;
public:
    Multime_perechi (int = 0);
    ~Multime_perechi();
    void set_px(int, int);
    void set_py(int, int);
    Multime_perechi& operator = (const Multime_perechi&);
    friend istream& operator >> (istream&, Multime_perechi&);
    friend ostream& operator << (ostream&, Multime_perechi&);
    friend Multime_perechi prod_cartezian (Multime& m1, Multime& m2);
};


