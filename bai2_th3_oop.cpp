#include<iostream>
#include<math.h>

using namespace std;

class TamGiac{
private:
    float x1, x2, x3, y1, y2, y3;
public:
    TamGiac(){
        x1 = x2 = x3 = y1 = y2 = y3 = 0;
    }
    TamGiac(float x1, float x2, float x3, float y1, float y2, float y3){
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->y1 = y1;
        this->y2 = y2;
        this->y3 = y3;
    }
    ~TamGiac(){};
    void Nhap(){
        cout << "Nhap toa do 3 dinh cua tam giac: " << endl;
        cout << "Dinh 1: ";
        cin >> x1 >> y1;
        cout << "Dinh 2: ";
        cin >> x2 >> y2;
        cout << "Dinh 3: ";
        cin >> x3 >> y3;
    }
    void Xuat(){
    cout << "Toa do 3 dinh cua tam giac la: " << endl;
        cout << "(" << x1 << "," << y1 << ")" << endl;
        cout << "(" << x2 << "," << y2 << ")" << endl;
        cout << "(" << x3 << "," << y3 << ")" << endl;
    }
    void Phong_To(float k){
        x1 *= k; 
        y1 *= k;
        x2 *= k;   
        y2 *= k;
        x3 *= k; 
        y3 *= k;
    }
    void Thu_Nho(float k){
        x1 /= k; 
        y1 /= k;
        x2 /= k;   
        y2 /= k;
        x3 /= k; 
        y3 /= k;
    }
    void Tinh_Tien(float dx, float dy){
        x1 += dx; 
        y1 += dy;
        x2 += dx;   
        y2 += dy;
        x3 += dx; 
        y3 += dy;
    }
    void Quay(float angle) {
        
    }
};

int main(){

}