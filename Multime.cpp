#include "Multime.h"

Multime::Multime (int n )
{
    dim = n;
    v = new int[dim];
}

Multime::~Multime()
{
    delete []v;
}

int Multime::get_v(int i)
{
    return v[i];
}

int Multime::get_dim()
{
    return dim;
}

Multime::Multime (const Multime& o)
{
    dim = o.dim;
    v = new int[dim];
    for (int i = 0; i < dim; i++)
        v[i] = o.v[i];
}

void Multime::elimina_duplicate()
{
    int *a = new int[dim];
    for (int  i = 0; i < dim; i++)
        a[i] = v[i];
    int dim_a = dim;
    for (int i = 0; i < dim_a - 1; i++)
    {
        int ok = 0;
        for (int j = i + 1; j < dim_a && !ok; j++)
        {
            if (a[i] == a[j])
                ok = 1;
        }
        if (ok)
        {
            a[i] = a[dim_a - 1];
            dim_a--;
        }
    }
    dim = dim_a;
    delete []v;
    v = a;
}

Multime& Multime::operator = (const Multime& o)
{
    if (this->v != o.v)
    {
        this->v = new int[o.dim];
        this->dim = o.dim;
        for (int i = 0; i < o.dim; i++)
            this->v[i] = o.v[i];
    }
    return (*this);
}

Multime Multime::operator + (const Multime& o)
{
    Multime obj(dim + o.dim);
    for (int i = 0; i < dim; i++)
        obj.v[i] = v[i];
    for (int i = 0; i < o.dim; i++)
        obj.v[dim + i] = o.v[i];
    obj.elimina_duplicate();
    return obj;
}

Multime Multime::operator - (const Multime& o)
{

    int *a = new int[dim];
    int dim_a = 0;
    for (int i = 0; i < dim; i++)
    {
        int ok = 0;
        for (int j = 0; j < o.dim && !ok; j++)
            if (v[i] == o.v[j]) ok = 1;
        if (ok == 0)
            a[dim_a++] = v[i];
    }
    Multime obj(dim_a);
    obj.v = a;
    return obj;
}

Multime Multime::operator * (const Multime& o)
{

    int *a = new int[dim + o.dim];
    int dim_a = 0;
    for (int i = 0; i < dim; i++)
        {   int ok = 0;
            for (int j = 0; j < o.dim && !ok; j++)
            if (v[i] == o.v[j]) ok = 1;
            if (ok) a[dim_a++] = v[i];
        }
    Multime obj(dim_a);
    obj.v = a;
    return obj;
}

istream& operator >> (istream& in, Multime& v1)
{
    in >> v1.dim;
    for (int i = 0; i < v1.dim; i++)
        in >> v1.v[i];
    return in;
}



ostream& operator << (ostream& out, Multime& o)
{
    cout << "Elementele multimii sunt:\n";
    for (int i = 0; i < o.dim; i++)
        out << "v[" << i << "]=" << o.v[i] << "\n";
    out << "\n";
    return out;
}

bool Multime::operator == (const Multime& o)
{
    return dim == o.dim;
}

bool Multime::operator != (const Multime& o)
{
    return dim != o.dim;
}

bool Multime::operator < (const Multime& o)
{
    return dim < o.dim;
}


