/* Cài đặt 01 struct Vecto3D để biểu diễn 01 vecto trong không
gian 3 chiều (x, y, z)
Định nghĩa các phép toán +, -, * (vô hướng) 2 vecto
và phép toán >>, << để nhập, xuất vecto */
#include <iostream>
using namespace std;
struct Vecto3D {
    int x, y, z;
};
istream &operator >>(istream &in, Vecto3D &v){
    cout<<"Nhâp tọa x:"; in>>v.x;
    cout<<"Nhâp tọa y:"; in>>v.y;
    cout<<"Nhâp tọa z:"; in>>v.z;
    return in;
}
ostream &operator <<(ostream &out, const Vecto3D &v){
    out<<"("<<v.x<<","<<v.y<<","<<v.z<<")"<<endl;
    return out;
}
Vecto3D operator + (const Vecto3D &v1, const Vecto3D &v2){
    Vecto3D t;
    t.x = v1.x + v2.x;
    t.y = v1.y + v2.y;
    t.z = v1.z + v2.z;
    return t;
}
Vecto3D operator - (const Vecto3D &v1, const Vecto3D &v2){
    Vecto3D t;
    t.x = v1.x - v2.x;
    t.y = v1.y - v2.y;
    t.z = v1.z - v2.z;
    return t;
}
int operator * (const Vecto3D &v1, const Vecto3D &v2){
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
int main(){
    Vecto3D a, b, c, d;
    cout<<"Nhập vecto a:"<<endl; cin >> a;
    cout<<"Nhập vecto b:"<<endl; cin >> b;
    cout<<"Vecto a vừa nhập: "; cout<<a;
    cout<<"Vecto b vừa nhập: "; cout<<b;
    c = a + b;
    cout<<"Vecto c = a + b = "<<c;
    d = a - b;
    cout<<"Vecto d = a - b = "<<d;
    cout<<"Tích vô hướng a * b = "<<a *b<<endl;
}