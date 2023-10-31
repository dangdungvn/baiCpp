#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class hcn
{
private:
    int cDai, cRong;

public:
    void nhap();
    void xuat();
    int chuVi();
    int dienTich();
    void setCDai(int a);
    void setCRong(int a);
    int getCDai();
    int getCRong();
};
void hcn::nhap()
{
    cout << "nhap chieu dai: ";
    cin >> cDai;
    cout << "nhap chieu rong: ";
    cin >> cRong;
}
void hcn::xuat()
{
    cout << "Chu vi hinh chu nhat la: " << chuVi() << endl;
    cout << "Dien tich hinh chu nhat la: " << dienTich() << endl;
}
int hcn::chuVi()
{
    return (cDai + cRong) * 2;
}
int hcn::dienTich()
{
    return cDai * cRong;
}
void hcn::setCDai(int a)
{
    this->cDai = a;
}
void hcn::setCRong(int a)
{
    this->cRong = a;
}
int hcn::getCDai()
{
    return this->cDai;
}
int hcn::getCRong()
{
    return this->cRong;
}
int main()
{
    hcn a;
    a.nhap();
    a.xuat();
}