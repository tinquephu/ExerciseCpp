#include <iostream>
#include "Dathuc.h"
using namespace std;

dathuc::dathuc(int m):n(m), heso(new int[n+1]) {}

dathuc::~dathuc()
{
    delete[] heso;
};

dathuc::dathuc(const dathuc &p):n(p.n)
{
    for (int i = 0;i <= n;i++) {
        heso[i] = p[i];
    }
}
istream &operator >> (istream &in, dathuc&p)
{
    cout << "Nhap cac he so: " << endl;
    for (int i = 0;i <= p.n;i++){
        cout << "a_" << i << ": ";
        in >> p[i];
    }
    return in;
}
ostream &operator << (ostream &out, const dathuc &p)
{
    int count = 0;
    for (int i = p.n;i >= 0;i--) {
        if (p[i] != 0) {
            if (i == 0){
                out << p[0];
            } else if (p[i] == 1) {
                out << "x^" << p.n - count;
            } else {
                out << p[i] << "x^" << p.n - count;
            }
            bool flag = false;
            for (int j = i - 1;j >= 0;j--) {
                if (p[j] != 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) out << " + ";
        }
        count++;
    }
    cout << endl;
    return out;
}

dathuc dathuc::operator +(const dathuc&p)
{
    int s;
    (n > p.n) ? s = n : s = p.n;
    dathuc t(s);
    int count = -1;
    while (count < n && count < p.n) {
        ++count;
        t[count] = heso[count] + p[count];
    }
    if (count < n) {
        while (count < s) {
            ++count;
            t[count] = heso[count];
        }
    }
    if (count < p.n) {
        while (count < s) {
            ++count;
            t[count] = p[count];
        }
    }
    return t;
}

dathuc dathuc::operator- (const dathuc &p)
{
    int s;
    (n > p.n) ? s = n : s = p.n;
    dathuc t(s);

    int count = -1;
    while (count < n && count < p.n) {
        count++;
        t[count] = heso[count] - p[count];
    }
    if (count < n) {
        while (count < n) {
            count++;
            t[count] = -heso[count];
        }
    }
    if (count < p.n) {
        while (count < p.n) {
            count++;
            t[count] = -p[count];
        }
    }
    return t;
}

dathuc &dathuc::operator = (const dathuc &p) 
{
    if (this != &p) {
        this -> n = p.n;
        delete[] heso;
        heso = new int[n + 1];
        for (int i = 0;i <= n;i++) {
            heso[i] = p[i];
        }
    }
    return *this;
}

int dathuc::operator ()(int x)
{
    int s = 0;
    for (int i = 0;i <= n;i++) {
        s += heso[i]*pow(x, n - i);
    }
    return s;
}