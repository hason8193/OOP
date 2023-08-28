#include<iostream>

using namespace std;

class Diem{
private:
    float Hoanh;
    float Tung;
public:
    void setHoanh(float hoanh){
        Hoanh = hoanh;
    }
    float getHoanh(){
        return Hoanh;
    }
    void setTung(float tung){
        Tung = tung;
    }
    float getTung(){
        return Tung;
    }
    void Tinh_Tien(float dx, float dy){
        Hoanh += dx;
        Tung += dy;
    }
    void nhap(){
        cout << "Nhap hoanh do: ";
        cin >> Hoanh;
        cout << "Nhap tung do: ";
        cin >> Tung;
    }
    void xuat(){
        cout << "Diem la: (" << Hoanh << "," << Tung << ")" << endl;
    }
    Diem(){
        Hoanh = 0;
        Tung = 0;
    }
    Diem(float h, float t){
        Hoanh = h;
        Tung = t;
    }
};
int main() {
    Diem A;
    cout << "Nhap toa do cua A:" << endl;
    A.nhap();
    float dx, dy;
    cout << "Nhap hoanh do va tung do muon tinh tien:";
    cin >> dx >> dy;
    A.Tinh_Tien(dx, dy);
    A.xuat();
    return 0;
}

