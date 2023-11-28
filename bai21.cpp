#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class SP1
{
protected:
    int phanThuc, phanAo;

public:
    SP1();
    SP1(int phanThuc, int phanAo);
    void nhap();
    void xuat();
    double module();
};
class SP2 : public SP1
{
public:
    SP2();
    SP2(int phanThuc, int phanAo);
    bool operator=(SP2 a);
    bool operator<(SP2 a);
    bool operator==(SP2 a);
    SP2 operator+(SP2 a);
};
SP1::SP1()
{
    phanThuc = 0;
    phanAo = 0;
}
SP1::SP1(int phanThuc, int phanAo)
{
    this->phanThuc = phanThuc;
    this->phanAo = phanAo;
}
void SP1::nhap()
{
    cout << "Nhap phan thuc: ";
    cin >> phanThuc;
    cout << "Nhap phan ao: ";
    cin >> phanAo;
}
void SP1::xuat()
{
    cout << phanThuc << " + " << phanAo << "i, ";
}
double SP1::module()
{
    return sqrt(phanThuc * phanThuc + phanAo * phanAo);
}
SP2::SP2() : SP1()
{
}
SP2::SP2(int phanThuc, int phanAo) : SP1(phanThuc, phanAo)
{
}
bool SP2::operator=(SP2 a)
{
    phanThuc = a.phanThuc;
    phanAo = a.phanAo;
    return true;
}
bool SP2::operator<(SP2 a)
{
    return module() < a.module();
}
bool SP2::operator==(SP2 a)
{
    return (phanThuc == a.phanThuc && phanAo == a.phanAo);
}
SP2 SP2::operator+(SP2 a)
{
    SP2 tong;
    tong.phanThuc = phanThuc + a.phanThuc;
    tong.phanAo = phanAo + a.phanAo;
    return tong;
}
void nhap(SP2 a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap so phuc thu " << i + 1 << ": " << endl;
        a[i].nhap();
    }
}
void xuat(SP2 a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << endl;
}
void sapXep(SP2 a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                SP2 temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Mang so phuc sau khi sap xep: ";
    xuat(a, n);
}
void minMax(SP2 a[], int n)
{
    SP2 min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (max < a[i])
        {
            max = a[i];
        }
    }
    cout << "So phuc co module nho nhat: ";
    min.xuat();
    cout << endl;
    cout << "So phuc co module lon nhat: ";
    max.xuat();
    cout << endl;
}
void tong(SP2 a[], int n)
{
    SP2 tong;
    for (int i = 0; i < n; i++)
    {
        tong = tong + a[i];
    }
    cout << "Tong cac so phuc trong mang: ";
    tong.xuat();
    cout << endl;
}
void dem(SP2 a[], int n)
{
    int dem = 0;
    SP2 temp(3, 4);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == temp)
        {
            dem++;
        }
    }
    cout << "So luong so phuc bang (3+4i) trong mang: " << dem << endl;
}
int main()
{
    int n;
    cout << "Nhap so luong so phuc: ";
    cin >> n;
    SP2 a[n];
    nhap(a, n);
    sapXep(a, n);
    minMax(a, n);
    tong(a, n);
    dem(a, n);
    return 0;
}