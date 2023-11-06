#include <bits/stdc++.h>
using namespace std;
class thiSinh
{
private:
    string mts, name;
    int dt, dl, dh;

public:
    void in();
    void out();
    int tongDiem();
    string getName();
    friend void xapXep(thiSinh svi[], int n);
    friend void xapXep1(thiSinh svi[], int n);
};
void thiSinh::in()
{
    cout << "nhap ma thi sinh: ";
    cin >> mts;
    cout << "nhap ten thi sinh: ";
    cin.ignore();
    getline(cin, name);
    cout << "nhap diem thi sinh: ";
    cin >> dt >> dl >> dh;
}
int thiSinh::tongDiem()
{
    return dt + dl + dh;
}
void thiSinh::out()
{
    cout << left << setw(20) << mts << setw(30) << name << setw(10) << tongDiem() << endl;
}
string thiSinh::getName()
{
    return this->name;
}
// bool cmp(thiSinh a, thiSinh b)
// {
//     return a.getName() < b.getName();
// }

// bool cmp1(thiSinh a, thiSinh b)
// {
//     return a.tongDiem() > b.tongDiem();
// }
bool tim(string name, string word)
{
    for (char &x : name)
        x = tolower(x);
    for (char &x : word)
        x = tolower(x);
    return name.find(word) != string::npos;
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
        tsi[i].out();
    }
}
// void xapXep1(thiSinh tsi[], int n)
// {
//     sort(tsi, tsi + n, cmp);
//     for (int i = 0; i < n; i++)
//     {
//         tsi[i].out();
//     }
// }
int main()
{
    int n;
    cout << "nhap so luong sinh vien: ";
    cin >> n;
    thiSinh *tsi;
    tsi = new thiSinh[n];
    for (int i = 0; i < n; i++)
    {
        tsi[i].in();
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
    x.out();
    // sort(tsi, tsi + n, cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     tsi[i].out();
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
    //     tsi[i].out();
    // }
    xapXep(tsi, n);

    // xapXep1(tsi, n);
    string s;
    cout << "nhap ten sinh vien can tim: ";
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (tim(tsi[i].getName(), s))
        {
            tsi[i].out();
        }
    }
    delete[] tsi;
}
// từ dòng thứ 112 đến dòng thứ 124 là dùng hàm getName() để sắp xếp các phần tử của các thí sinh
// dong sapXep(tsi,n) (dòng thứ 130) để sắp xếp cac thi sinh theo cách dùng hàm friend
// muốn chạy 1 trong 2 thì phải comment cái còn lại
// các cái comment còn lại là dùng để thực hiện hàm sort (cách khác để sắp xếp các thí sinh)