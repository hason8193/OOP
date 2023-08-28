#include<iostream>

using namespace std;

class DaThuc{
    private:
    int n;
    int* arr;
    public:
    DaThuc(){
        n = 1;
        arr = new int[n];
        arr[0] = 1;
    }
    friend istream& operator >> (istream& is, DaThuc& dt){
        cout << "Nhap bac: ";
        is >> dt.n;
        dt.arr = new int[dt.n + 1];
        for(int i = dt.n; i >= 0; i--){
            cout << "Nhap he so " << i << ":";
            is >> dt.arr[i];
        }
        return is;
    }
    friend ostream& operator << (ostream& os, const DaThuc& dt){
        os << "He so cua bac giam dan: ";
        for(int i = dt.n; i >= 0; i--){
            os << dt.arr[i] << "x^" << i << "+";
        }
        os << 0;
        return os;
    }
    DaThuc operator+(DaThuc& other) {
        DaThuc dt;
        if (this->n > other.n) {
            dt.n = this->n;
            dt.arr = new int[this->n + 1];
            for (int i = this->n; i >= 0; i--) {
                if (i <= other.n) {
                    dt.arr[i] = this->arr[i] + other.arr[i];
                } else {
                    dt.arr[i] = this->arr[i];
                }
            }
        } else {
            dt.n = other.n;
            dt.arr = new int[other.n + 1];
            for (int i = other.n; i >= 0; i--) {
                if (i <= this->n) {
                    dt.arr[i] = this->arr[i] + other.arr[i];
                } else {
                    dt.arr[i] = other.arr[i];
                }
            }
        }
        return dt;
    }

};

int main(){
    DaThuc dt1, dt2,dt3;
    cin >> dt1 >> dt2;
    dt3 = dt1 + dt2;
    cout << dt3;
}