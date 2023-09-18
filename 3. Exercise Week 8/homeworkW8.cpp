#include <iostream>
using namespace std;
const int MAX = 10;

void nhap_Array(int* arr, int& n)
{
    cout << "Nhap so luong mang: "; cin >> n;
    for (int i = 0;i < n;i++)
    {
        cout << "arr[" << i + 1 << "]= ";
        cin >> arr[i];
    }
}

void xuat_Array(int* arr, int& n)
{
    cout << "Mang vua nhap la: ";
    for (int i = 0;i < n;i ++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// int size_of_Array(int* arr)
// {
    
// }

void lay_phan_tu_tai_vitri(int* arr, int& n)
{
    int findIndex;
    cout << "Nhap vi tri can lay: "; cin >> findIndex;
    cout << arr[findIndex - 1];
}

int main()
{
    int n;
    int *arr = new int[MAX];
    nhap_Array(arr, n);
    xuat_Array(arr, n);
    lay_phan_tu_tai_vitri(arr, n);
    delete[] arr;
}