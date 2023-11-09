// Cài đặt lớp Matrix để biểu diễn 01 ma trận vuông cấp n các số nguyên gồm n là cấp của ma trân 
// và 01 mảng động 2 chiều chưa các phần tử của ma trận;
// và các hàm: hàm dựng, hàm dựng sao chép, hàm hủy, các phép toán +, -, * 2 ma trận;
// các phép toán >>, << để nhập, xuất ma trận; toán tử = gán 2 ma trận;
// toán tử ( ) để truy xuất phần tử của ma trận. 
#ifndef Matrix_h
#define Matrix_h
#include <iostream>
using namespace std;
class matrix {
    int n;
    int **data; //Array 2 dim use **
    public:
        matrix(int = 2);
        ~matrix();
        matrix(const matrix &m);
        friend istream &operator >>(istream &in, matrix &m);
        friend ostream &operator <<(ostream &out,const matrix &m);
        int &operator ()(int i, int j) const {return data[i][j];};
        matrix operator +(const matrix &m);
        matrix operator -(const matrix &m);
        matrix operator *(const matrix &m);
        const matrix &operator =(const matrix &m);
};
#endif