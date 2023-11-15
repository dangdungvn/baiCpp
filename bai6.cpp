#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string hoTen, namSinh;

public:
    nguoi();
    nguoi(string hoTen, string namSinh);
    void nhap();
    void xuat();
    string getHoTen();
};
class Sv : public nguoi
{
private:
    string maSV;
    double gpa;

public:
    Sv();
    Sv(string hoTen, string namSinh, string maSV, double gpa);
    void nhap();
    void xuat();
    string getMaSV();
};
nguoi::nguoi()
{
    hoTen = "";
    namSinh = "";
}
nguoi::nguoi(string hoTen, string namSinh)
{
    this->hoTen = hoTen;
    this->namSinh = namSinh;
}
void nguoi::nhap()
{
    cout << "nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "nhap ngay sinh: ";
    cin >> namSinh;
}
void nguoi::xuat()
{
    cout << left << setw(20) << hoTen << setw(15) << namSinh;
}
string nguoi::getHoTen()
{
    return this->hoTen;
}
Sv ::Sv() : nguoi()
{
    maSV = "";
    gpa = 0;
}
Sv ::Sv(string hoTen, string namSinh, string maSV, double gpa) : nguoi(hoTen, namSinh)
{
    this->maSV = maSV;
    this->gpa = gpa;
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
    cout << left << setw(10) << maSV << setw(5) << gpa << endl;
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
    cout << left << setw(20) << "ho ten" << setw(15) << "nam sinh" << setw(10) << "ma sv" << setw(5) << "gpa" << endl;

    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    string s;
    cout << "nhap thong tin sinh vien can tim: ";
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        if ((a[i].getHoTen().find(s) != string::npos) || (a[i].getMaSV().find(s) != string::npos))
        {
            cout << "thong tin sinh vien can tim: " << endl;
            cout << left << setw(20) << "ho ten" << setw(15) << "nam sinh" << setw(10) << "ma sv" << setw(5) << "gpa" << endl;
            a[i].xuat();
        }
    }
}