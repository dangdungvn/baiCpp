#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int day, int month, int year);
    ~Date();
    friend istream &operator>>(istream &in, Date &a);
    friend ostream &operator<<(ostream &out, Date a);
    Date &operator++();
    Date operator++(int);
    Date &operator--();
    Date operator--(int);
    int getDayInMonth();
};
Date::Date()
{
    day = month = year = 0;
}
Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Date::~Date()
{
    day = month = year = 0;
}

istream &operator>>(istream &in, Date &a)
{
    in >> a.day >> a.month >> a.year;
    return in;
}
ostream &operator<<(ostream &out, Date a)
{

    if (a.day < 10 && a.month < 10)
    {
        out << "0" << a.day << "/"
            << "0" << a.month << "/" << a.year;
    }
    else if (a.day < 10)
    {
        out << "0" << a.day << "/" << a.month << "/" << a.year;
    }
    else if (a.month < 10)
    {
        out << a.day << "/"
            << "0" << a.month << "/" << a.year;
    }
    else
    {
        out << a.day << "/" << a.month << "/" << a.year;
    }
    return out;
}

Date &Date::operator++()
{
    day++;
    if (day > getDayInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return *this;
}
Date Date::operator++(int)
{
    Date temp = *this;
    this->day++;
    if (this->day > getDayInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return temp;
}
Date &Date::operator--()
{
    day--;
    if (day < 1)
    {
        day = getDayInMonth();
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
    }
    return *this;
}
Date Date::operator--(int)
{
    Date temp = *this;
    this->day--;
    if (this->day < 1)
    {
        day = getDayInMonth();
        month--;
        if (month < 1)
        {
            month = 12;
            year--;
        }
    }
    return temp;
}
int Date::getDayInMonth()
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        return 31;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}
int main()
{
    Date a;
    cin >> a;
    a++;
    cout << a;
    return 0;
}