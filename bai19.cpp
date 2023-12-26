#include <bits/stdc++.h>
using namespace std;

class ps1
{
protected:
    int tuSo, mauSo;

public:
    void nhap();
    void xuat();
    void toiGian();
};
class ps2 : public ps1
{
public:
    ps2 &operator=(const ps2 &);
    bool operator<(ps2 &);
};
bool cmp(ps2 a, ps2 b);
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
void ps1::nhap()
{
    cout << "nhap tu so: ";
    cin >> tuSo;
    do
    {
        cout << "nhap mau so: ";
        cin >> mauSo;
    } while (mauSo == 0);
}
void ps1::toiGian()
{
    int ucln = gcd(tuSo, mauSo);
    tuSo /= ucln;
    mauSo /= ucln;
}
void ps1::xuat()
{
    cout << tuSo << "/" << mauSo << " ";
}
ps2 &ps2::operator=(const ps2 &a)
{
    tuSo = a.tuSo;
    mauSo = a.mauSo;
    return *this;
}
bool ps2::operator<(ps2 &a)
{
    if (tuSo * a.mauSo < a.tuSo * mauSo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void minMax(ps2 a[], int n)
{
    ps2 min = a[0], max = a[0];
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
    cout << "phan so nho nhat: ";
    min.xuat();
    cout << endl;
    cout << "phan so lon nhat: ";
    max.xuat();
    cout << endl;
}

int main()
{
    int n;
    cout << "nhap so luong phan so:";
    cin >> n;
    ps2 a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap phan so thu " << i + 1 << ": ";
        a[i].nhap();
        a[i].toiGian();
    }
    cout << "danh sach phan so: ";
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout << endl;
    minMax(a, n);
}