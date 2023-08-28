#include<iostream>
#include<string>

using namespace std;

struct TT{
    string ten;
    int ms;
    string ns;
    float dT;
    float dV;
    float dA;
};

istream & operator >> (istream & in, TT &t){
    cout << "Ten, Ma so, Ngay sinh, Diem Toan, Diem Van, Diem Anh lan luot la:";
    in >> t.ten >> t.ms >> t.ns >> t.dT >> t.dV >> t.dA;
    return in;
}

ostream & operator << (ostream & out, TT &t){
    out << t.ten << " co ma so " << t.ms << " va ngay sinh " << t.ns << " co diem tong lon hon 15";
    return out;
}

bool Tong(TT &t){
    int s = t.dT + t.dV + t.dA;
    if (s > 15) return 1;
    else return 0;
}

int main(){
    int n;
    cout << "Nhap n:";
    cin >> n;
    TT t[n];
    for (int i = 0; i < n; i ++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i ++){
        if(Tong(t[i])) cout << t[i] << endl;
    }
}