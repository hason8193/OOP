#include<iostream>
#include<math.h>

using namespace std;

class TamGiac{
private:
    float a, b, c;
public:
    TamGiac(){
        a= b = c = 0;
    }
    TamGiac(float x1, float x2, float x3, float y1, float y2, float y3){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    ~TamGiac(){};
    void Nhap(){
        cout << "Nhap do dai 3 canh cua tam giac:";
        cin >> a >> b >> c;
    }
    void Xuat(){
    cout << "Tam giac co do dai 3 canh la:" << a << "," << b << "," << c << endl;
    }
    void Phong_To(float k){
        a *= k;
        b *= k;
        c *= k;
    }
    void Thu_Nho(float k){
        a /= k;
        b /= k;
        c /= k;
    }
    void Tinh_Tien(float dx, float dy){
        a += dx;
        b += dy;
    }
    void Quay(float angle) {
        float rad = angle * M_PI / 180; // đổi đơn vị sang radian
        float x1 = a * cos(rad) - b * sin(rad);
        float y1 = a * sin(rad) + b * cos(rad);
        float x2 = b * cos(rad) - c * sin(rad);
        float y2 = b * sin(rad) + c * cos(rad);
        float x3 = c * cos(rad) - a * sin(rad);
        float y3 = c * sin(rad) + a * cos(rad);
        a = sqrt(x1 * x1 + y1 * y1);
        b = sqrt(x2 * x2 + y2 * y2);
        c = sqrt(x3 * x3 + y3 * y3);
    }
};

int main(){

}