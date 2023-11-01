#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class daThuc
{
private:
    int bacDaThuc;
    vector<int> heSo;

public:
    void nhap();
    void xuat();
    daThuc cong2DT(daThuc &a);
    daThuc tru2DT(daThuc &a);
};
void daThuc::nhap()
{
    cout << "nhap bac da thuc: ";
    cin >> bacDaThuc;
    heSo.resize(bacDaThuc + 1);
    for (int i = bacDaThuc; i >= 0; i--)
    {
        cout << "nhap he so thu " << i << ": ";
        cin >> heSo[i];
    }
}
void daThuc::xuat()
{
    for (int i = bacDaThuc; i >= 0; i--)
    {
        cout << heSo[i] << "x^" << i << " + ";
    }
    cout << endl;
}
daThuc daThuc::cong2DT(daThuc &a)
{
    daThuc sum;
    sum.bacDaThuc = max(this->bacDaThuc, a.bacDaThuc);
    for (int i = 0; i <= sum.bacDaThuc; i++)
    {
        sum.heSo[i] = this->heSo[i] + a.heSo[i];
    }
    return sum;
}
// chưa xong :v