#include <bits/stdc++.h>
using namespace std;
class MTV
{
private:
    int capMT;
    int heSo[100][100];

public:
    void nhap();
    void xuat();
    int tongDCC();
    int tongDCP();
};

void MTV::nhap()
{
    cout << "nhap cap ma tran vuong: ";
    cin >> capMT;
    for (int i = 0; i < capMT; i++)
    {
        for (int j = 0; j < capMT; j++)
        {
            cout << "nhap he so thu " << i << " " << j << ": ";
            cin >> heSo[i][j];
        }
    }
}
void MTV::xuat()
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
int MTV::tongDCC()
{
    int sum = 0;
    for (int i = 0; i < capMT; i++)
    {
        sum += heSo[i][i];
    }
    return sum;
}
int MTV::tongDCP()
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
    MTV mtv;
    cout << "nhap ma tran vuong: " << endl;
    mtv.nhap();
    cout << "ma tran vuong: " << endl;
    mtv.xuat();
    cout << "tong duong cheo chinh: " << mtv.tongDCC() << endl;
    cout << "tong duong cheo phu: " << mtv.tongDCP() << endl;
    return 0;
}
