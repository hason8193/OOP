#include <iostream>

using namespace std;

class DaGiac {
public:
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    virtual void tinhTien(float dx, float dy) = 0;
};

class TamGiac : public DaGiac {
protected:
    float a, b, c;

public:
    void nhap() override {
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
        cout << "Nhap canh c: ";
        cin >> c;
    }

    void xuat() override {
        cout << "Tam giac co cac canh: " << a << ", " << b << ", " << c << endl;
    }

    void tinhTien(float dx, float dy) override {
        
    }
};

class TuGiac : public DaGiac {
protected:
    float a, b, c, d;

public:
    void nhap() override {
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
        cout << "Nhap canh c: ";
        cin >> c;
        cout << "Nhap canh d: ";
        cin >> d;
    }

    void xuat() override {
        cout << "Tu giac co cac canh: " << a << ", " << b << ", " << c << ", " << d << endl;
    }

    void tinhTien(float dx, float dy) override {
    }
};

class HinhBinhHanh : public DaGiac {
protected:
    float a, b, h;

public:
    void nhap() override {
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
        cout << "Nhap chieu cao h: ";
        cin >> h;
    }

    void xuat() override {
        cout << "Hinh binh hanh co cac canh: " << a << ", " << b << " va chieu cao " << h << endl;
    }

    void tinhTien(float dx, float dy) override {
    }
};

class HinhChuNhat : public DaGiac {
protected:
    float a, b;

public:
    void nhap() override {
        cout << "Nhap canh a: ";
        cin >> a;
        cout << "Nhap canh b: ";
        cin >> b;
    }

    void xuat() override {
        cout << "Hinh chu nhat co cac canh: " << a << ", " << b << endl;
    }

    void tinhTien(float dx, float dy) override {
        
        
        
    }
};

class HinhVuong : public DaGiac {
protected:
    float a;

public:
    void nhap() override {
        cout << "Nhap canh a: ";
        cin >> a;
    }

    void xuat() override {
        cout << "Hinh vuong co canh: " << a << endl;
    }

    void tinhTien(float dx, float dy) override {
        
        
        
    }
};

int main() {
    DaGiac *hinh;
    int choice;

    cout << "Nhap hinh muon tao (1 - Tam giac, 2 - Tu giac, 3 - Hinh binh hanh, 4 - Hinh chu nhat, 5 - Hinh vuong): ";
    cin >> choice;

    switch (choice) {
        case 1:
            hinh = new TamGiac();
            break;
        case 2:
            hinh = new TuGiac();
            break;
        case 3:
            hinh = new HinhBinhHanh();
            break;
        case 4:
            hinh = new HinhChuNhat();
            break;
        case 5:
            hinh = new HinhVuong();
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            return 0;
    }

    hinh->nhap();
    hinh->xuat();

    float dx, dy;
    cout << "Nhap vecto tinh tien (dx, dy): ";
    cin >> dx >> dy;

    hinh->tinhTien(dx, dy);

    delete hinh;
    return 0;
}
