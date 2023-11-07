#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string hoTen, gioiTinh, namSinh;

public:
    virtual void nhap();
    virtual void xuat() = 0;
};

class sinhVien : public nguoi
{
protected:
    double gpa;

public:
    virtual void nhap();
    virtual void xuat() = 0;
};
class giangVien
{
protected:
    string mon;

public:
    virtual void nhap();
    virtual void xuat() = 0;
};
class troGiang : public giangVien, public sinhVien
{
private:
    string tenKhoaHoc;

public:
    void nhap();
    void xuat();
};
void nguoi::nhap()
{
    cout << "nhap ho ten: ";
    // cin.ignore();
    getline(cin, hoTen);
    cout << "nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "nhap nam sinh: ";
    getline(cin, namSinh);
}
void giangVien::nhap()
{
    cout << "nhap mon: ";
    getline(cin, mon);
}
void sinhVien::nhap()
{
    cout << "nhap gpa: ";
    cin >> gpa;
}
void troGiang::nhap()
{
    nguoi::nhap();
    giangVien::nhap();
    sinhVien::nhap();
    cout << "nhap ten khoa hoc: ";
    cin.ignore();
    getline(cin, tenKhoaHoc);
}
void troGiang::xuat()
{
    cout << "ho ten: " << hoTen << endl;
    cout << "gioi tinh: " << gioiTinh << endl;
    cout << "nam sinh: " << namSinh << endl;
    cout << "mon: " << mon << endl;
    cout << "gpa: " << gpa << endl;
    cout << "ten khoa hoc: " << tenKhoaHoc << endl;
}
int main()
{
    int n;
    cout << "nhap so tro giang: ";
    cin >> n;
    troGiang a[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        cout << "nhap thong tin tro giang thu " << j << ": ";
        a[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        cout << "thong tin tro giang thu " << j << ": ";
        a[i].xuat();
    }
}