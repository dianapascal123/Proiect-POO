#include "Multime_perechi.h"

Multime_perechi::Multime_perechi(int n)
{
    dim = n;
    p = new Pereche[n];
}

Multime_perechi::~Multime_perechi()
{
    delete []p;
}


void Multime_perechi::set_px(int i, int xx)
{
    p[i].x = xx;

}
void Multime_perechi::set_py(int i, int yy)
{
    p[i].y = yy;

}
Multime_perechi& Multime_perechi::operator = (const Multime_perechi& o)
{
    if (this->p != o.p)
    {
        this->p = new Pereche [o.dim];
        this->dim = o.dim;
        for (int i = 0; i < o.dim; i++)
            this->p[i] = o.p[i];
    }
    return (*this);
}
istream& operator >> (istream& in, Multime_perechi& o)
{
    in >> o.dim;
    for (int i = 0;  i < o.dim; i++)
        in >> o.p[i].x >> o.p[i].y;
    return in;
}
ostream& operator << (ostream& out, Multime_perechi& o)
{
    for (int i = 0; i < o.dim; i++)
        out << o.p[i] << " ";
    return out;
}

