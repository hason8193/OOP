#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for all nv
class NV {
protected:
    string ten;
public:
    NV(string ten) {
        this->ten = ten;
    }

    string getName() {
        return ten;
    }

    virtual float tinhLuong() = 0;
    virtual int getSoSp() { return 0; }
    virtual int getSNLV() { return 0; }
};

// Production Worker class (Type 1)
class NVSX : public NV {
    float luongCb;
    int soSp;
public:
    NVSX(string ten, float luongCb, int soSp) : NV(ten) {
        this->luongCb = luongCb;
        this->soSp = soSp;
    }

    float tinhLuong() {
        return luongCb + soSp * 5;
    }

    int getSoSp() {
        return soSp;
    }
};

// Office Worker class (Type 2)
class NVVP : public NV {
    int soNLV;
public:
    NVVP(string ten, int soNLV) : NV(ten) {
        this->soNLV = soNLV;
    }

    float tinhLuong() {
        return soNLV * 100;
    }

    int getSNLV() {
        return soNLV;
    }
};

// Sep class (Type 3)
class Sep : public NV {
    static int tongSp;
    static int tongNLV;
public:
    Sep(string ten) : NV(ten) {}

    float tinhLuong() {
        return 100 + tongSp * 2 + tongNLV * 40;
    }

    static void updateStatistics(NV* employee) {
        tongSp += employee->getSoSp();
        tongNLV += employee->getSNLV();
    }
};

int Sep::tongSp = 0;
int Sep::tongNLV = 0;

int main() {
    int slNV;
    cin >> slNV;

    vector<NV*> nv;

    for (int i = 0; i < slNV; i++) {
        int loai;
        string ten;

        cin >> loai >> ten;

        if (loai == 1) {
            float luongCb;
            int soSp;
            cin >> luongCb >> soSp;
            nv.push_back(new NVSX(ten, luongCb, soSp));
        }
        else if (loai == 2) {
            int soNLV;
            cin >> soNLV;
            nv.push_back(new NVVP(ten, soNLV));
        }
        else if (loai == 3) {
            nv.push_back(new Sep(ten));
        }
    }

    for (int i = 0; i < slNV; i++) {
        if (dynamic_cast<Sep*>(nv[i]) == nullptr) {
            Sep::updateStatistics(nv[i]);
        }
    }

    for (int i = 0; i < slNV; i++) {
        cout << nv[i]->getName() << ": " << nv[i]->tinhLuong() << endl;
    }

    // Deallocate memory for the dynamically created objects
    for (int i = 0; i < slNV; i++) {
        delete nv[i];
    }

    return 0;
}
