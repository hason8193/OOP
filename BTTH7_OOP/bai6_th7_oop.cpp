#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
protected:
    int slDV;
public:
    Animal(int slDV) : slDV(slDV) {}
    virtual void TiengKeu() = 0;
    virtual int SinhCon() = 0;
    virtual int SinhSua() = 0; 
};

class Cow : public Animal {
public:
    Cow(int slBo) : Animal(slBo) {}
    void TiengKeu() {
        cout << "Booo" << endl;
    }
    int SinhCon() {
        int slConNon = rand() % 5 + 1; 
        cout << slConNon << " con bo con duoc sinh ra." << endl;
        slDV += slConNon;
        return slConNon;
    }
    int SinhSua() {
        int sua = rand() % 21; 
        cout << "Con bo cho " << sua << " lit sua." << endl;
        return sua;
    }
};

class Sheep : public Animal {
public:
    Sheep(int slCuu) : Animal(slCuu) {}
    void TiengKeu() {
        cout << "Baaa" << endl;
    }
    int SinhCon() {
        int slConNon = rand() % 5 + 1; 
        cout << slConNon << " con cuu duoc sinh ra." << endl;
        slDV += slConNon;
        return slConNon;
    }
    int SinhSua() {
        int sua = rand() % 6;
        cout << "Con cuu cho " << sua << " lit sua." << endl;
        return sua;
    }
};


class Goat : public Animal {
public:
    Goat(int slDe) : Animal(slDe) {}
    void TiengKeu() {
        cout << "Beee" << endl;
    }
    int SinhCon() {
        int slConNon = rand() % 5 + 1; 
        cout << slConNon << " con de duoc sinh ra." << endl;
        slDV += slConNon;
        return slConNon;
    }
    int SinhSua() {
        int sua = rand() % 11; 
        cout << "Con de cho " << sua << " lit sua." << endl;
        return sua;
    }
};

int main() {
    srand(time(NULL)); 
    int slBo;
    int slCuu;
    int slDe;
    cout << "Nhap so luong bo: ";
    cin >> slBo;
    cout << "Nhap so luong cuu: ";
    cin >> slCuu;
    cout << "Nhap so luong de: ";
    cin >> slDe;
    Cow cow(slBo);
    Sheep sheep(slCuu);
    Goat goat(slDe);
    cout << "Tat ca con vat dang doi va deu dang lam tieng keu:" << endl;
    cow.TiengKeu();
    sheep.TiengKeu();
    goat.TiengKeu();
    cout << "\nSau 1 chu ki sinh con va cho sua:" << endl;
    int slBoNon = cow.SinhCon();
    int suaBo = cow.SinhSua();
    int slCuuNon = sheep.SinhCon();
    int suaCuu = sheep.SinhSua();
    int slDeNon = goat.SinhCon();
    int suaDe = goat.SinhSua();
    int tongDV = slBo + slCuu + slDe + slBoNon + slCuuNon + slDeNon;
    int tongSua = suaBo + suaCuu + suaDe;
    cout << "\nSo luong bo: " << slBo + slBoNon << endl;
    cout << "So luong cuu: " << slCuu + slCuuNon << endl;
    cout << "So luong de: " << slDe + slDeNon << endl;
    cout << "Tong sua san xuat: " << tongSua << " lit" << endl;
    cout << "Tong so luong dong vat: " << tongDV << endl;
    return 0;
}