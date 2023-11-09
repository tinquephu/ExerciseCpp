#include <iostream>
#include "Dathuc.h"
#include "Dathuc.cpp"
using namespace std;

int main()
{
    dathuc n(3);
    dathuc m(2);
    cin >> n; cin >> m;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;
    cout << "m + n = " << m + n << endl;
    cout << "m - n = " << m - n << endl;
    int i;
    cout << "Nhap he so can biet cua m: "; cin >> i;
    cout << "He so cua a" << i << " cua m la: " << m[i] << endl;
    int x;
    cout << "Nhap x: "; cin >> x;
    cout << "Gia tri cua m tai x = " << x << " la: " << m(x) << endl;
    dathuc p;
    p = m;
    cout << "p = " << p << endl;
    return 0;
}