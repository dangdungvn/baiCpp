#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string hoTen, namSinh;
};
class sinhVien : public nguoi
{
private:
    string maSV;
    double gpa;

public:
    void nhap();
    void xuat();
    double getGpa();
    string getMaSV();
};
void sinhVien::nhap()
{
    cout << "nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "nhap nam sinh: ";
    getline(cin, namSinh);
    cout << "nhap ma SV: ";
    getline(cin, maSV);
    cout << "nhap GPA: ";
    cin >> gpa;
}
void sinhVien::xuat()
{
    cout << left << setw(15) << maSV << setw(30) << hoTen << setw(15) << namSinh << setw(5) << gpa << endl;
}
bool cmp(sinhVien a, sinhVien b)
{
    return a.getGpa() > b.getGpa();
}
int main()
{
    int n;
    cout << "nhap so sinh vien: ";
    cin >> n;
    vector<sinhVien> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i].getGpa() >= 8.0)
        {
            cout << "cac sinh vien gioi la: " << endl;
            a[i].xuat();
        }
        else if (a[i].getGpa() >= 6.5 && a[i].getGpa() < 8.0)
        {
            cout << "cac sinh vien kha la: " << endl;
            a[i].xuat();
        }
        else
        {
            cout << "cac sinh vien trung binh la: " << endl;
            a[i].xuat();
        }
    }
    sort(a.begin(), a.end(), cmp);
    cout << "cac sinh vien co GPA giam dan la: " << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}