#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class hinhVuong
{
protected:
    int canh;

public:
    void in();
    void out();
    int chuVi();
    int dienTich();
    int getCanh();
};
class hcn : public hinhVuong
{
private:
    int canhCL;

public:
    void in();
    void out();
    int chuVi();
    int dienTich();
};
void hinhVuong::in()
{
    cin >> canh;
}
int hinhVuong::chuVi()
{
    return this->canh * 4;
}
int hinhVuong::dienTich()
{
    return this->canh * this->canh;
}
void hinhVuong::out()
{
    cout << this->chuVi() << endl;
    cout << this->dienTich() << endl;
}
int hinhVuong::getCanh()
{
    return this->canh;
}
void hcn::in()
{
    hinhVuong::in();
    cin >> canhCL;
}
int hcn::chuVi()
{
    return (canh + canhCL) * 2;
}
int hcn::dienTich()
{
    return canh * canhCL;
}
void hcn::out()
{
    cout << this->chuVi() << endl;
    cout << this->dienTich() << endl;
}
int main()
{
    int n;
    cin >> n;
    hinhVuong a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].in();
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i].getCanh();
    }
    int maxCanh = a[0].getCanh();
    for (int i = 1; i < n; i++)
    {
        if (maxCanh < a[i].getCanh())
        {
            maxCanh = a[i].getCanh();
        }
    }
    cout << "dien tich lon nhat la: " << maxCanh * maxCanh << endl;
    cout << "vi tri cua hinh vuong do: ";
    for (int i = 0; i < n; i++)
    {
        if (maxCanh == a[i].getCanh())
        {
            cout << i << " ";
        }
    }
}