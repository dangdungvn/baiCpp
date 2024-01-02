#include <bits/stdc++.h>
using namespace std;
class SinhVien
{
private:
    string maSV, name;
    float diemToan, diemLy, diemHoa;

public:
    SinhVien();
    SinhVien(string maSV, string name, float diemToan, float diemLy, float diemHoa);
    void in();
    void out();
    float getDiem();
    string getName();
};
SinhVien::SinhVien()
{
    maSV = name = "";
    diemToan = diemLy = diemHoa = 0;
}
SinhVien::SinhVien(string maSV, string name, float diemToan, float diemLy, float diemHoa)
{
    this->maSV = maSV;
    this->name = name;
    this->diemToan = diemToan;
    this->diemLy = diemLy;
    this->diemHoa = diemHoa;
}
void SinhVien::in()
{
    cin.ignore();
    cout << "Nhap ma sinh vien: ";
    cin >> maSV;
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap diem toan: ";
    cin >> diemToan;
    cout << "Nhap diem ly: ";
    cin >> diemLy;
    cout << "Nhap diem hoa: ";
    cin >> diemHoa;
}
float SinhVien::getDiem()
{
    return (diemToan + diemLy + diemHoa);
}
string SinhVien::getName()
{
    return name;
}
void SinhVien::out()
{
    cout << left << setw(20) << maSV << setw(30) << name << setw(10) << getDiem() << endl;
}
void tieude()
{
    cout << left << setw(20) << "maSV" << setw(30) << "Ho Ten" << setw(10) << "Diem" << endl;
}
void nhap(SinhVien a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i].in();
    }
}
void sapXep(SinhVien a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].getDiem() < a[j].getDiem())
            {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Danh sach sinh vien sau khi sap xep: " << endl;
    tieude();
    for (int i = 0; i < n; i++)
    {
        a[i].out();
    }
}
void maxDiem(SinhVien a[], int n)
{
    SinhVien max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max.getDiem() < a[i].getDiem())
        {
            max = a[i];
        }
    }
    cout << "Sinh vien co diem cao nhat la: " << endl;
    tieude();
    max.out();
}
void timKiem(SinhVien a[], int n)
{
    string s;
    cout << "Nhap ten sinh vien can tim: ";
    cin.ignore();
    getline(cin, s);
    cout << "Danh sach sinh vien co ten " << s << " la: " << endl;
    tieude();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getName().find(s) != string::npos)
        {
            a[i].out();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    SinhVien *svi;
    svi = new SinhVien[n];
    nhap(svi, n);
    sapXep(svi, n);
    maxDiem(svi, n);
    timKiem(svi, n);
    delete[] svi;
    return 0;
}