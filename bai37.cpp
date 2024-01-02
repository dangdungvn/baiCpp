#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class nguoi
{
protected:
    string hoTen, gioiTinh, namSinh;

public:
    virtual void nhap();
    virtual void xuat();
};
class sinhVien : virtual public nguoi
{
protected:
    double diemTB;

public:
    void nhap();
    void xuat();
};
class giangVien : virtual public nguoi
{
protected:
    string monGiangDay;

public:
    void nhap();
    void xuat();
};
class troGiang : public sinhVien, public giangVien
{
private:
    string tenKhoaHoc;

public:
    void nhap();
    void xuat();
};
void nguoi::nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap gioi tinh: ";
    getline(cin, gioiTinh);
    cout << "Nhap nam sinh: ";
    getline(cin, namSinh);
}
void nguoi::xuat()
{
    cout << setw(20) << left << hoTen << setw(6) << gioiTinh << setw(6) << namSinh;
}
void sinhVien::nhap()
{
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;
    cin.ignore();
}
void sinhVien::xuat()
{
    cout << setw(6) << diemTB;
}
void giangVien::nhap()
{
    cout << "Nhap mon giang day: ";
    getline(cin, monGiangDay);
}
void giangVien::xuat()
{
    cout << setw(20) << monGiangDay;
}
void troGiang::nhap()
{
    nguoi::nhap();
    sinhVien::nhap();
    giangVien::nhap();
    cout << "Nhap ten khoa hoc: ";
    getline(cin, tenKhoaHoc);
}
void troGiang::xuat()
{
    nguoi::xuat();
    sinhVien::xuat();
    giangVien::xuat();
    cout << setw(15) << tenKhoaHoc << endl;
}
int main()
{
    int n;
    cout << "Nhap so luong tro giang: ";
    cin >> n;
    troGiang *a = new troGiang[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin tro giang thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << setw(20) << left << "Ho ten" << setw(6) << "GT" << setw(6) << "NS" << setw(6) << "DTB" << setw(20) << "Mon giang day" << setw(15) << "Ten khoa hoc" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    delete[] a;
}