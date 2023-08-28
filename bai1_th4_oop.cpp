#include<iostream>

using namespace std;

class CTimeSpan{
    private:
    int hrs, min, sec;
    public:
    CTimeSpan(int h = 0, int m = 0, int s = 0) {
        hrs = h;
        min = m;
        sec = s;
    }
    int getHrs() const { return hrs; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
    void setHrs(int h) { hrs = h; }
    void setMin(int m) { min = m; }
    void setSec(int s) { sec = s; }
    CTimeSpan Cong(const CTimeSpan& other)const{
        int h = hrs + other.hrs;
        int m = min + other.min;
        int s = sec + other.sec;
        if(s >= 60){
            m += s / 60;
            s %= 60;
        }
        if(m >= 60){
            h += m / 60;
            m %= 60;
        }
        return CTimeSpan(h, m, s);
    }
    CTimeSpan Tru(const CTimeSpan& other)const{
        int h = hrs - other.hrs;
        int m = min - other.min;
        int s = sec - other.sec;
        if(s < 0){
            m--;
            s += 60;
        }
        if(m < 0){
            h--;
            m += 60;
        }
        return CTimeSpan(h, m, s);
    }
    bool Bang(const CTimeSpan& other)const{
        return hrs == other.hrs && min == other.min && sec == other.sec;
    }
    bool Khac(const CTimeSpan& other)const{
        return !Bang(other);
    }
    bool Lonhon(const CTimeSpan& other) const {
        if (hrs > other.hrs) {
            return true;
        }
        else if (hrs == other.hrs && min > other.min) {
            return true;
        }
        else if (hrs == other.hrs && min == other.min && sec > other.sec) {
            return true;
        }
        else {
            return false;
        }
    }
     bool Lonhonhoacbang(const CTimeSpan& other) const {
        return Lonhon(other) || Bang(other);
    }
    
    bool Nhohon(const CTimeSpan& other) const {
        return !Lonhonhoacbang(other);
    }
    
    bool Nhohonhoacbang(const CTimeSpan& other) const {
        return !Lonhon(other);
    }
    void nhap() {
        cout << "Nhap gio, phut, giay: ";
        cin >> hrs >> min >> sec;
    }
    
    void xuat() const {
        cout << hrs << " gio " << min << " phut " << sec << " giay" << endl;
    }
};

int main(){
    CTimeSpan c;
}