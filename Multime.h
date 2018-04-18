#pragma once
#include <iostream>

using namespace std;

class Multime
{
    int *v;
    int dim;
public:
    Multime (int = 0);
    ~Multime();
    int get_v (int);
    int get_dim ();
    Multime (const Multime&);
    void elimina_duplicate ();
    Multime& operator = (const Multime&);
    Multime operator + (const Multime&);
    Multime operator - (const Multime&);
    Multime operator * (const Multime&);
    friend istream& operator >> (istream&, Multime&);
    friend ostream& operator << (ostream&, Multime&);
    bool operator == (const Multime&);
    bool operator != (const Multime&);
    bool operator < (const Multime&);
    friend int cmp (const void *o1, const void *o2);
};


