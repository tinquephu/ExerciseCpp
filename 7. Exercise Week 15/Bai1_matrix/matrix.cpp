#include <iostream>
#include "matrix.h"
using namespace std;

matrix::matrix(int m):n(m), data (new int *[n]){
    for (int i = 0;i < n;i++)
    {
        data[i] = new int [n];
    }
}
matrix::matrix(const matrix &m):n(m.n), data(new int*[n])
{
    for (int i=0;i<n;i++){
        data[i] = new int [n];
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            data[i][j] = m(i,j);
        }
    }
}
matrix::~matrix() {
    for (int i = 0;i<n;i++){
        delete data[i];
    }
    delete[] data;
}

istream &operator >>(istream &in, matrix &m)
{
    for (int i = 0;i < m.n;i++){
        for (int j = 0;j < m.n;j++){
            cout << "["<< i << "]" << "[" << j << "]= ";
            in >> m.data[i][j];
        }
    }
    return in;
}
ostream &operator <<(ostream &out, const matrix &m)
{
    for (int i = 0;i < m.n;i++) {
        for (int j = 0;j < m.n;j++) {
            out << m(i, j) << " ";
        }
        out << endl;
    }
    return out;
}

matrix matrix::operator +(const matrix &m) {
    if (n == m.n) {
        matrix t(n);
        t.n = n;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++){
                t.data[i][j] = data[i][j] + m(i, j);
            }
        }
        return t;
    }
    return *this;
}
matrix matrix::operator -(const matrix &m) {
    if (n == m.n) {
        matrix t(n);
        t.n = n;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++){
                t.data[i][j] = data[i][j] - m(i, j);
            }
        }
        return t;
    }
    return *this;
}
matrix matrix::operator *(const matrix &m) {
    if (n == m.n) {
        matrix t(n);
        t.n = n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                t.data[i][j] = 0;
                for (int k = 0;k < n;k++) {
                    t.data[i][j] += data[i][k]*m(k, j);
                }
            }
        }
        return t;
    }
    return *this;
}

const matrix &matrix::operator = (const matrix &m) {
    if (this != &m) {
        for (int i = 0;i < n;i++){
            delete[] data[i];
        }
        n = m.n;
        for (int i = 0;i < n;i++) {
            data[i] = new int[n];
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                data[i][j] = m(i,j);
            }
        }
    }
    return *this;
}