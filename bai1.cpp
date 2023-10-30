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
bool cmp(SinhVien a, SinhVien b);
bool cmp1(SinhVien a, SinhVien b);
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
    return (this->diemToan + this->diemLy + this->diemHoa);
}
string SinhVien::getName()
{
    return this->name;
}
bool cmp(SinhVien a, SinhVien b)
{
    return a.getDiem() > b.getDiem();
}
bool cmp1(SinhVien a, SinhVien b)
{
    return a.getName() < b.getName();
}
void SinhVien::out()
{
    cout << left << setw(20) << maSV << setw(30) << name << setw(10) << getDiem() << endl;
}
int main()
{
    int n;
    cin >> n;
    SinhVien *svi;
    svi = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        svi[i].in();
    }
    cout << "Sinh vien co diem cao nhat:" << endl;
    sort(svi, svi + n, cmp);
    svi[0].out();
    cout << "Danh sach cac sinh vien theo ten:" << endl;
    sort(svi, svi + n, cmp1);
    cout << left << setw(20) << "Ma Sinh vien" << setw(30) << "Ten Sinh vien" << setw(10) << "GPA" << endl;
    for (int i = 0; i < n; i++)
    {
        svi[i].out();
    }
    string s;
    cout << "nhap ten sinh vien can tim: ";
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (svi[i].getName().find(s) != string::npos)
        {
            svi[i].out();
        }
    }
    return 0;
}