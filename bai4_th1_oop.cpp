#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

bool Nam_Nhuan(int year)
 {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Ngay_Cua_Thang(int month, int year)
{
    if (month == 2)
    {
        if (Nam_Nhuan(year))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

Date Ngay_Ke(Date date)
{
    int k = Ngay_Cua_Thang(date.month, date.year);
    if (date.day < k)
    {
        date.day++;
    }
    else
    {
        date.day = 1;
        if (date.month < 12)
        {
            date.month ++;
        }
        else
        {
            date.month = 1;
            date.year ++;
        }
    }

    return date;
}

int main() {
    Date date;
    cout << "Nhap ngay: ";
    cin >> date.day;
    cout << "Nhap thang: ";
    cin >> date.month;
    cout << "Nhap nam: ";
    cin >> date.year;
    date = Ngay_Ke(date);
    cout << "Ngay ke tiep la: " << date.day << "/" << date.month << "/" << date.year << endl;
    return 0;
}
