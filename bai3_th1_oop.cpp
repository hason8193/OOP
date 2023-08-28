#include <iostream>

using namespace std;

typedef struct PHANSO
{
    int tu;
    int mau;
}PS;

void Tong(PS p1, PS p2)
{
    if (p1.mau == p2.mau) cout << p1.tu + p2.tu << "/" << p1.mau << endl;
    else cout << (p1.tu * p2.mau + p2.tu * p1.mau) << "/" << p1.mau * p2.mau << endl;
}

void Hieu(PS p1, PS p2)
{
    if (p1.mau == p2.mau) cout << p1.tu - p2.tu << "/" << p1.mau << endl;
    else cout << (p1.tu * p2.mau - p2.tu * p1.mau) << "/" << p1.mau * p2.mau << endl;
}

void Tich(PS p1, PS p2)
{
    cout << p1.tu * p2.tu << "/" << p1.mau * p2.mau << endl;
}

void Thuong(PS p1, PS p2)
{
    cout << p1.tu * p2.mau << "/" << p1.mau * p2.tu << endl;
}

int main()
{
    PS p1, p2;
    cout << "Tu va mau cua phan so p1 lan luot la:";
    cin >> p1.tu >> p1.mau;
    cout << "Tu va mau cua phan so p2 lan luot la:";
    cin >> p2.tu >> p2.mau;
    cout << "Tong:";
    Tong(p1, p2);
    cout << "Hieu:";
    Hieu(p1, p2);
    cout << "Tich:";
    Tich(p1, p2);
    cout << "Thuong:";
    Thuong(p1, p2);
    return 0;
}
