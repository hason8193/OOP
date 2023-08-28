#include<iostream>

using namespace std;

class CDate{
    private:
    int day,month,year;
    public:
    CDate(int d=0, int m=0, int y=0){
        day = d;
        month = m;
        year = y;
    }
    friend istream& operator >> (istream& is, CDate& cd){
        cout << "Nhap ngay,thang,nam: ";
        is >> cd.day >> cd.month >> cd.year;
        return is;
    }
    friend ostream& operator << (ostream& os,const CDate cd){
        os << cd.day << "/" << cd.month << "/" << cd.year;
        return os;
    }
    bool isLeapYear(int y){
        return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)); 
    }
    int daysInMonth(CDate cd) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (cd.month == 2 && isLeapYear(cd.year)) {
            return 29;
        }
        return days[month - 1];
    }
    CDate CongNgay(int n){
        CDate c;
        c.year = year;
        c.month = month;
        c.day = day + n;
        if(c.day > c.daysInMonth(c)){
            int a = c.day / c.daysInMonth(c);
            int b = c.daysInMonth(c);
            c.month += a;
            c.day %= b;
        }
        if(c.month > 12){
            c.year += c.month / 12;
            c.month %= 12;
        }
        return c;
    }
    CDate TruNgay(int n) {
        CDate c;
        c.year = year;
        c.month = month;
        c.day = day - n;

        if (c.day < 1) {
            c.month--;
            if (c.month < 1) {
                c.year--;
                c.month += 12;
            }
            int a = c.daysInMonth(c);
            c.day += a;
        }
        return c;
    }
    CDate CongMotNgay(){
        CDate c = CongNgay(1);
        return c;
    }
    CDate TruMotNgay(){
        CDate c = TruNgay(1);
        return c;
    }
};

int main(){
    CDate c;
    cin >> c;
    cout << c.TruNgay(4);
}