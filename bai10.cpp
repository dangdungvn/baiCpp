#include <bits/stdc++.h>
using namespace std;
class nhanSu
{
protected:
    string maNV, hoTen, namSinh;

public:
    void nhap();
    void xuat();
};
class canBo : public nhanSu
{
private:
    long long luongCoBan, heSoLuong;

public:
    void nhap();
    void xuat();
    long long tinhLuong();
    long long getLuongCoBan();
    long long getHeSoLuong();
    friend void xapXep(canBo a[], int n);
};
void nhanSu::nhap()
{
    cin.ignore();
    cout << "nhap ma nhan vien: ";
    getline(cin, maNV);
    cout << "nhap ho ten: ";
    getline(cin, hoTen);
    cout << "nhap nam sinh: ";
    getline(cin, namSinh);
}
void nhanSu::xuat()
{
    cout << left << setw(10) << maNV << setw(20) << hoTen << setw(15) << namSinh;
}
void canBo::nhap()
{
    nhanSu::nhap();
    cout << "nhap luong co ban: ";
    cin >> luongCoBan;
    cout << "nhap he so luong: ";
    cin >> heSoLuong;
}
void canBo::xuat()
{
    nhanSu::xuat();
    cout << setw(15) << tinhLuong() << endl;
}
long long canBo::tinhLuong()
{
    return luongCoBan * heSoLuong;
}
long long canBo::getLuongCoBan()
{
    return this->luongCoBan;
}
long long canBo::getHeSoLuong()
{
    return this->heSoLuong;
}
void tieuDe()
{
    cout << left << setw(10) << "Ma nv" << setw(20) << "Ho ten" << setw(15) << "Nam sinh" << setw(15) << "Luong" << endl;
}
void xapXep(canBo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].tinhLuong() < a[j].tinhLuong())
            {
                canBo temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    tieuDe();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}
int main()
{
    int n;
    cout << "nhap so luong can bo: ";
    cin >> n;
    canBo a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin can bo thu " << i << endl;
        a[i].nhap();
    }
    tieuDe();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << "danh sach can bo sau khi sap xep: " << endl;
    xapXep(a, n);
}