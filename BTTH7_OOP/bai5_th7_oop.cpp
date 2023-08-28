#include <iostream>
using namespace std;

class Hinh {
public:
    virtual void nhapThongTin() = 0;
    virtual void xuatThongTin() = 0;
};

class HinhThang : public Hinh {
private:
    double dayLon;
    double dayNho;
    double chieuCao;
public:
    void nhapThongTin() {
        cout << "Nhap day lon: ";
        cin >> dayLon;
        cout << "Nhap day nho: ";
        cin >> dayNho;
        cout << "Nhap chieu cao: ";
        cin >> chieuCao;
    }
    void xuatThongTin() {
        cout << "Day lon: " << dayLon << endl;
        cout << "Day nho: " << dayNho << endl;
        cout << "Chieu cao: " << chieuCao << endl;
    }
};

class HinhBinhHanh : public Hinh {
private:
    double day;
    double chieuCao;
public:
    void nhapThongTin() {
        cout << "Nhap day: ";
        cin >> day;
        cout << "Nhap chieu cao: ";
        cin >> chieuCao;
    }
    void xuatThongTin() {
        cout << "Day: " << day << endl;
        cout << "Chieu cao: " << chieuCao << endl;
    }
};

class HinhChuNhat : public Hinh {
private:
    double chieuDai;
    double chieuRong;
public:
    void nhapThongTin() {
        cout << "Nhap chieu dai: ";
        cin >> chieuDai;
        cout << "Nhap chieu rong: ";
        cin >> chieuRong;
    }
    void xuatThongTin() {
        cout << "Chieu dai: " << chieuDai << endl;
        cout << "Chieu rong: " << chieuRong << endl;
    }
};

class HinhVuong : public Hinh {
private:
    double canh;
public:
    void nhapThongTin() {
        cout << "Nhap canh: ";
        cin >> canh;
    }
    void xuatThongTin() {
        cout << "Canh: " << canh << endl;
    }
};

int main() {
    Hinh *hinh;
    int loaiHinh;
    bool hopLe = false;
    while (!hopLe) {
        cout << "Nhap loai hinh (1: hinh thang, 2: hinh binh hanh, 3: hinh chu nhat, 4: hinh vuong): ";
        cin >> loaiHinh;
        switch (loaiHinh) {
            case 1: {
                hinh = new HinhThang();
                hinh->nhapThongTin();
                hinh->xuatThongTin();
                hopLe = true;
                break;
            }
            case 2: {
                hinh = new HinhBinhHanh();
                hinh->nhapThongTin();
                hinh->xuatThongTin();
                hopLe = true;
                break;
            }
            case 3: {
                hinh = new HinhChuNhat();
                hinh->nhapThongTin();
                hinh->xuatThongTin();
                hopLe = true;
                break;
            }
            case 4: {
                hinh = new HinhVuong();
                hinh->nhapThongTin();
                hinh->xuatThongTin();
                hopLe = true;
                break;
            }
            default: {
                cout << "Loai hinh khong hop le. Vui long nhap lai.\n";
                break;
            }
        }
    }
    delete hinh;
    return 0;
}
