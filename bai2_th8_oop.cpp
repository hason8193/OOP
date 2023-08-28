#include<iostream>
#include<vector>

using namespace std;

class DaGiac{
    protected:
    int soDinh;
    float* toaDoX;
    float* toaDoY;
    public:
    DaGiac(int n){
        soDinh = n;
        toaDoX = new float[n];
        toaDoY = new float[n];
    }
    virtual void nhap(){
        cout << "Nhap toa do cac dinh:\n";
        for(int i = 0; i < soDinh; i++){
            cout << "Dinh thu " << i + 1 << " co \n";
            cout << "(x,y) = ";
            cin >> toaDoX[i] >> toaDoY[i];
        }
    }
    virtual void xuat(){
        cout << "Cac toa do cua dinh lan luot la: ";
        for(int i = 0; i < soDinh; i++){
            cout << "(" << toaDoX[i] << "," << toaDoY[i] << ")";
            if(i < soDinh - 1) cout << ",";
        }
        cout << endl;
    }
    virtual void tinhTien(float dx, float dy){
        for(int i = 0; i < soDinh; i++){
            toaDoX[i] += dx;
            toaDoY[i] += dy;
        }
    }
    ~DaGiac(){
        delete[] toaDoX;
        delete[] toaDoY;
    }
};

class TuGiac: public DaGiac{
    public:
    TuGiac(): DaGiac(4){}
};

class TamGiac: public DaGiac{
    public:
    TamGiac(): DaGiac(3){}
};

int main(){
    int n,type,dx,dy;
    cout << "Nhap so hinh da giac can tinh:";
    cin >> n;
    vector<DaGiac*> hinh(n);
    for(int i = 0; i < n; i++){
        cout << "Nhap loai da giac(1: Tu giac, 2: Tam giac):";
        cin >> type;
        cout << "Nhap vector (dx,dy) muon tinh tien:";
        cin >> dx >> dy;
        if(type == 1){
            hinh[i] = new TuGiac();
            hinh[i]->nhap();
            hinh[i]->tinhTien(dx,dy);
        }
        if(type == 2){
            hinh[i] = new TamGiac();
            hinh[i]->nhap();
            hinh[i]->tinhTien(dx,dy);
        }
    }
    for(int i = 0; i < n; i++){
        hinh[i]->xuat();
    }
    for(int i = 0; i < n; i++){
        delete hinh[i];
    }
    return 0;
}