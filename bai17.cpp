#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class diem
{
private:
    int toaDoX;
    int toaDoY;

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
    friend void kiemTra(tamGiac a);
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
    cout << "nhap dinh thu nhat cua tam giac: " << endl;
    a.nhap();
    cout << "nhap dinh thu hai cua tam giac: " << endl;
    b.nhap();
    cout << "nhap dinh thu ba cua tam giac: " << endl;
    c.nhap();
    canh1 = khoangCach(a, b);
    canh2 = khoangCach(b, c);
    canh3 = khoangCach(c, a);
}
void tamGiac::xuat()
{
    cout << "canh thu nhat cua tam giac: " << canh1 << endl;
    cout << "canh thu hai cua tam giac: " << canh2 << endl;
    cout << "canh thu ba cua tam giac: " << canh3 << endl;
}
void kiemTra(tamGiac a)
{
    if (a.canh1 + a.canh2 <= a.canh3 || a.canh1 + a.canh3 <= a.canh2 || a.canh2 + a.canh3 <= a.canh1)
    {
        cout << "tam giac khong hop le" << endl;
    }
    else
    {
        if (a.canh1 == a.canh2 && a.canh2 == a.canh3)
        {
            cout << "tam giac deu" << endl;
        }
        else if ((a.canh1 == a.canh2 || a.canh1 == a.canh3 || a.canh2 == a.canh3) && (a.canh1 * a.canh1 + a.canh2 * a.canh2 == a.canh3 * a.canh3 || a.canh1 * a.canh1 + a.canh3 * a.canh3 == a.canh2 * a.canh2 || a.canh2 * a.canh2 + a.canh3 * a.canh3 == a.canh1 * a.canh1))
        {
            cout << "tam giac vuong can" << endl;
        }
        else if (a.canh1 * a.canh1 + a.canh2 * a.canh2 == a.canh3 * a.canh3 || a.canh1 * a.canh1 + a.canh3 * a.canh3 == a.canh2 * a.canh2 || a.canh2 * a.canh2 + a.canh3 * a.canh3 == a.canh1 * a.canh1)
        {
            cout << "tam giac vuong" << endl;
        }
        else if (a.canh1 == a.canh2 || a.canh1 == a.canh3 || a.canh2 == a.canh3)
        {
            cout << "tam giac can" << endl;
        }
        else
        {
            cout << "tam giac thuong" << endl;
        }
    }
}
int main()
{
    tamGiac tg;
    tg.nhap();
    tg.xuat();
    kiemTra(tg);
}