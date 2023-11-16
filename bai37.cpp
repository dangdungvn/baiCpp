
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string hoTen, gioiTinh, namSinh;

public:
    void nhap();
    void xuat();
};
class sinhVien : public nguoi
{
private:
    double dtb;

public:
    void nhap();
    void xuat();
};
class giangVien : public nguoi
{
private:
    string monHoc;

public:
    void nhap();
    void xuat();
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
    cout << "nhap ten nguoi: ";
    getline(cin, hoTen);
    cout << "nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "nhap nam sinh: ";
    getline(cin, namSinh);
}
void nguoi::xuat()
{
    cout << "ten nguoi: " << hoTen << endl;
    cout << "gioi tinh: " << gioiTinh << endl;
    cout << "nam sinh: " << namSinh << endl;
}
void sinhVien::nhap()
{
    nguoi::nhap();
    cout << "nhap diem trung binh: ";
    cin >> dtb;
}
void sinhVien::xuat()
{
    nguoi::xuat();
    cout << "diem trung binh: " << dtb << endl;
}
void giangVien::nhap()
{
    cout << "nhap ten mon hoc: ";
    cin.ignore();
    getline(cin, monHoc);
}
void giangVien::xuat()
{
    cout << "ten mon hoc: " << monHoc << endl;
}
void troGiang::nhap()
{
    sinhVien::nhap();
    giangVien::nhap();
    cout << "nhap ten khoa hoc: ";
    getline(cin, tenKhoaHoc);
}
void troGiang::xuat()
{
    sinhVien::xuat();
    giangVien::xuat();
    cout << "ten khoa hoc: " << tenKhoaHoc << endl;
}
int main()
{
    troGiang a;
    a.nhap();
    a.xuat();
    return 0;
}