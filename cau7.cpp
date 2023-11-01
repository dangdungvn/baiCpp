#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class mtv
{
private:
    int capMT;
    int heSo[100][100];

public:
    void in();
    void out();
    int tongCc();
    int tongCp();
};
void mtv::in()
{
    cout << "nhap cap MT: ";
    cin >> capMT;
    cout << "nhap he so: ";
    for (int i = 0; i < capMT; i++)
    {
        for (int j = 0; j < capMT; j++)
        {
            cin >> heSo[i][j];
        }
    }
}
void mtv::out()
{
    for (int i = 0; i < capMT; i++)
    {
        for (int j = 0; j < capMT; j++)
        {
            cout << heSo[i][j] << " ";
        }
        cout << endl;
    }
}
int mtv::tongCc()
{
    int sum = 0;
    for (int i = 0; i < capMT; i++)
    {
        sum += heSo[i][i];
    }
    return sum;
}
int mtv::tongCp()
{
    int sum = 0;
    for (int i = 0; i < capMT; i++)
    {
        sum += heSo[i][capMT - i - 1];
    }
    return sum;
}
int main()
{
    mtv a;
    a.in();
    a.out();
    cout << "tong cac phan tu tren duong cheo chinh: ";
    cout << a.tongCc() << endl;
    cout << "tong cac phan tu tren duong cheo phu: ";
    cout << a.tongCp() << endl;
}