#include "Pereche.h"

Pereche::Pereche(int xx, int yy)
{
    x = xx;
    y = yy;
}
Pereche::Pereche(const Pereche& o)
{
    x = o.x;
    y = o.y;
}

Pereche& Pereche::operator = (const Pereche& o)
{
    if ((this->x != o.x) || (this->y != o.y))
    {
        this->x = o.x;
        this->y = o.y;
    }
    return (*this);
}
istream& operator >> (istream& in, Pereche& o)
{
    in >> o.x >> o.y;
    return in;
}

ostream& operator << (ostream& out, Pereche& o)
{
    out << '(' << o.x << ',' << o.y << ")";
    return out;
}
