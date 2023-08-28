#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Vehicle{
    protected:
    string maPT;
    string loaiXe;
    float trongTai;
    string xuatXu;
    int tgSX;
    public:
    virtual void nhap(){
        cout << "Nhap ma phuong tien: ";
        cin >> maPT;
        cout << "Nhap trong tai: ";
        cin >> trongTai;
        cin.ignore();
        cout << "Nhap xuat xu: ";
        getline(cin,xuatXu);
        cout << "Nhap thoi gian san xuat: ";
        cin >> tgSX;
    }
    void xuat(){
        cout << "Ma phuong tien: " << maPT << endl;
        cout << "Loai xe: " << loaiXe << endl;
        cout << "Trong tai: " << trongTai << endl;
        cout << "Xuat xu: " << xuatXu << endl;
        cout << "Thoi gian san xuat: " << tgSX << endl;
    }
    virtual float tinhTienCuoc(float soKM) = 0;
    string getMaPT(){
        return maPT;
    }
};

class XeContainer: public Vehicle{
    private:
    float nhienLieu;
    float KLHang;
    public:
    void nhap(){
        Vehicle::nhap();
        loaiXe = "Xe Container";
        while(trongTai > 35) {
            cout << "Nhap lai trong tai: ";
            cin >> trongTai;
        }
        cout << "Nhap nhien lieu: ";
        cin >> nhienLieu;
        while(nhienLieu > 40){
            cout << "Nhap lai nhien lieu: ";
            cin >> nhienLieu;
        }
        cout << "Nhap khoi luong hang: ";
        cin >> KLHang;
    }
    void xuat(){
        Vehicle::xuat();
        cout << "Nhien lieu: " << nhienLieu << endl;
        cout << "Khoi luong hang: " << KLHang << endl;
    }
    float tinhTienCuoc(float soKM){
        return KLHang * 150 * soKM;
    }
};

class XeBen: public Vehicle{
    private:
    float nhienLieu;
    float luongHang;
    public:
    void nhap(){
        Vehicle::nhap();
        loaiXe = "Xe Ben";
        while(trongTai > 20) {
            cout << "Nhap lai trong tai: ";
            cin >> trongTai;
        }
        cout << "Nhap nhien lieu: ";
        cin >> nhienLieu;
        while(nhienLieu > 40){
            cout << "Nhap lai nhien lieu: ";
            cin >> nhienLieu;
        }
        cout << "Nhap luong hang: ";
        cin >> luongHang;
    }
    void xuat(){
        Vehicle::xuat();
        cout << "Nhien lieu: " << nhienLieu << endl;
        cout << "Luong hang: " << luongHang << endl;
    }
    float tinhTienCuoc(float soKM){
        return luongHang * 5000 * soKM;
    }
};

class XeDL: public Vehicle{
    private:
    float nhienLieu;
    float KLHang;
    public:
    void nhap(){
        Vehicle::nhap();
        loaiXe = "Xe Dong Lanh";
        while(trongTai > 3.5) {
            cout << "Nhap lai trong tai: ";
            cin >> trongTai;
        }
        cout << "Nhap nhien lieu: ";
        cin >> nhienLieu;
        while(nhienLieu > 25){
            cout << "Nhap lai nhien lieu: ";
            cin >> nhienLieu;
        }
        cout << "Nhap khoi luong hang: ";
        cin >> KLHang;
    }
    void xuat(){
        Vehicle::xuat();
        cout << "Nhien lieu: " << nhienLieu << endl;
        cout << "Khoi luong hang: " << KLHang << endl;
    }
    float tinhTienCuoc(float soKM){
        return KLHang * 200 * soKM;
    }
};

class TuyenDuong{
    private:
    int maTuyen;
    string tenTuyen;
    float soKM;
    public:
    void nhap(){
        cout << "Nhap ma tuyen duong: ";
        cin >> maTuyen;
        cin.ignore();
        cout << "Nhap ten tuyen duong: ";
        getline(cin, tenTuyen);
        cout << "Nhap so km: ";
        cin >> soKM;
    }
    void xuat() {
        cout << "Ma tuyen duong: " << maTuyen << endl;
        cout << "Ten tuyen duong: " << tenTuyen << endl;
        cout << "So km: " << soKM << endl;
    }
    float getKM(){
        return soKM;
    }
    int getMaTD(){
        return maTuyen;
    }
};

struct Date{
    int day, month, year;
};

class QuanLyXe {
private:
    string maChuyen;
    Vehicle* phuongTien;
    TuyenDuong* tuyenDuong;
    Date thoiGianChay;

public:
    QuanLyXe() {
        phuongTien = nullptr;
        tuyenDuong = nullptr;
    }

    void nhap() {
        cout << "Nhap ma chuyen hang: ";
        cin >> maChuyen;
        cout << "Nhap thoi gian chay(ngay,thang,nam): ";
        cin >> thoiGianChay.day >> thoiGianChay.month >> thoiGianChay.year;
    }

    void xuat() {
        cout << "Ma chuyen hang: " << maChuyen << endl;
        cout << "Ma phuong tien: " << phuongTien->getMaPT() << endl;
        cout << "Ma tuyen duong: " << tuyenDuong->getMaTD() << endl;
        cout << "Thoi gian chay: " << thoiGianChay.day << "/" << thoiGianChay.month << "/" << thoiGianChay.year << endl;
    }

    void setPhuongTien(Vehicle* pt) {
        phuongTien = pt;
    }

    void setTuyenDuong(TuyenDuong* td) {
        tuyenDuong = td;
    }

    float tinhTienCuoc() {
        if (phuongTien != nullptr && tuyenDuong != nullptr) {
            float soKM = tuyenDuong->getKM();
            return phuongTien->tinhTienCuoc(soKM);
        }
        return 0.0;
    }
};

int main(){
    int m,n,type;
    cout << "Nhap so phuong tien: ";
    cin >> m;
    vector<Vehicle*> pt(m);
    for(int i = 0; i < m; i++){
        cout << "Nhap loai(loai 1: xe container, loai 2: xe ben, loai 3: xe dong lanh): ";
        cin >> type;
        if(type == 1) pt[i] = new XeContainer();
        if(type == 2) pt[i] = new XeBen();
        if(type == 3) pt[i] = new XeDL();
        pt[i]->nhap();
    }
    cout << "Nhap so tuyen duong: ";
    cin >> n;
    vector<TuyenDuong*> td(n);
    for(int i = 0; i < n; i++){
        td[i] = new TuyenDuong();
        td[i]->nhap();
    }
    int q;
    cout << "Nhap so quan ly xe: ";
    cin >> q;
    vector<QuanLyXe*> qlx(q);
    for (int i = 0; i < q; i++) {
        qlx[i] = new QuanLyXe();
        qlx[i]->nhap();
    }
    
    for (int i = 0; i < q; i++) {
        cout << "Thong tin chuyen hang: " << endl;
        qlx[i]->xuat();
        float tienCuoc = qlx[i]->tinhTienCuoc();
        cout << "Tien cuoc van tai: " << tienCuoc << endl;
        cout << endl;
    }

    for (int i = 0; i < m; i++) {
        delete pt[i];
    }

    for (int i = 0; i < n; i++) {
        delete td[i];
    }

    for (int i = 0; i < q; i++) {
        delete qlx[i];
    }

    return 0;
}