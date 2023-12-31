#include <bits/stdc++.h>
using namespace std;
// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }
int gcd(int a, int b)
{
    int minx = min(a, b);
    for (int i = minx; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
}
class PS1
{
protected:
    int tu, mau;

public:
    void nhap();
    void xuat();
    void toiGian();
};
class PS2 : public PS1
{
public:
    PS2();
    PS2(int tu, int mau);
    PS2 operator+(PS2 a);
    bool operator>(PS2 a);
    bool operator<(PS2 a);
    bool operator=(PS2 a);
};
PS2::PS2()
{
    tu = 0;
    mau = 1;
}
PS2::PS2(int tu, int mau)
{
    this->tu = tu;
    this->mau = mau;
}
void PS1::nhap()
{
    cout << "Nhap tu so: ";
    cin >> tu;
    do
    {
        cout << "Nhap mau so: ";
        cin >> mau;
        if (mau == 0)
            cout << "Mau so khong hop le. Nhap lai!\n";
    } while (mau == 0);
}
void PS1::xuat()
{
    cout << "(" << tu << "/" << mau << ")" << endl;
}
void PS1::toiGian()
{
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
}
PS2 PS2::operator+(PS2 a)
{
    PS2 tong;
    tong.tu = tu * a.mau + mau * a.tu;
    tong.mau = mau * a.mau;
    tong.toiGian();
    return tong;
}
bool PS2::operator>(PS2 a)
{
    return (tu * a.mau > mau * a.tu);
}
bool PS2::operator<(PS2 a)
{
    return (tu * a.mau < mau * a.tu);
}
bool PS2::operator=(PS2 a)
{
    tu = a.tu;
    mau = a.mau;
    return true;
}
void nhap(PS2 a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << i + 1 << endl;
        a[i].nhap();
    }
}
void sapXep(PS2 a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                PS2 temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Danh sach sau khi sap xep: " << endl;
    for (int i = 0; i < n; i++)
        a[i].xuat();
}
void minMax(PS2 a[], int n)
{
    PS2 min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    cout << "Phan so nho nhat: ";
    min.xuat();
    cout << "Phan so lon nhat: ";
    max.xuat();
}
void tongA(PS2 a[], int n)
{
    PS2 tong;
    PS2 temp(1, 2);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < temp)
            tong = tong + a[i];
    }
    cout << "Tong cac phan so nho hon 1/2: ";
    tong.xuat();
}
void tongB(PS2 a[], int n)
{
    PS2 tong;
    PS2 temp(1, 4);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > temp)
            tong = tong + a[i];
    }
    cout << "Tong cac phan so lon hon 1/4: ";
    tong.xuat();
}
int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    PS2 a[n];
    nhap(a, n);
    sapXep(a, n);
    minMax(a, n);
    tongA(a, n);
    tongB(a, n);
}