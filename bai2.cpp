#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class daThuc
{
private:
    int bacDaThuc;
    int heSo[100];

public:
    daThuc();
    daThuc(int bac);
    void nhap();
    void xuat();
    daThuc operator+(daThuc &);
    daThuc operator-(daThuc &);
};
daThuc::daThuc()
{
    bacDaThuc = 0;
}
daThuc::daThuc(int bac)
{
    bacDaThuc = bac;
    for (int i = bacDaThuc; i >= 0; i--)
    {
        heSo[i] = 0;
    }
}
void daThuc::nhap()
{
    cout << "nhap bac da thuc: ";
    cin >> bacDaThuc;
    for (int i = bacDaThuc; i >= 0; i--)
    {
        cout << "nhap he so cua x^" << i << ": ";
        cin >> heSo[i];
    }
}
void daThuc::xuat()
{
    for (int i = bacDaThuc; i >= 0; i--)
    {
        if (i > 1)
        {
            cout << heSo[i] << "x^" << i << " + ";
        }
        else if (i == 1)
        {
            cout << heSo[i] << "x + ";
        }
        else
        {
            cout << heSo[i];
        }
    }
    cout << endl;
}
daThuc daThuc::operator+(daThuc &a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= temp.bacDaThuc; i++)
    {
        temp.heSo[i] = this->heSo[i] + a.heSo[i];
    }
    return temp;
}
daThuc daThuc::operator-(daThuc &a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= temp.bacDaThuc; i++)
    {
        temp.heSo[i] = this->heSo[i] - a.heSo[i];
    }
    return temp;
}
int main()
{
    daThuc a, b, c;
    cout << "nhap da thuc a: ";
    a.nhap();
    cout << "nhap da thuc b: ";
    b.nhap();
    c = a + b;
    cout << "da thuc c = a + b: ";
    c.xuat();
    cout << "da thuc c = a - b: ";
    c = a - b;
    c.xuat();
    return 0;
}