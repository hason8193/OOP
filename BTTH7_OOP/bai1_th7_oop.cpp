#include <iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct DateNV {
	int ngay, thang, nam;
};

class NV {
private:
	string Hoten;
	DateNV Ngs;
	double Luong;
public:
	NV() {
		Hoten = "";
		Ngs.ngay = 0;
		Luong = 0;
	}
	virtual void Nhap() {
		cout << "Nhap ho ten:"; cin >> this->Hoten;
		cout << "Nhap ngay sinh: "; cin >> this->Ngs.ngay;
		cout << "Nhap thang sinh: "; cin >> this->Ngs.thang;
		cout << "Nhap nam sinh: "; cin >> this->Ngs.nam;
	}
	virtual void Xuat() {
		cout << "Ong/Ba : " << this->Hoten << " sinh ngay "
			<< Ngs.ngay << "-" << Ngs.thang << "-" << Ngs.nam;
		cout << " Co so luong la: " << this->TinhLuong() << endl;
	}
	virtual double TinhLuong()=0;
	~NV() {}

};

class NVVP : virtual public NV {
private:
	int Snlv;
public:
	NVVP() { Snlv = 0; }
	void Nhap() {
		NV::Nhap();
		cout << "Nhap so ngay lam viec: ";
		cin >> this->Snlv;
	}
	
	double TinhLuong() {
		return Snlv * 100000;
	}
};

class NVSX : virtual public NV {
private:
	double lcb, sp;
public:
	NVSX() { lcb = 0; sp = 0; }
	void Nhap() {
		NV::Nhap();
		cout << "Nhap Luong co ban: "; cin >> this->lcb;
		cout << "Nhap san pham: "; cin >> this->sp;
	}
	
	double TinhLuong() { return lcb + sp * 5000; }
};


class Quanly {

	int sl;
	NV** nv;
public:

	Quanly(){ }
	void Nhap() {
		int i = 0, n = 0;
		int typenv;
		cout << "Nhap so nhan vien: "; cin >> this->sl;

		nv = new NV * [sl];

		while (i < sl) {
			cin.ignore();
			cout << "Nhap nhom nhan vien: "; cin >> typenv;
			if (typenv == 0)
			{
				nv[i] = new NVVP();
				nv[i]->Nhap();
				i++;
			}
			else {
				nv[i] = new NVSX();
				nv[i]->Nhap();
				i++;
			}
		}

	}
	void Xuat() {
		int i;
		for (i = 0; i < this->sl; i++) {
			nv[i]->Xuat();
		}
	}
	~Quanly() {

	}

};

int main()
{
	Quanly ql;
	ql.Nhap();
	ql.Xuat();
	
	
	_getch();

}
