#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class Person{
    private:
    string Ten;
    string Ngs;
    string Place;
    string Gt;
    public:
    Person(){
        Ten = "";
        Ngs = "";
        Place = "";
        Gt = "";
    }
    virtual void nhap(){
        cout << "Nhap ten:"; cin >> this->Ten;
        cout << "Nhap ngay sinh:"; cin >> this->Ngs;
        cout << "Nhap noi o:"; cin >> this->Place;
        cout << "Nhap gioi tinh:"; cin >> this->Gt;
    }
    virtual void xuat(){
        cout << "Ong/Ba ten " << this->Ten << " co gioi tinh " << this->Gt << " co ngay sinh " << this->Ngs << " o " << this->Place;
    }
    ~Person(){}    
};

class SinhVien: virtual public Person{
    private:
    int Nam;
    int NienK;
    string Truong;
    string Nganh;
    public:
    SinhVien(){
        Nam = 0;
        NienK = 0;
        Truong = "";
        Nganh = "";
    }
    virtual void nhap(){
        Person::nhap();
        cout << "Nhap sinh vien nam may:"; cin >> this->Nam;
        cout << "Nhap nien khoa:"; cin >> this->NienK;
        cout << "Nhap ten truong:"; cin >> this->Truong;
        cout << "Nhap nganh:"; cin >> this->Nganh;
    }
    virtual void xuat(){
        Person::xuat();
        cout << " la sinh vien dang hoc nam " << this->Nam << " nien khoa " << this->NienK << " o truong " << this->Truong << " nganh " << this->Nganh;
    }
};

class HocSinh: virtual public Person{
    private:
    string Truong;
    int Lop;
    public:
    HocSinh(){
        Truong = "";
        Lop = 1;
    }
    virtual void nhap(){
        Person::nhap();
        cout << "Nhap ten truong:"; cin >> this->Truong;
        cout << "Nhap lop:"; cin >> this->Lop;
    }
    virtual void xuat(){
        Person::xuat();
        cout << " la hoc sinh dang hoc truong " << this->Truong << " va o lop " << this->Lop;
    }
};

class CongNhan: virtual public Person{
    private:
    string WPlace;
    float Luong;
    public:
    CongNhan(){
        WPlace = "";
        Luong = 0;
    }
    virtual void nhap(){
        Person::nhap();
        cout << "Nhap noi lam viec:"; cin >> this->WPlace;
        cout << "Nhap luong:"; cin >> this->Luong;
    }
    virtual void xuat(){
        Person::xuat();
        cout << " la cong nhan lam viec o " << this->WPlace << " co so luong " << this->Luong;
    }
};

class NgheSi: virtual public SinhVien{
    private:
    string NgheDanh;
    string ChuyenMon;
    public:
    NgheSi(){
        NgheDanh = "";
        ChuyenMon = "";
    }
    virtual void nhap(){
        Person::nhap();
        cout << "Nhap nghe danh:"; cin >> this->NgheDanh;
        cout << "Nhap chuyen mon:";cin >> this->ChuyenMon;
    }
    virtual void xuat(){
        Person::xuat();
        cout << " la nghe si co nghe danh " << this->NgheDanh << " va chuyen mon " << this->ChuyenMon;
    }
};

class CaSi: virtual public Person{
    private:
    string NgheDanh;
    string ChuyenMon;
    public:
    CaSi(){
        NgheDanh = "";
        ChuyenMon = "";
    }
    virtual void nhap(){
        Person::nhap();
        cout << "Nhap nghe danh:"; cin >> this->NgheDanh;
        cout << "Nhap chuyen mon:";cin >> this->ChuyenMon;
    }
    virtual void xuat(){
        Person::xuat();
        cout << " la ca si co nghe danh " << this->NgheDanh << " va chuyen mon " << this->ChuyenMon;
    }
};

class QuanLy{
    public:
    Person** p;
    QuanLy(){}
    void nhap(){
        int type,i=0;
        cout << "Nhap nhom nguoi(1:SinhVien, 2:HocSinh, 3:CongNhan, 4:NgheSi, 5: CaSi)";
        cin >> type;
        p = new Person*[1];
        while(i<1){
            if(type == 1){
                p[i]=new SinhVien();
                p[i]->nhap();
                i++;
            }

            if(type == 2){
                p[i]=new HocSinh();
                p[i]->nhap();
                i++;
            }
            if(type == 3){
                p[i]=new CongNhan();
                p[i]->nhap();
                i++;
            }
            if(type == 4){
                p[i]=new NgheSi();
                p[i]->nhap();
                i++;
            }
            if(type == 5){
                p[i]=new CaSi();
                p[i]->nhap();
                i++;
            }
        }
    }
    void xuat() {
		int i;
		for (i = 0; i < 1; i++) {
			p[i]->xuat();
		}
	}
	~QuanLy(){}
};

int main(){
    QuanLy ql;
    ql.nhap();
    ql.xuat();
    _getch();
}