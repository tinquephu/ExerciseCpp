//Cài đặt lớp Dathuc để biểu diễn 01 đa thức gồm bậc n và 01 mảng động chứa hệ số của đa thức; 
//các hàm dựng, hàm dựng sao chép, hàm hủy; hàm toán tử +, - 2 đa thức; 
//hàm toán tử [ ] để truy xuất 01 hệ số của đa thức; toán tử ( ) để tinh giá trị của đa thức; 
//toán tử = để gán 2 đa thức; toán tử >>, << để nhập, xuất 2 đa thức.
#ifndef Dathuc_h
#define Dathuc_h
#include <iostream>
#include <cmath>
using namespace std;
class dathuc 
{
    int n;
    int *heso;
    public:
        dathuc(int = 1);
        ~dathuc();
        dathuc(const dathuc &p);
        dathuc operator +(const dathuc &p);
        dathuc operator -(const dathuc &p);
        dathuc &operator =(const dathuc &p);
        int &operator [](int i) const {return heso[i];};
        friend istream &operator >> (istream &in, dathuc &p);
        friend ostream &operator << (ostream &out, const dathuc &p);
        int operator ()(int x);
};
#endif
