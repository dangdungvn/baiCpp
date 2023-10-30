#include <bits/stdc++.h>
using namespace std;
class maTran
{
private:
    int soHang;
    int soCot;
    int phanTu[100][100];

public:
    maTran();
    void in();
    void out();
    friend maTran congMaTran(maTran a, maTran b);
};
maTran::maTran()
{
    soHang = 0;
    soCot = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            phanTu[i][j] = 0;
        }
    }
}
void maTran::in()
{
    cin >> soHang >> soCot;
    for (int i = 0; i < soHang; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            cin >> phanTu[i][j];
        }
    }
}
void maTran::out()
{
    for (int i = 0; i < soHang; i++)
    {
        for (int j = 0; j < soCot; j++)
        {
            cout << phanTu[i][j] << " ";
        }
        cout << endl;
    }
}
maTran congMaTran(maTran a, maTran b)
{
    maTran c;
    c.soHang = a.soHang;
    c.soCot = a.soCot;
    for (int i = 0; i < c.soHang; i++)
    {
        for (int j = 0; j < c.soCot; j++)
        {
            c.phanTu[i][j] = a.phanTu[i][j] + b.phanTu[i][j];
        }
    }
    return c;
}
int main()
{
    maTran a, b;
    a.in();
    b.in();
    maTran c = congMaTran(a, b);
    c.out();
}