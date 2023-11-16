#include <iostream>
#include "Set.cpp"
#include "Set.h"

using namespace std;

int main() 
{
    Set A, B;
    int x;
    A = A + 1 + 2 + 3 + 4 + 5;
    cout << "Tap Hop A = " << A << endl;
	cout <<"Nhap phan tu can xoa: "; cin >> x;
    A = A - x;
	cout <<"Nhap phan tu can them: "; cin >> x;
	A = A + x;
	cout <<"A = " <<A << endl;
	B = B + 9 + 8 + 7 + 6 + 5 + 2;
	cout <<"B = " <<B<< endl;
	Set M = A + B;
	cout <<"A hop B = " << M <<endl;
	Set N = A * B;
	cout <<"A giao B = "<< N <<endl;
	Set p = A - B;
	cout <<"A - B = " << p <<endl;
	cout <<"A[2] = " << A[2] << endl;
	return 0;
}
