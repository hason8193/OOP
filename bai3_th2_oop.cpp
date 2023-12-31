#include<iostream>
#include<string>

using namespace std;

class TT{
    private:
    string ten;
    int MSSV;
    string DATE;
    float dT;
    float dV;
    float dA;
    public:
    friend istream & operator >> (istream & in, TT &t){
        cout << "Ten, Ma so, Ngay sinh, Diem Toan, Diem Van, Diem Anh lan luot la:";
        in >> t.ten >> t.MSSV >> t.DATE >> t.dT >> t.dV >> t.dA;
        return in;
    }

    friend ostream & operator << (ostream & out, TT &t){
        out << t.ten << " co ma so " << t.MSSV << " va ngay sinh " << t.DATE << " co diem tong lon hon 15";
        return out;
    }

    bool Tong(TT &t){
        int s = t.dT + t.dV + t.dA;
        if (s > 15) return 1;
        else return 0;
    }
};

int main(){
    int n;
    cout << "Nhap n:";
    cin >> n;
    TT* t = new TT[n];
    for (int i = 0; i < n; i ++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i ++){
        if(t->Tong(t[i])) cout << t[i] << endl;
    }
}