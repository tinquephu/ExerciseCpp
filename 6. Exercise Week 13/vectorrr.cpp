#include <iostream>
#include <cmath>

using namespace std;

class Vecto {
private:
    int n;
    double* arr;
public:
    Vecto() {
        n = 0;
        arr = NULL;
    }

    Vecto(int n) {
        this->n = n;
        arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }

    Vecto(const Vecto& v) {
        n = v.n;
        arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = v.arr[i];
        }
    }

    ~Vecto() {
        delete[] arr;
    }

    void nhap() {
        cout << "Nhap so chieu cua vecto: ";
        cin >> n;
        arr = new double[n];
        cout << "Nhap toa do cua vecto: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void xuat() {
        cout << "(";
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i < n - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    Vecto operator+(const Vecto& v) {
        if (n != v.n) {
            cout << "Khong the cong hai vecto khac chieu!" << endl;
            return *this;
        }
        Vecto res(n);
        for (int i = 0; i < n; i++) {
            res.arr[i] = arr[i] + v.arr[i];
        }
        return res;
    }

    Vecto operator-(const Vecto& v) {
        if (n != v.n) {
            cout << "Khong the tru hai vecto khac chieu!" << endl;
            return *this;
        }
        Vecto res(n);
        for (int i = 0; i < n; i++) {
            res.arr[i] = arr[i] - v.arr[i];
        }
        return res;
    }

    double operator*(const Vecto& v) {
        if (n != v.n) {
            cout << "Khong the tinh tich vo huong hai vecto khac chieu!" << endl;
            return 0;
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += arr[i] * v.arr[i];
        }
        return res;
    }
};

int main() {
    Vecto v1, v2;
    cout << "Nhap vecto thu nhat: " << endl;
    v1.nhap();
    cout << "Nhap vecto thu hai: " << endl;
    v2.nhap();
    cout << "Vecto thu nhat: ";
    v1.xuat();
    cout << "Vecto thu hai: ";
    v2.xuat();
    cout << "Tong hai vecto: ";
    (v1 + v2).xuat();
    cout << "Hieu hai vecto: ";
    (v1 - v2).xuat();
    cout << "Tich vo huong hai vecto: " << (v1 * v2) << endl;
    return 0;
}
