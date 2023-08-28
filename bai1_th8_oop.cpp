#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

class Sach{
    protected:
    string ten;
    string tg;
    public:
    
    virtual void inTT(){
        cout << "Ten sach la " << ten << " cua tac gia " << tg;
    }
    virtual void nhap(){
        cout << "Nhap ten sach:"; cin >> ten;
        cout << "Nhap ten tac gia:"; cin >> tg;
    }
};

class SGK: public Sach{
    private:
    string monHoc;
    public:
    
    void inTT(){
        Sach::inTT();
        cout << ", la sach giao khoa ve mon hoc " << monHoc << endl;
    }
    void nhap(){
        Sach::nhap();
        cout << "Nhap ten mon hoc trong sgk: "; cin >> monHoc;
    }
};

class TThuyet: public Sach{
    private:
    string theLoai;
    public:
    
    void inTT(){
        Sach::inTT();
        cout << ", la tieu thuyet ve the loai " << theLoai << endl;
    }
    void nhap(){
        Sach::nhap();
        cout << "Nhap ten the loai tieu thuyet: "; cin >> theLoai;
    }
};

class TapChi: public Sach{
    private:
    int soPhatHanh;
    public:
    
    void inTT(){
        Sach::inTT();
        cout << ", la tap chi co so phat hanh " << soPhatHanh << endl;
    }
    void nhap(){
        Sach::nhap();
        cout << "Nhap ten so phat hanh cua tap chi: "; cin >> soPhatHanh;
    }
};

int main(){
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    vector<Sach*> books(n);
    int type;
    for(int i = 0; i < n; i++){
        cout << "Nhap loai sach(1: sach giao khoa, 2: tieu thuyet, 3: tap chi):";
        cin >> type;
        if(type == 1){
            books[i] = new SGK();
            books[i]->nhap();
        }
        if(type == 2){
            books[i] = new TThuyet();
            books[i]->nhap();
        }
        if(type == 3){
            books[i] = new TapChi();
            books[i]->nhap();
        }
    }
    for(int i = 0; i < n; i++){
        books[i]->inTT();
    }
    for (int i = 0; i < n; i++) {
        delete books[i];
    }
    return 0;
}