#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class tamGiac
{
private:
    double canh1, canh2, canh3;

public:
    tamGiac();
    tamGiac(double canh1, double canh2, double canh3);
    void nhap();
    friend void loaiTamGiac(tamGiac a);
    double chuVi();
    double p();
    double dienTich();
    void setA(double canh1);
    void setB(double canh2);
    void setC(double canh3);
    double getCanh1();
    double getCanh2();
    double getCanh3();
};
tamGiac::tamGiac()
{
    canh1 = canh2 = canh3 = 0;
}
tamGiac::tamGiac(double canh1, double canh2, double canh3)
{
    this->canh1 = canh1;
    this->canh2 = canh2;
    this->canh3 = canh3;
}
void tamGiac::nhap()
{
    cout << "nhap canh thu nhat cua tam giac: ";
    cin >> canh1;
    cout << "nhap canh thu hai cua tam giac: ";
    cin >> canh2;
    cout << "nhap canh thu ba cua tam giac: ";
    cin >> canh3;
}
double tamGiac::chuVi()
{
    return canh1 + canh2 + canh3;
}
double tamGiac::p()
{
    return chuVi() / 2;
}
double tamGiac::dienTich()
{
    return sqrt(p() * (p() - canh1) * (p() - canh2) * (p() - canh3));
}
void tamGiac::setA(double canh1) // tam giac a co canh 1 la = 2
{
    this->canh1 = canh1; // tac giac co canh 1 la 3
}
void tamGiac::setB(double canh2)
{
    this->canh2 = canh2;
}
void tamGiac::setC(double canh3)
{
    this->canh3 = canh3;
}
double tamGiac::getCanh1()
{
    return canh1; // tam giac a canh1 = 3 cout << a.canh1
}
double tamGiac::getCanh2()
{
    return canh2;
}
double tamGiac::getCanh3()
{
    return canh3;
}
void loaiTamGiac(tamGiac a)
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
    tamGiac a;
    a.nhap();
    loaiTamGiac(a);
    cout << "chu vi: " << a.chuVi() << endl;
    cout << "dien tich: " << a.dienTich() << endl;
}
