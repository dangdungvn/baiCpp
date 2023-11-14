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
    void nhap();
    void xuat();
    string getName();
};
class Sv : public nguoi
{
private:
    string maSV;
    double gpa;

public:
    Sv();
    void nhap();
    void xuat();
    string getMaSV();
};
nguoi::nguoi()
{
    name = "";
    date = "";
}
void nguoi::nhap()
{
    cout << "nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, name);
    cout << "nhap ngay sinh: ";
    cin >> date;
}
void nguoi::xuat()
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
void Sv::nhap()
{
    nguoi::nhap();
    cout << "nhap ma sinh vien: ";
    cin >> maSV;
    cout << "nhap diem tb: ";
    cin >> gpa;
}
void Sv::xuat()
{
    nguoi::xuat();
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
        a[i].nhap();
    }
    string s;
    cout << "nhap thong tin sinh vien can tim: ";
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        if ((a[i].getName().find(s) != string::npos) || (a[i].getMaSV().find(s) != string::npos))
        {
            cout << "thong tin sinh vien can tim: ";
            a[i].xuat();
        }
        else
        {
            cout << "khong tim thay sinh vien can tim" << endl;
        }
    }
}