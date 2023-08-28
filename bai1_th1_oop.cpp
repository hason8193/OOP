#include <iostream>

using namespace std;

typedef struct PHANSO
{
    int tu;
    int mau;
}PS;

void Rut_Gon(PS &p)
{
    for(int i = 1; i <= p.tu; i++)
    {
        if (p.tu % i == 0 && p.mau % i == 0)
        {
            p.tu = p.tu / i;
            p.mau = p.mau / i;
        }
    }
    cout << p.tu << "/" << p.mau;
}

int main()
{
    PS p;
    cout << "Tu va mau cua phan so p lan luot la:";
    cin >> p.tu >> p.mau;
    Rut_Gon(p);
    return 0;
}
