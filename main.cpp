#include "Multime_perechi.h"
#include <fstream>
#include <cstdlib>
using namespace std;

int cmp (const void *o1, const void *o2)
{
    const Multime *obj1 = (const Multime *) o1;
    const Multime *obj2 = (const Multime *) o2;
    if (obj1->dim == obj2->dim)
        return 0;
    if (obj1->dim > obj2->dim)
        return 1;
    return -1;

}
Multime_perechi prod_cartezian (Multime& o1, Multime& o2)
{
    int dim1 = o1.get_dim();
    int dim2 = o2.get_dim();
    Multime_perechi o3(dim1 * dim2);
    int dim3 = 0;
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            o3.set_px(dim3, o1.get_v(i));
            o3.set_py(dim3, o2.get_v(j));
            dim3++;
        }
    }
    return o3;
}

int main()
{
    ifstream fin ("Multimi.in");
    Multime *m;
    int n;
    fin >> n;
    m = new Multime[n];
    for (int i = 0; i < n; i++)
    {
        fin >> m[i];
        m[i].elimina_duplicate();
    }
    int opt;
    do
    {
        cout << "Introduceti optiunea:\n1-Afisarea multimilor dupa eliminarea duplicatelor\n2-Reuniunea a doua multimi\n3-Diferenta a doua multimi\n4-Intersectia a doua multimi\n5-Produsul cartezian a doua multimi\n6-Ordonarea multimilor dupa numarul de elemente\n7-Iesire\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            {
                for (int i = 0; i < n; i++)
                    cout << m[i];
                cout << "\n";
                break;
            }
        case 2:
            {
                int poz1, poz2;
                do
                {
                    cout << "Introduceti indicii multimilor pentru care vreti sa faceti reuniunea. Acestia trebuie sa fie intre 1 si " << n << "(numarul de multimi):\n";
                    cin >> poz1 >> poz2;
                    poz1--;
                    poz2--;
                }
                while (poz1 < 0 || poz1 > n-1 || poz2 < 0 || poz2 > n-1);
                Multime obj = m[poz1] + m[poz2];
                cout << "Multimea " << poz1 + 1 << " + multimea " << poz2 + 1 << ":\n" << obj << "\n";
                break;
            }
        case 3:
            {
                int poz1, poz2;
                do
                {
                    cout << "Introduceti indicii multimilor pentru care vreti sa faceti diferenta. Acestia trebuie sa fie intre 1 si " << n << "(numarul de multimi):\n";
                    cin >> poz1 >> poz2;
                    poz1--;
                    poz2--;
                }
                while (poz1 < 0 || poz1 > n-1 || poz2 < 0 || poz2 > n-1);
                if (poz1 > poz2)
                   {
                       Multime obj = m[poz1] - m[poz2];
                       cout << "Multimea " << poz1 + 1 << " - multimea " << poz2 + 1 << ":\n" << obj;
                   }
                else
                {
                    Multime obj = m[poz2] - m[poz1];
                    cout << "Multimea " << poz2 + 1 << " - multimea " << poz1 + 1 << ":\n" << obj;
                }
                cout <<"\n";
                break;
            }
        case 4:
            {
                int poz1, poz2;
                do
                {
                    cout << "Introduceti indicii multimilor pentru care vreti sa faceti intersectia. Acestia trebuie sa fie intre 1 si " << n << "(numarul de multimi):\n";
                    cin >> poz1 >> poz2;
                    poz1--;
                    poz2--;
                }
                while (poz1 < 0 || poz1 > n-1 || poz2 < 0 || poz2 > n-1);
                Multime obj = m[poz1] * m[poz2];
                if (obj.get_dim() == 0) cout << "Intersectia este vida\n";
                else cout << "Multimea " << poz1 + 1 << " * multimea " << poz2 + 1 << ":\n" << obj;
                cout << "\n";
                break;
            }
        case 5:
            {
                int poz1, poz2;
                do
                {
                    cout << "Introduceti indicii multimilor pentru care vreti sa faceti produsul cartezian. Acestia trebuie sa fie intre 1 si " << n << "(numarul de multimi):\n";
                    cin >> poz1 >> poz2;
                    poz1--;
                    poz2--;
                }
                while (poz1 < 0 || poz1 > n-1 || poz2 < 0 || poz2 > n-1);
                Multime_perechi obj = prod_cartezian(m[poz1], m[poz2]);
                cout << "Multimea " << poz1 + 1 << " x multimea " << poz2 + 1 << ":\n" << obj <<"\n";
                cout << "\n";
                break;
            }
        case 6:
            {
                qsort (m, n, sizeof(Multime), cmp);
                for (int i = 0; i < n; i++)
                    cout << m[i];
                cout << "\n";
            }
        }
    }
    while (opt >= 1 && opt <= 6);
    return 0;
}
