#include<iostream>
#include<math.h>

using namespace std;

typedef struct So_Ao{
    float thuc;
    float ao;
}SA;

SA operator + (SA s1, SA s2){
    SA s;
    s.thuc = s1.thuc + s2.thuc;
    s.ao = s1.ao + s2.ao;
    return s;
}

SA operator - (SA s1, SA s2){
    SA s;
    s.thuc = s1.thuc - s2.thuc;
    s.ao = s1.ao - s2.ao;
    return s;
}

SA operator * (SA s1, SA s2){
    SA s;
    s.thuc = s1.thuc * s2.thuc - s1.ao * s2.ao;
    s.ao = s1.thuc * s2.ao + s1.ao * s2.thuc;
    return s;
}

SA operator / (SA s1, SA s2){
    SA s;
    s.thuc = (s1.thuc * s2.thuc + s1.ao * s2.ao) / (pow(s2.thuc, 2) * pow(s2.ao, 2));
    s.ao = (s1.ao * s2.thuc - s1.thuc * s2.ao) / (pow(s2.thuc, 2) * pow(s2.ao, 2));
    return s;
}

istream & operator >> (istream &in, SA &s){
    cout << "Nhap phan thuc:";
    in >> s.thuc;
    cout << "Nhap phan ao:";
    in >> s.ao;
    return in;
}

ostream & operator << (ostream &out, SA &s){
    out << s.thuc << "+" << s.ao;
    return out;
}

int main(){
    SA s1, s2, s3, s4, s5, s6;
    cout << "Nhap s1:";
    cin >> s1;
    cout << "Nhap s2:";
    cin >> s2;
    s3 = s1 + s2;
    cout << "Tong bang:" << s3 << endl;
    s4 = s1 - s2;
    cout << "Hieu bang:" << s4 << endl;
    s5 = s1 * s2;
    cout << "Tich bang:" << s5 << endl;
    s6 = s1 / s2;
    cout << "Thuong bang:" << s6 << endl;
}