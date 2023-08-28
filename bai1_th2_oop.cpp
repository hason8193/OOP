#include<iostream>

using namespace std;

typedef struct PHAN_SO{
    int tu;
    int mau;
}PS;

PS operator +(PS p1, PS p2){
    PS p;
    p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    p.mau = p1.mau * p2.mau;
    return p;
}

PS operator -(PS p1, PS p2){
    PS p;
    p.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    p.mau = p1.mau * p2.mau;
    return p;
}

PS operator *(PS p1, PS p2){
    PS p;
    p.tu = p1.tu * p2.tu;
    p.mau = p1.mau * p2.mau;
    return p;
}

PS operator /(PS p1, PS p2){
    PS p;
    p.tu = p1.tu * p2.mau;
    p.mau = p1.mau * p2.tu;
    return p;
}

istream & operator >> (istream &in, PS &p){
    cout << "Tu: ";
    in >> p.tu;
    cout << "Mau: ";
    in >> p.mau;
    return in;
}

ostream & operator << (ostream &out, PS &p){
    out << p.tu << "/" << p.mau;
    return out;
}

int main(){
    PS p1, p2, p3, p4, p5,p6;
    cout << "Nhap p1:";
    cin >> p1;
    cout << "Nhap p2:";
    cin >> p2;
    p3 = p1 + p2;
    cout << "Tong bang:" << p3 << endl;
    p4 = p1 - p2;
    cout << "Hieu bang:" << p4 << endl;
    p5 = p1 * p2;
    cout << "Tich bang:" << p5 << endl;
    p6 = p1 / p2;
    cout << "Thuong bang:" << p6 << endl;
}
