#include <bits/stdc++.h>
using namespace std;
class thiSinh
{
private:
    string mts, name;
    double dt, dl, dh;

public:
    void nhap();
    void xuat();
    double tongDiem();
    string getName();
    string getMts()
    {
        return this->mts;
    }
    friend void xapXep(thiSinh svi[], int n);
    friend void xapXep1(thiSinh svi[], int n);
};
void thiSinh::nhap()
{
    cout << "nhap ma thi sinh: ";
    cin >> mts;
    cout << "nhap ten thi sinh: ";
    cin.ignore();
    getline(cin, name);
    cout << "nhap diem thi sinh: ";
    cin >> dt >> dl >> dh;
}
double thiSinh::tongDiem()
{
    return dt + dl + dh;
}
void thiSinh::xuat()
{
    cout << left << setw(20) << mts << setw(30) << name << setw(10) << tongDiem() << endl;
}
string thiSinh::getName()
{
    return this->name;
}

void xapXep(thiSinh tsi[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tsi[i].name > tsi[j].name)
            {
                thiSinh t;
                t = tsi[i];
                tsi[i] = tsi[j];
                tsi[j] = t;
            }
        }
    }
    cout << left << setw(20) << "Ma Sinh vien" << setw(30) << "Ten Sinh vien" << setw(10) << "Tong diem" << endl;
    for (int i = 0; i < n; i++)
    {
        tsi[i].xuat();
    }
}
// bool cmp(thiSinh a, thiSinh b)
// {
//     return a.getName() < b.getName();
// }

// bool cmp1(thiSinh a, thiSinh b)
// {
//     return a.tongDiem() > b.tongDiem();
// }

// void xapXep1(thiSinh tsi[], int n)
// {
//     sort(tsi, tsi + n, cmp);
//     for (int i = 0; i < n; i++)
//     {
//         tsi[i].xuat();
//     }
// }
void tieuDe()
{
    cout << left << setw(20) << "Ma Sinh vien" << setw(30) << "Ten Sinh vien" << setw(10) << "Tong diem" << endl;
}
int main()
{
    int n;
    cout << "nhap so luong sinh vien: ";
    cin >> n;
    thiSinh *tsi;
    tsi = new thiSinh[n];
    for (int i = 0; i < n; i++)
    {
        tsi[i].nhap();
    }
    thiSinh x = tsi[0];
    for (int i = 0; i < n; i++)
    {
        if (tsi[i].tongDiem() > x.tongDiem())
        {
            x = tsi[i];
        }
    }
    cout << "thi sinh co tong diem lon nhat la: ";
    x.xuat();

    // sort(tsi, tsi + n, cmp);

    // for (int i = 0; i < n; i++)
    // {
    //     tsi[i].xuat();
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (tsi[i].getName() > tsi[j].getName())
    //         {
    //             thiSinh t;
    //             t = tsi[i];
    //             tsi[i] = tsi[j];
    //             tsi[j] = t;
    //         }
    //     }
    // }

    // cout << left << setw(20) << "Ma Sinh vien" << setw(30) << "Ten Sinh vien" << setw(10) << "Tong diem" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     tsi[i].xuat();
    // }

    xapXep(tsi, n);

    // xapXep1(tsi, n);
    string s;
    cout << "nhap ten sinh vien can tim: ";
    cin >> s;
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (tsi[i].getName().find(s) != string::npos)
        {
            cout << "danh sach sinh vien co ten " << s << ":" << endl;
            tieuDe();
            tsi[i].xuat();
            dem++;
        }
        else if (tsi[i].getMts().find(s) != string::npos)
        {

            cout << "thong tin sinh vien co ma " << s << ": " << endl;
            tieuDe();
            tsi[i].xuat();
            dem++;
        }
    }
    if (dem == 0)
    {
        cout << "khong tim thay sinh vien nao co ten " << s << endl;
    }
    delete[] tsi;
}
// trong hàm sapXep(): ta cho i chạy từ phần tử 0 đến phần tử n-2, j chạy từ phần tử 1 đến phần n-1, khi mà phần tử thứ i lớn hơn phần tử thứ j
// thì chúng ta sẽ swap 2 phần tử đó với nhau để luôn bảo đảm phần tử đứng trước nhỏ hơn phần tử phía sau, sau khi swap thì ta lại chạy lại vòng for