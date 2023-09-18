#include <iostream>
using namespace std;

struct Vector3D {
    int x, y, z;
} ;

istream &operator >>(istream& in, Vector3D& a)
{
    cout << "Write x: "; in >> a.x;
    cout << "Write y: "; in >> a.y;
    cout << "Write z: "; in >> a.z;
    return in;
} 

ostream &operator <<(ostream& out, const Vector3D& a)
{
    out << a.x << endl;
    out << a.y << endl;
    out << a.z << endl;
    return out;
} 

Vector3D operator +(const Vector3D&a, const Vector3D&b)
{
    Vector3D t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;
    t.z = a.z + b.z;
    return t; 
}

int main()
{
    Vector3D a,b,c;
    cout << "Write a: " << endl; cin >> a;
    cout << "Write b: " << endl; cin >> b;
    c = a + b;
    cout << c;
    return 0;
}