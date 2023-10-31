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
bool cmp(thiSinh a, thiSinh b)
{
    return a.getName() < b.getName();
}
bool cmp1(thiSinh a, thiSinh b)
{
    return a.tongDiem() > b.tongDiem();
}
bool tim(string name, string word)
{
    for (char &x : name)
        x = tolower(x);
    for (char &x : word)
        x = tolower(x);
    return name.find(word) != string::npos;
}
void xapXep(thiSinh svi[], int n)
{
    sort(svi, svi + n, cmp);
    cout << left << setw(20) << "Ma Sinh vien" << setw(30) << "Ten Sinh vien" << setw(10) << "Tong diem" << endl;
    for (int i = 0; i < n; i++)
    {
        svi[i].out();
    }
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
        tsi[i].in();
    }
    sort(tsi, tsi + n, cmp1);
    tsi[0].out();
    // sort(tsi, tsi + n, cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     tsi[i].out();
    // }
    xapXep(tsi, n);
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
// phần comment là phần dùng getter để so xắp xếp các thi sinh, còn hàm xapXep() thì dùng hàm friend