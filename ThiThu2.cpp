#include<bits/stdc++.h>

using namespace std;

class NhomMau{
    protected:
    bool Rh;
    public:
    NhomMau(){};
    ~NhomMau(){};
    virtual bool KTraDiTruyen(char, char) = 0;
    virtual char getTen() = 0;
    virtual bool TuongThich(char, bool) = 0;
    void nhap(){
        char t;
        cout << "Nhap Rh: ";
        cin >> t;
        if(t == '+') Rh = true;
        else Rh = false;
    }
    bool getRh(){
        return Rh;
    }
};

class NhomA: public NhomMau{
    public:
    bool KTraDiTruyen(char me, char con){
        switch(me){
            case 'A':
                if(con == 'A' || con == 'O')
                    return true;
                break;
            case 'B':
                if(con == 'A' || con == 'B' || con == 'C' || con == 'O')
                    return true;
                break;
            case 'C':
                if(con == 'A' || con == 'B' || con == 'C')
                    return true;
                break;
            case 'O':
                if(con == 'A' || con == 'O')
                    return true;
                break;
        }
        return false;
    }
    char getTen(){
        return 'A';
    }
    bool TuongThich(char nm, bool b){
        if(this->getRh() == 0){
            if(b == 0){
                if(nm == 'A' || nm == 'O')
                    return 1;
            }
        }
        if(this->getRh() == 1){
            if(nm == 'A' || nm == 'O')
                return 1;
        }
        return 0;
    }

};

class NhomB: public NhomMau{
    public:
    char getTen(){
        return 'B';
    }
    bool KTraDiTruyen(char me, char con){
        switch(me){
            case 'A': 
            if(con == 'A' || con == 'B' || con == 'C' || con == 'O')
                return 1;
            break;
            case 'O':
            if(con == 'B' || con == 'O')
                return 1;
            break;
            case 'C':
            if(con == 'A' || con == 'B' || con == 'C')
                return 1;
            break;
            case 'B':
            if(con == 'B' || con == 'O')
                return 1;
            break;
        }
        return 0;
    }
    bool TuongThich(char nm, bool b){
        if(this->getRh() == 0){
            if(b == 0){
                if(nm == 'O' || nm == 'B')
                    return 1;
            }
        }
        if(this->getRh() == 1){
            if(nm == 'O' || nm == 'B')
                    return 1;
        }
        return 0;
    }
};

class NhomAB: public NhomMau{
    public:
    char getTen(){
        return 'C';
    }
    bool KTraDiTruyen(char me, char con){
        switch(me){
            case 'A':
            if(con == 'A' || con == 'B' || con == 'C')
                return 1;
            break;
            case 'B':
            if(con == 'A' || con == 'B' || con == 'C')
                return 1;
            break;
            case 'C':
            if(con == 'A' || con == 'B' || con == 'C')
                return 1;
            break;
            case 'O':
            if(con == 'A' || con == 'B')
                return 1;
            break;
        }
        return 0;
    }
    bool TuongThich(char nm, bool b){
        if(this->getRh() == 0){
            if(b == 0){
                if(nm == 'A' || nm == 'B' || nm == 'C' || nm == 'O')
                    return 1;
            }
        }
        if(this->getRh() == 1){
            if(nm == 'A' || nm == 'B' || nm == 'C' || nm == 'O')
                return 1;
        }
        return 0;
    }
};

class NhomO: public NhomMau{
    public:
    char getTen(){
        return 'O';
    }
    bool KTraDiTruyen(char me, char con){
        switch(me){
            case 'A':
            if(con == 'A' || con == 'O')
                return 1;
            break;
            case 'B':
            if(con == 'B' || con == 'O')
                return 1;
            break;
            case 'C':
            if(con == 'A' || con == 'B')
                return 1;
            break;
            case 'O':
            if(con == 'O')
                return 1;
            break;
        }
        return 0;
    }
    bool TuongThich(char nm, bool b){
        if(this->getRh() == 0){
            if(b == 0){
                if(nm == 'O')
                    return 1;
            }
        }
        if(this->getRh() == 1){
            if(nm == 'O')
                return 1;
        }
        return 0;
    }
};

int main()
{
    //Cau 1
    int n, chon;
    cout << "Nhap so nguoi: ";
    cin >> n;
    vector<NhomMau*> list(n);
    for (int i = 0; i < n; i++)
    {
    cout << "Hay chon 1,2,3,4 lan luot la nguoi nhom mau O,A,B,AB: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
    list[i] = new NhomO();
    break;
    case 2:
    list[i] = new NhomA();
    break;
    case 3:
    list[i] = new NhomB();
    break;
    case 4:
    list[i] = new NhomAB();
    break;
    }
    list[i]->nhap();
    }
    //Cau 2
    int cha, me, con;
    cout << "Hay nhap theo thu tu cha, me, con bang cac chi so trong mang: ";
    cin >> cha >> me >> con;
    bool KQ = list[cha]->KTraDiTruyen(list[me]->getTen(), list[con]->getTen());
    if(KQ) cout << "Di truyen duoc" << endl;
    else cout << "Khong di truyen duoc" << endl;
    //Cau 3
    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "So thu tu cua nhung nguoi tuong thich la: ";
    for (int i = 0; i < n; i++){
        if ((i != x) && (list[x]->TuongThich(list[i]->getTen(), list[i]->getRh()))){
            cout << i << " ";
        }
    }
    return 0;
}