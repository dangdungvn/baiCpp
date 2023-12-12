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
    // void nhap();
    // void xuat();
    friend istream &operator>>(istream &in, daThuc &);
    friend ostream &operator<<(ostream &out, daThuc);
    daThuc operator+(daThuc);
    daThuc operator-(daThuc);
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
istream &operator>>(istream &in, daThuc &a)
{
    cout << "nhap bac da thuc: ";
    in >> a.bacDaThuc;
    for (int i = a.bacDaThuc; i >= 0; i--)
    {
        cout << "nhap he so cua x^" << i << ": ";
        in >> a.heSo[i];
    }
    return in;
}
ostream &operator<<(ostream &out, daThuc a)
{
    for (int i = a.bacDaThuc; i >= 0; i--)
    {
        if (i > 1)
        {
            out << a.heSo[i] << "x^" << i << " + ";
        }
        else if (i == 1)
        {
            out << a.heSo[i] << "x + ";
        }
        else
        {
            out << a.heSo[i];
        }
    }
    out << endl;
    return out;
}
// void daThuc::nhap()
// {
//     cout << "nhap bac da thuc: ";
//     cin >> bacDaThuc;
//     for (int i = bacDaThuc; i >= 0; i--)
//     {
//         cout << "nhap he so cua x^" << i << ": ";
//         cin >> heSo[i];
//     }
// }
// void daThuc::xuat()
// {
//     for (int i = bacDaThuc; i >= 0; i--)
//     {
//         if (i > 1)
//         {
//             cout << heSo[i] << "x^" << i << " + ";
//         }
//         else if (i == 1)
//         {
//             cout << heSo[i] << "x + ";
//         }
//         else
//         {
//             cout << heSo[i];
//         }
//     }
//     cout << endl;
// }
daThuc daThuc::operator+(daThuc a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= this->bacDaThuc; i++)
    {
        temp.heSo[i] += heSo[i];
    }
    for (int i = 0; i <= a.bacDaThuc; i++)
    {
        temp.heSo[i] += a.heSo[i];
    }
    return temp;
}
daThuc daThuc::operator-(daThuc a)
{
    int maxBac = max(this->bacDaThuc, a.bacDaThuc);
    daThuc temp(maxBac);
    for (int i = 0; i <= this->bacDaThuc; i++)
    {
        temp.heSo[i] += heSo[i];
    }
    for (int i = 0; i <= a.bacDaThuc; i++)
    {
        temp.heSo[i] -= a.heSo[i];
    }
    return temp;
}
int main()
{
    daThuc a, b, c;
    cout << "nhap da thuc a: " << endl;
    cin >> a;
    cout << "nhap da thuc b: " << endl;
    cin >> b;
    c = a + b;
    cout << "da thuc c = a + b: " << c;
    c = a - b;
    cout << "da thuc c = a - b: " << c;
    return 0;
}