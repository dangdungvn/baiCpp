#include <bits/stdc++.h>
using namespace std;
class daThuc
{
private:
    int bacDaThuc;
    int heSo[100];

public:
    daThuc();
    friend void in(daThuc &);
    friend void out(daThuc);
    daThuc operator+(daThuc a);
    daThuc operator-(daThuc a);
    int getBacDaThuc();
};
int cmp(daThuc a, daThuc b);
daThuc::daThuc()
{
    this->bacDaThuc = 0;
    for (int i = 0; i < 100; i++)
    {
        this->heSo[i] = 0;
    }
}
void in(daThuc &a)
{
    cout << "Nhap bac da thuc: ";
    cin >> a.bacDaThuc;
    for (int i = 0; i <= a.bacDaThuc; i++)
    {
        cout << "Nhap he so thu " << i + 1 << ": ";
        cin >> a.heSo[i];
    }
}
int daThuc::getBacDaThuc()
{
    return this->bacDaThuc;
}
daThuc daThuc::operator+(daThuc a)
{
    daThuc sum;
    sum.bacDaThuc = cmp(*this, a);
    for (int i = sum.bacDaThuc; i >= 0; i--)
    {
        sum.heSo[i] = this->heSo[i] + a.heSo[i];
    }
    return sum;
}
daThuc daThuc::operator-(daThuc a)
{
    daThuc sub;
    sub.bacDaThuc = cmp(*this, a);
    for (int i = sub.bacDaThuc; i >= 0; i--)
    {
        sub.heSo[i] = this->heSo[i] - a.heSo[i];
    }
    return sub;
}
void out(daThuc a)
{
    for (int i = 0; i < a.bacDaThuc; i++)
    {
        cout << a.heSo[i] << "x^" << a.bacDaThuc - i << " + ";
    }
    cout << a.heSo[a.bacDaThuc] << " = 0" << endl;
}
int cmp(daThuc a, daThuc b)
{
    if (a.getBacDaThuc() >= b.getBacDaThuc())
    {
        return a.getBacDaThuc();
    }
    else
    {
        return b.getBacDaThuc();
    }
}
int main()
{
    daThuc a, b;
    in(a);
    in(b);
    daThuc sum = a + b;
    daThuc sub = a - b;
    out(sum);
    out(sub);
    return 0;
}