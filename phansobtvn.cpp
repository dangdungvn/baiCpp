// dùng đệ quy để tìm ra ucln của 2 số nhằm mục đích tối giản các phân số
//(có thể dùng cách khác để tìm ucln của 2 số, hoặc định nghĩa luôn ở trong hàm tối giản)
// khai báo và định nghĩa toán tử > (chú ý là toán tử này có kiểu trả về là bool (boolean))
// so sánh và tìm ra phân số lớn nhất giống như bài trước
#include <bits/stdc++.h>
#include <algorithm>
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
    int minx;
    if (a <= b)
    {
        minx = a;
    }
    else
    {
        minx = b;
    }
    for (int i = minx; i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}
class ps
{
private:
    int tu, mau;

public:
    // void nhap();
    // void xuat();
    friend istream &operator>>(istream &in, ps &a);
    friend ostream &operator<<(ostream &out, ps a);
    ps operator+(ps a);
    ps operator-(ps a);
    void toiGian();
    bool operator>(ps a);
    friend bool cmp(ps a, ps b);
    bool cmp1(ps a);
    int getTu();
    int getMau();
};
void ps::toiGian()
{
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
}
// void ps::nhap()
// {
//     cin >> tu >> mau;
// }
// void ps::xuat()
// {
//     cout << "(" << tu << "/" << mau << ")";
// }
istream &operator>>(istream &in, ps &a)
{
    in >> a.tu >> a.mau;
    return in;
}
ostream &operator<<(ostream &out, ps a)
{
    out << "(" << a.tu << "/" << a.mau << ")";
    return out;
}
ps ps::operator+(ps a)
{
    ps temp;
    temp.tu = tu * a.mau + a.tu * mau;
    temp.mau = mau * a.mau;
    temp.toiGian();
    return temp;
}
ps ps::operator-(ps a)
{
    ps temp;
    temp.tu = tu * a.mau - a.tu * mau;
    temp.mau = mau * a.mau;
    temp.toiGian();
    return temp;
}

bool ps::operator>(ps a)
{
    return tu * a.mau > a.tu * mau;
}

bool cmp(ps a, ps b)
{
    return a.tu * b.mau > a.mau * b.tu;
}

bool ps::cmp1(ps a)
{
    return tu * a.mau > mau * a.tu;
}

int ps::getTu()
{
    return tu;
}
int ps::getMau()
{
    return mau;
}
int main()
{
    int n;
    cout << "nhap so luong phan so: ";
    cin >> n;
    ps a[n];
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        cout << "nhap phan so thu " << j << endl;
        cin >> a[i];
    }
    ps temp = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > temp)
        // if(a[i].cmp1(temp))
        // if(cmp(a[i], temp))
        // if(a[i].getTu() * temp.getMau() > a[i].getMau() * temp.getTu())
        {
            temp = a[i];
        }
    }
    cout << "phan so lon nhat la: ";
    cout << temp << endl;
    return 0;
}