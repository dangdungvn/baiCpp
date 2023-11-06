#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class vienChuc
{
protected:
    string maSo, hoTen, chucVu;
    long long luong;

public:
    virtual void nhap();
    virtual void xuat() = 0;
    virtual long long tinhLuong() = 0;
};
class bienChe : public vienChuc
{
private:
    long long heSoLuong;

public:
    static int STT1;
    void nhap();
    void xuat();
    long long tinhLuong();
};
class hopDong : public vienChuc
{
private:
    int soNgayLam;

public:
    static int STT2;
    void nhap();
    void xuat();
    long long tinhLuong();
};

void vienChuc::nhap()
{
    cout << "nhap ma so: ";
    cin >> maSo;
    cout << "nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "nhap chuc vu: ";
    getline(cin, chucVu);
}

void bienChe::nhap()
{

    vienChuc::nhap();
    cout << "nhap he so luong: ";
    cin >> heSoLuong;
}
void bienChe::xuat()
{
    bienChe::STT1++;
    cout << left << setw(10) << bienChe::STT1 << setw(30) << hoTen << setw(15) << heSoLuong << setw(10) << tinhLuong() << endl;
}
int bienChe::STT1 = 0;
long long bienChe::tinhLuong()
{
    if (chucVu == "pho giam doc")
        return (heSoLuong * 830000 + 100000) * 95 / 100;
    else if (chucVu == "giam doc")
        return (heSoLuong * 830000 + 150000) * 95 / 100;
    else
        return (heSoLuong * 830000) * 95 / 100;
}

void hopDong::nhap()
{

    vienChuc::nhap();
    cout << "nhap so ngay lam: ";
    cin >> soNgayLam;
}
int hopDong::STT2 = 0;
long long hopDong::tinhLuong()
{
    if (soNgayLam <= 26)
    {
        return (1500000 - (26 - soNgayLam) * 50000) * 95 / 100;
    }
    else
    {
        return (1500000 + (soNgayLam - 26) * 100000) * 95 / 100;
    }
}
void hopDong::xuat()
{
    hopDong::STT2++;
    cout << left << setw(10) << hopDong::STT2 << setw(30) << hoTen << setw(15) << soNgayLam << setw(10) << tinhLuong() << endl;
}
int main()
{
    int n, m;
    cout << "nhap so luong can bo: ";
    cin >> n;
    bienChe a[n];
    for (int i = 0; i < n; i++)
    {
        int j = i;
        cout << "nhap can bo thu " << j + 1 << endl;
        a[i].nhap();
    }
    cout << "BANG DANH SACH TIEN LUONG CAN BO BIEN CHE" << endl;
    cout << left << setw(10) << "STT" << setw(30) << "Ho ten" << setw(15) << "He so luong" << setw(10) << "Luong" << endl;
    for (int i = 0; i < n; i++)
    {

        a[i].xuat();
    }
    cout << "nhap so luong nhan vien hop dong: ";
    cin >> m;
    hopDong b[m];
    for (int i = 0; i < m; i++)
    {
        int j = i;
        cout << "nhap nhan vien thu " << j + 1 << endl;
        b[i].nhap();
    }
    cout << "BANG DANH SACH TIEN LUONG NHAN VIEN HOP DONG" << endl;
    cout << left << setw(10) << "STT" << setw(30) << "Ho ten" << setw(15) << "So ngay lam" << setw(10) << "Luong" << endl;
    for (int i = 0; i < m; i++)
    {
        b[i].xuat();
    }
}
