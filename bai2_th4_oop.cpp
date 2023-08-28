#include<iostream>

using namespace std;

class CTime{
    private:
    int hrs,min,sec;
    public:
    CTime(int h = 0, int m = 0, int s = 0){
        hrs = h;
        min = m;
        sec = s;
    }
    friend istream& operator >>(istream& is, CTime& ct){
        is >> ct.hrs >> ct.min >> ct.sec;
        return is;
    }
    friend ostream& operator <<(ostream& os, const CTime& ct){
        os << ct.hrs << "h" << ct.min << "m" << ct.sec << "s";
        return os;
    }
    CTime CongGiay(int s){
        CTime t;
        t.hrs = hrs;
        t.min = min;
        t.sec = sec + s;
        if(sec >= 60){
            t.min += t.sec / 60;
            t.sec %= 60;
        }
        if(min >= 60){
            t.hrs += t.min / 60;
            t.min %= 60;
        }
        return t;
    }
    CTime TruGiay(int s){
        CTime t;
        t.hrs = hrs;
        t.min = min;
        t.sec = sec - s;
        if (t.sec < 0) {
            t.min += t.sec / 60 - 1;
            t.sec = 60 + t.sec % 60;
        }
        if (t.min < 0) {
            t.hrs += t.min / 60 - 1;
            t.min = 60 + t.min % 60;
        }
        return t;
    }
    CTime TruHaiSpan(CTime other){
        CTime c;
        c.sec = sec - other.sec;
        c.min = min - other.min;
        c.hrs = hrs - other.hrs;
        if(c.sec < 0){
            c.min += c.sec / 60 - 1;
            c.sec = 60 + c.sec % 60;
        }
        if(c.min < 0){
            c.hrs += c.min / 60 - 1;
            c.min = 60 + c.min % 60;
        }
        if(c.hrs < 0){
            c.hrs = c.min = c.sec = -1;
        }
        return c;
    }
    CTime ThemMotGiay(){
        CTime c;
        c.hrs = this->hrs;
        c.min = this->min;
        c.sec = this->sec + 1;
        if(c.sec >= 60){
            c.min += c.sec / 60;
            c.sec %= 60;
        }
        if(c.min >= 60){
            c.hrs += c.min / 60;
            c.min %= 60;
        }
        return c;
    }
    CTime BotMotGiay(){
        CTime c;
        c.hrs = hrs;
        c.min = min;
        c.sec = sec - 1;
        if(c.sec < 0){
            c.min += c.sec / 60 - 1;
            c.sec = 60 + c.sec % 60;
        }
        if(c.min < 0){
            c.hrs += c.min / 60 - 1;
            c.min = 60 + c.min % 60;
        }
        return c;
    }
};

int main(){
    CTime c;
    cin >> c;
    cout << c.ThemMotGiay();
    return 0;
}
