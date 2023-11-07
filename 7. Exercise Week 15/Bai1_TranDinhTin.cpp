#include <iostream>
#include "matrix.cpp"
#include "matrix.h"
using namespace std;

int main() 
{
    matrix m1, m2;
    cout << "Matrix m1: "<< endl;
    cin >> m1;
    cout << "Matrix m2: "<< endl;
    cin >> m2;
    cout << "m1: " << endl;
    cout << m1;
    cout << "m2: " << endl;
    cout << m2;
    matrix m3 = (m1+m2);
    cout << "m3 = m1 + m2: " << endl;
    cout << m3;
    m3 = m1*m2;
    cout << "m3 = m1*m2: " << endl;
    cout << m3;
    cout << "m1(1, 1) = ";
    cout << m1(1, 1) << endl;
    m1 = m2;
    cout << "m1 after change: " << endl;
    cout << m1;
    return 0;
}