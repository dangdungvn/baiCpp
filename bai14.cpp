#include <bits/stdc++.h>
using namespace std;
class nguoi
{
protected:
    string hoten, namsinh;

public:
    void nhap();
    void xuat();
};
class giangvien : public nguoi
{
private:
    string monCT, monGD;

public:
    void nhap();
    void xuat();
    friend void bomon(giangvien a[], int n);
};
void nguoi::nhap()
{
    cout << "nhap ho ten: ";
    getline(cin, hoten);
    cout << "nhap nam sinh: ";
    getline(cin, namsinh);
}
void nguoi::xuat()
{
    cout << left << setw(20) << hoten << setw(7) << namsinh;
}
void giangvien::nhap()
{
    nguoi::nhap();
    cout << "nhap mon cong tac: ";
    getline(cin, monCT);
    cout << "nhap mon giang day: ";
    getline(cin, monGD);
}
void giangvien::xuat()
{
    nguoi::xuat();
    cout << setw(20) << monCT << setw(20) << monGD << endl;
}
void tieude()
{
    cout << left << setw(20) << "ho ten" << setw(7) << "NS" << setw(20) << "Mon cong tac" << setw(20) << "Mon giang day" << endl;
}
void bomon(giangvien a[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].monCT > a[j].monCT)
            {
                giangvien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    tieude();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}
int main()
{
    int n;
    cout << "nhap so luong giang vien: ";
    cin >> n;
    cin.ignore();
    giangvien a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "nhap thong tin giang vien thu " << i + 1 << ": " << endl;
        a[i].nhap();
    }
    bomon(a, n);
}
/*từ dòng */