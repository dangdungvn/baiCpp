#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class monHoc
{
protected:
    string tenMonHoc;
    float diemCC, diemKT, diemDT;

public:
    monHoc();
    monHoc(string tenMonHoc, float diemCC, float diemKT, float diemDT);
    void nhap();
    void xuat();
    float diemHocPhan();
    float getDiemCC();
    float getDiemKT();
};
class sinhVien : public monHoc
{
private:
    string hoTen, lop, maSV;

public:
    sinhVien();
    sinhVien(string hoTen, string lop, string maSV, string tenMonHoc, float diemCC, float diemKT, float diemDT);
    void nhap();
    void xuat();
};
monHoc::monHoc()
{
    tenMonHoc = "";
    diemCC = diemKT = diemDT = 0;
}
monHoc::monHoc(string tenMonHoc, float diemCC, float diemKT, float diemDT)
{
    this->tenMonHoc = tenMonHoc;
    this->diemCC = diemCC;
    this->diemKT = diemKT;
    this->diemDT = diemDT;
}
sinhVien::sinhVien() : monHoc() // sinhVien a
{
    hoTen = "";
    lop = "";
    maSV = "";
}
sinhVien::sinhVien(string hoTen, string lop, string maSV, string tenMonHoc, float diemCC, float diemKT, float diemDT) : monHoc(tenMonHoc, diemCC, diemKT, diemDT)
{
    this->hoTen = hoTen;
    this->lop = lop;
    this->maSV = maSV;
}
float monHoc::diemHocPhan()
{
    return diemCC * 0.1 + diemKT * 0.3 + diemDT * 0.6;
}
void monHoc::nhap()
{
    cout << "Nhap ten mon hoc: ";
    getline(cin, tenMonHoc);
    cout << "Nhap diem chuyen can: ";
    cin >> diemCC;
    cout << "Nhap diem kiem tra: ";
    cin >> diemKT;
    cout << "Nhap diem thi: ";
    cin >> diemDT;
}
void monHoc::xuat()
{
    cout << left << setw(20) << tenMonHoc << setw(10) << fixed << setprecision(2) << diemHocPhan() << endl;
}
void sinhVien::nhap()
{
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap ma sinh vien: ";
    getline(cin, maSV);
    monHoc::nhap();
}
void sinhVien::xuat()
{
    cout << left << setw(30) << hoTen << setw(10) << lop << setw(10) << maSV;
    monHoc::xuat();
}
float monHoc::getDiemCC()
{
    return this->diemCC;
}
float monHoc::getDiemKT()
{
    return this->diemKT;
}
void tieuDe()
{
    cout << left << setw(30) << "Ho ten" << setw(10) << "Lop" << setw(10) << "Ma SV" << setw(20) << "Ten mon hoc" << setw(10) << "DHP" << endl;
}
int main()
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    sinhVien a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        a[i].nhap();
    }
    tieuDe();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << "Danh sach sinh vien bi cam thi: " << endl;
    tieuDe();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getDiemCC() < 5 || a[i].getDiemKT() < 5)
        {
            a[i].xuat();
        }
    }
}