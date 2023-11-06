#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
class ps
{
private:
    int tu, mau;

public:
    ps();
    void nhap();
    void hienThi();
    bool operator==(ps a);
    ps operator+(ps a);
    bool operator>(ps a);
    ps toiGian();
};
ps::ps()
{
    tu = 0;
    mau = 1;
}
void ps::nhap()
{
    cout << "nhap tu so: ";
    cin >> tu;
    do
    {
        cout << "nhap mau so: ";
        cin >> mau;
    } while (mau == 0);
}
void ps::hienThi()
{
    cout << tu << "/" << mau << endl;
}
ps ps::toiGian()
{
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
    return *this;
}
bool ps::operator==(ps a)
{
    return tu * a.mau == a.tu * mau;
}
ps ps::operator+(ps a)
{
    ps temp;
    temp.tu = tu * a.mau + a.tu * mau;
    temp.mau = mau * a.mau;
    return temp;
}
bool ps::operator>(ps a)
{
    return tu * a.mau > a.tu * mau;
}
bool cmp(ps a, ps b)
{
    return a > b;
}
int main()
{
    int n;
    cout << "nhap so phan so: ";
    cin >> n;
    ps a[n];
    for (int i = 0; i < n; i++)
    {
        int j = i;
        cout << "nhap phan so thu " << j + 1 << endl;
        a[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        int j = i;
        cout << "phan so thu " << j + 1 << " la: ";
        a[i].hienThi();
    }
    ps sum;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    sum.toiGian();
    cout << "tong cua n phan so: ";
    sum.hienThi();
    sort(a, a + n, cmp);
    cout << "phan so lon nhat la: ";
    a[0].hienThi();
    ps t;
    cout << "nhap phan so can tim: ";
    t.nhap();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == t)
        {
            cout << "ton tai phan so t trong n";
        }
    }
}