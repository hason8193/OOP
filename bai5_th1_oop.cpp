#include <iostream>
#include <string>

using namespace std;

typedef struct THONG_TIN_HS
{
    string name;
    float toan;
    float van;
}TT;

void Nhap(TT &hs)
{
    cout << "Nhap ten:";
    getline(cin, hs.name);
    cout << "Nhap diem toan:";
    cin >> hs.toan;
    cout << "Nhap diem van:";
    cin >> hs.van;
}

float DTB(TT hs)
{
    return ( hs.toan + hs.van ) / 2.0;
}

int main()
{
    TT hs;
    Nhap(hs);
    cout << "Hoc sinh " << hs.name << " co diem trung binh:" << DTB(hs);
    return 0;
}
