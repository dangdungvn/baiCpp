#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string hoTen, tuoi, namSinh, ngheNghiep;

public:
    void nhap();
    void xuat();
};
class khuPho
{
private:
    int soHo;
    nguoi hoDan[100];
    int soNha;

public:
    void nhap();
    void xuat();
};
void nguoi::nhap()
{
    cout << "nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "nhap nam sinh: ";
    getline(cin, namSinh);
    cout << "nhap tuoi: ";
    getline(cin, tuoi);
    cout << "nhap nghe nghiep: ";
    getline(cin, ngheNghiep);
}
void khuPho::nhap()
{
    cout << "nhap so ho dan: ";
    cin >> soHo;
    for (int i = 0; i < soHo; i++)
    {
        int j = i;
        cout << "nhap ho dan thu " << j + 1 << ": " << endl;
        hoDan[i].nhap();
    }
}
