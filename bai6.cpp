#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string name;
    string date;

public:
    nguoi();
    void in();
    void out();
    string getName();
};
class Sv : public nguoi
{
private:
    string maSV;
    double gpa;

public:
    Sv();
    void in();
    void out();
    string getMaSV();
};
nguoi::nguoi()
{
    name = "";
    date = "";
}
void nguoi::in()
{
    cout << "nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, name);
    cout << "nhap ngay sinh: ";
    cin >> date;
}
void nguoi::out()
{
    cout << name << " " << date << " ";
}
string nguoi::getName()
{
    return this->name;
}
Sv ::Sv()
{
    maSV = "";
    gpa = 0;
}
void Sv::in()
{
    nguoi::in();
    cout << "nhap ma sinh vien: ";
    cin >> maSV;
    cout << "nhap diem tb: ";
    cin >> gpa;
}
void Sv::out()
{
    nguoi::out();
    cout << maSV << " " << gpa << endl;
}
string Sv::getMaSV()
{
    return this->maSV;
}
int main()
{
    int n;
    cout << "nhap so luong sinh vien: ";
    cin >> n;
    Sv a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap sinh vien thu " << i << ":" << endl;
        a[i].in();
    }
    string s;
    cout << "nhap thong tin sinh vien can tim: ";
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        if (a[i].getName().find(s) != string::npos)
        {
            cout << "thong tin sinh vien can tim: ";
            a[i].out();
        }
        else
        {
            cout << "khong tim thay sinh vien can tim" << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].getMaSV().find(s) != string::npos)
        {
            cout << "thong tin sinh vien can tim: ";
            a[i].out();
        }
        else
        {
            cout << "khong tim thay sinh vien can tim!" << endl;
        }
    }
}