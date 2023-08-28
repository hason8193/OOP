#include<iostream>

using namespace std;

class PhanSo{
    private:
    int tu, mau;
    public:
    PhanSo(){
        tu = 0;
        mau = 0;
    }
    PhanSo(int tu, int mau){
        this->tu = tu;
        this->mau = mau;
    }
    ~PhanSo(){

    }
    friend istream& operator >> (istream &is, PhanSo &p){
        is >> p.tu >> p.mau;
        while(p.mau == 0){
            is >> p.mau;
        }
        return is;
    }
    friend ostream& operator << (ostream &os, PhanSo &p){
        os << p.tu << "/" << p.mau;
        return os;
    }
    PhanSo operator + (PhanSo &a){
        PhanSo b;
        b.tu = tu * a.mau  + a.tu * mau;
        b.mau = mau * a.mau;
        return b;
    }
    PhanSo operator - (PhanSo &a){
        PhanSo b;
        b.tu = tu * a.mau  - a.tu * mau;
        b.mau = mau * a.mau;
        return b;
    }
    PhanSo operator * (PhanSo &a){
        PhanSo b;
        b.tu = tu * a.tu;
        b.mau = mau * a.mau;
        return b;
    }
    PhanSo operator / (PhanSo &a){
        PhanSo b;
        b.tu = tu * a.mau;
        b.mau = mau * a.tu;
        return b;
    }
};

int main(){
    PhanSo p1, p2, p3;
    cout << "Nhap tu va mau cua p1:";
    cin >> p1;
    cout << "Nhap tu va mau cua p2:";
    cin >> p2;
    p3 = p1 + p2;
    cout << "Tong hai phan so la: " << p3 << endl;
    p3 = p1 - p2;
    cout << "Hieu hai phan so la: " << p3 << endl;
    p3 = p1 * p2;
    cout << "Tich hai phan so la: " << p3 << endl;
    p3 = p1 / p2;
    cout << "Thuong hai phan so la: " << p3 << endl;
}
