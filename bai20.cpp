#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class sp1
{
protected:
    int phanThuc, phanAo;

public:
    void nhap();
    void in();
    double module();
};
class sp2 : public sp1
{
public:
    sp2 &operator=(const sp2 &a);
    bool operator>(sp2 &a);
};
bool cmp(sp2 a, sp2 b);
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
void sp1::in()
{
    cout << phanThuc << "+" << phanAo << "*i, ";
}
sp2 &sp2::operator=(const sp2 &a)
{
    this->phanThuc = a.phanThuc;
    this->phanAo = a.phanAo;
    return *this;
}
bool sp2::operator>(sp2 &a)
{
    return this->module() > a.module();
}
bool cmp(sp2 a, sp2 b)
{
    return a > b;
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
        a[i].in();
    }
}