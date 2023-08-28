#include<iostream>
#include<math.h>

using namespace std;

class SoPhuc{
    private:
    double thuc, ao;
    public:
    SoPhuc(){
        thuc = 0;
        ao = 0;
    }
    SoPhuc(double thuc, double ao){
        this->thuc = thuc;
        this->ao = ao;
    }
    ~SoPhuc(){

    }
    friend istream& operator >> (istream &is, SoPhuc &s){
        is >> s.thuc >> s.ao;
        return is;
    }
    friend ostream& operator << (ostream &os, SoPhuc &s){
        os << s.thuc << " + " << s.ao << "i";
        return os;
    }
    SoPhuc operator + (SoPhuc &a){
        SoPhuc b;
        b.thuc = thuc + a.thuc;
        b.ao = ao + a.ao;
        return b;
    }
    SoPhuc operator - (SoPhuc &a){
        SoPhuc b;
        b.thuc = thuc - a.thuc;
        b.ao = ao - a.ao;
        return b;
    }
    SoPhuc operator * (SoPhuc &a){
        SoPhuc b;
        b.thuc = thuc * a.thuc - ao * a.ao;
        b.ao = thuc * a.ao + ao * a.thuc;
        return b;
    }
    SoPhuc operator / (SoPhuc &a){
        SoPhuc b;
        b.thuc = (thuc * a.thuc + ao * a.ao) / (pow(a.thuc, 2) * pow(a.ao, 2));
        b.ao = (ao * a.thuc - thuc * a.ao) / (pow(a.thuc, 2) * pow(a.ao, 2));
        return b;
    }
};

int main(){
    SoPhuc p1, p2, p3;
    cout << "Nhap phan thuc va phan ao cua p1:";
    cin >> p1;
    cout << "Nhap phan thuc va phan ao cua p2:";
    cin >> p2;
    p3 = p1 + p2;
    cout << "Tong hai so phuc la: " << p3 << endl;
    p3 = p1 - p2;
    cout << "Hieu hai so phuc la: " << p3 << endl;
    p3 = p1 * p2;
    cout << "Tich hai so phuc la: " << p3 << endl;
    p3 = p1 / p2;
    cout << "Thuong hai so phuc la: " << p3 << endl;
}
