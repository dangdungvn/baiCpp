#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class monHoc
{
protected:
    string tenMonHoc;
    int cc, kt, dt;

public:
    double tinhHocPhan();
    int getCC() { return cc; }
    int getKT() { return kt; }
};

class sinhVien : public monHoc
{
private:
    string hoTen, lop, MaSV;

public:
    void nhap();
    void xuat();
};
double monHoc::tinhHocPhan()
{
    return 1.0 * (cc * 0.1 + kt * 0.2 + dt * 0.7);
}
void sinhVien::nhap()
{
    cin.ignore();
    cout << "nhap ho ten: ";
    getline(cin, hoTen);
    cout << "nhap lop: ";
    getline(cin, lop);
    cout << "nhap ma sinh vien: ";
    getline(cin, MaSV);
    cout << "nhap ten mon hoc: ";
    getline(cin, tenMonHoc);
    cout << "nhap diem chuyen can: ";
    cin >> cc;
    cout << "nhap diem kiem tra: ";
    cin >> kt;
    cout << "nhap diem thi: ";
    cin >> dt;
}
void sinhVien::xuat()
{
    cout << left << setw(20) << hoTen << setw(20) << lop << setw(20) << MaSV << setw(20) << tenMonHoc << setw(10) << fixed << setprecision(2) << tinhHocPhan() << endl;
}
void tieuDe()
{
    cout << left << setw(20) << "ho ten" << setw(20) << "lop" << setw(20) << "ma sinh vien" << setw(20) << "ten mon hoc" << setw(10) << "diem trung binh" << endl;
}
int main()
{
    int n;
    cout << "nhap so luong sinh vien: ";
    cin >> n;
    sinhVien a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin sinh vien thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "nhung hoc sinh bi cam thi: " << endl;
    tieuDe();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getCC() < 5 || a[i].getKT() == 0)
        {
            a[i].xuat();
        }
    }
}