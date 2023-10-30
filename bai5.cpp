#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class nguoi
{
protected:
    string name;
    string date;

public:
    nguoi();
    void in();
    void out();
};
class Sv : public nguoi
{
private:
    string maSV;
    double gpa;

public:
    Sv();
    void in();
    void out();
};
nguoi::nguoi()
{
    name = "";
    date = "";
}
void nguoi::in()
{
    cin.ignore();
    getline(cin, name);
    cin >> date;
}
void nguoi::out()
{
    cout << name << " " << date << " ";
}
Sv::Sv()
{
    maSV = "";
    gpa = 0;
}
void Sv::in()
{
    nguoi::in();
    cin >> maSV;
    cin >> gpa;
}
void Sv::out()
{
    nguoi::out();
    cout << maSV << " " << gpa << endl;
}
int main()
{
    int n;
    cin >> n;
    Sv a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].in();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].out();
    }
}