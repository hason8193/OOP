#include<iostream>

using namespace std;

class Phan_So{
    private:
    int tu, mau;
    public:
    Phan_So(){
        tu = 0;
        mau = 1;
    }
    Phan_So(int tu, int mau){
        this->tu = tu;
        this->mau = mau;
    }
    void Nhap(){
        cin >> tu >> mau;
        if (mau == 0) cin >> mau;
    }
    void Xuat(){
        cout << tu << "/" << mau << endl;
    }
    int gcd(int tu, int mau) {
    return mau == 0 ? abs(tu) : gcd(mau, tu % mau);
}

void Rut_Gon() {
    int g = gcd(tu, mau);
    tu /= g;
    mau /= g;
}
};
int main(){
    Phan_So A;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        A.Nhap();
        A.Rut_Gon();
        A.Xuat();
    }
}