#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class sp1
{
protected:
    int phanThuc, phanAo;

public:
    sp1();
    void nhap();
    void xuat();
    double module();
};
class sp2 : public sp1
{
public:
    sp2 &operator=(const sp2 &a);
    bool operator<(sp2 &a);
};

sp1::sp1()
{
    phanThuc = 0;
    phanAo = 0;
}
void sp1::nhap()
{
    cout << "nhap phan thuc: ";
    cin >> phanThuc;
    cout << "nhap phan ao: ";
    cin >> phanAo;
}
double sp1::module()
{
    return sqrt(phanThuc * phanThuc + phanAo * phanAo);
}
void sp1::xuat()
{
    cout << phanThuc << "+" << phanAo << "*i, ";
}
sp2 &sp2::operator=(const sp2 &a)
{
    phanThuc = a.phanThuc;
    phanAo = a.phanAo;
    return *this;
}
bool sp2::operator<(sp2 &a)
{
    return this->module() < a.module();
}
bool cmp(sp2 a, sp2 b)
{
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    sp2 a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}