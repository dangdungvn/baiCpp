#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class diem
{
private:
    int toaDoX, toaDoY;

public:
    void nhap();
    void xuat();
    friend double khoangCach(diem a, diem b);
};
class tamGiac
{
private:
    diem a, b, c;
    double canh1, canh2, canh3;

public:
    void nhap();
    void xuat();
    double getCanh1();
    double getCanh2();
    double getCanh3();
};
void diem::nhap()
{
    cout << "nhap toa do x: ";
    cin >> toaDoX;
    cout << "nhap toa do y: ";
    cin >> toaDoY;
}
double khoangCach(diem a, diem b)
{
    return sqrt((a.toaDoX - b.toaDoX) * (a.toaDoX - b.toaDoX) + (a.toaDoY - b.toaDoY) * (a.toaDoY - b.toaDoY));
}
void diem::xuat()
{
    cout << "(" << toaDoX << ", " << toaDoY << ")";
}
void tamGiac::nhap()
{
    cout << "nhap dinh thu nhat cua tam giac: ";
    cout << endl;
    a.nhap();
    cout << "nhap dinh thu hai cua tam giac: ";
    cout << endl;
    b.nhap();
    cout << "nhap dinh thu ba cua tam giac: ";
    cout << endl;
    c.nhap();
    canh1 = khoangCach(a, b);
    canh2 = khoangCach(b, c);
    canh3 = khoangCach(c, a);
}
void tamGiac::xuat()
{
    cout << "dinh thu nhat cua tam giac: ";
    a.xuat();
    cout << endl;
    cout << "dinh thu hai cua tam giac: ";
    b.xuat();
    cout << endl;
    cout << "dinh thu ba cua tam giac: ";
    c.xuat();
}
double tamGiac::getCanh1()
{
    return canh1;
}
double tamGiac::getCanh2()
{
    return canh2;
}
double tamGiac::getCanh3()
{
    return canh3;
}
int main()
{
    tamGiac a;
    a.nhap();
    if (a.getCanh1() == a.getCanh2() && a.getCanh1() == a.getCanh3())
    {
        cout << "tam giac deu";
    }
    else if (a.getCanh1() == a.getCanh2() || a.getCanh1() == a.getCanh3() || a.getCanh2() == a.getCanh3())
    {
        cout << "tam giac can";
    }
    else if ((a.getCanh1() * a.getCanh1() == a.getCanh2() * a.getCanh2() + a.getCanh3() * a.getCanh3()) || (a.getCanh2() * a.getCanh2() == a.getCanh1() * a.getCanh1() + a.getCanh3() * a.getCanh3()) || (a.getCanh3() * a.getCanh3() == a.getCanh1() * a.getCanh1() + a.getCanh2() * a.getCanh2()))
    {
        cout << "tam giac vuong";
    }
    else
    {
        cout << "tam giac thuong";
    }
}