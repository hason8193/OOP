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
}

void So_Sanh(PS p1, PS p2)
{
    if ( (p1.tu * p2.mau - p2.tu * p1.mau) > 0) cout << "p1 lon hon p2";
    else if ( (p1.tu * p2.mau - p2.tu * p1.mau) < 0) cout << "p2 lon hon p1";
    else cout << "p1 bang p2";
}

int main()
{
    PS p1, p2;
    cout << "Tu va mau cua phan so p1 lan luot la:";
    cin >> p1.tu >> p1.mau;
    cout << "Tu va mau cua phan so p2 lan luot la:";
    cin >> p2.tu >> p2.mau;
    Rut_Gon(p1);
    Rut_Gon(p2);
    So_Sanh(p1, p2);
    return 0;
}
