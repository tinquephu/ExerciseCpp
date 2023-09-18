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
    cout << arr[findIndex - 1] << endl;
}

void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selectionSort(int *arr)

int main()
{
    int n;
    int *arr = new int[MAX];
    nhap_Array(arr, n);
    xuat_Array(arr, n);
    lay_phan_tu_tai_vitri(arr, n);
    cout << "Choose method to arrange array:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. BubbleSort" << endl;
    cout << "4. QuickSort" << endl;
    cout << "5. HeapSort" << endl;
    cout << "6. ShellSort" << endl;
    cout << "7. RadixSort" << endl;
    int choice ;
    cout << "Enter your choice (1-7): "; cin >> choice;

    switch (choice) {
        case 1:

    }

    delete[] arr;
}