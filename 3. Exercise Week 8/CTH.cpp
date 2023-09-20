#include <iostream>
using namespace std;
void nhap(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan thu thu " << i << ": ";
        cin >> *(arr + i);
    }
}
void xuat(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
}
void lpt(int *arr, int n)
{
    cout << "\nNhap vi tri muon tim: ";
    cin >> n;
    cout << "Gia tri phan tu thu " << n << ": " << arr[n];
}
// SSSX tăng dần
bool td(int t, int s)
{
    return t > s;
}
// SSSX giảm dần
bool gd(int t, int s)
{
    return t < s;
}
// Hoán vị
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// Chọn trực tiếp
void chon(int arr[], int n, bool (*p)(int, int) = td)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*td)(arr[k], arr[j]))
            {
                k = j;
            }
        }
        Swap(arr[i], arr[k]);
    }
}
// Gọi hàm SX
void sort(void (*fpt)(int *, int, bool (*fp)(int, int)), int arr[], int n, bool (*p)(int, int) = td)
{
    (*fpt)(arr, n, p);
}
// Chèn trực tiếp
void chen(int arr[], int n, bool (*p)(int, int) = td)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        while (j >= 0 && (*p)(arr[j], arr[i]))
        {
            arr[j + 1] = arr[j];
            arr[j] = arr[i];
        }
    }
}
// BubbleSort
void bbs(int arr[], int n, bool (*p)(int, int) = td)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if ((*p)(arr[j], arr[j + 1]))
                Swap(arr[j], arr[j + 1]);
        }
    }
}
// QuickSort
int chia(int arr[], int d, int c, bool (*p)(int, int))
{
    int k = arr[c];
    int i = d - 1;

    for (int j = d; j <= c - 1; j++)
    {
        if (!(*p)(arr[j], k))
        {
            i++;
            Swap(arr[i], arr[j]);
        }
    }
    Swap(arr[i + 1], arr[c]);
    return (i + 1);
}
void qs(int arr[], int d, int c, bool (*p)(int, int) = td)
{
    if (d < c)
    {
        int h = chia(arr, d, c, p);

        qs(arr, d, h - 1, p);
        qs(arr, h + 1, c, p);
    }
}
// SD hàm QuickSort
void qsu(int arr[], int n, bool (*p)(int, int) = td)
{
    qs(arr, 0, n - 1, p);
}
// HeapSort
void hf(int arr[], int n, int i)
{
    int max = i;
    int t = 2 * i + 1;
    int p = 2 * i + 2;
    if (t < n && arr[t] > arr[max])
        max = t;
    if (p < n && arr[p] > arr[max])
        max = p;
    if (p < n && arr[p] > arr[max])
        max = p;
    if (max != i)
    {
        Swap(arr[i], arr[max]);
        hf(arr, n, max);
    }
}
void hs(int arr[], int n, bool (*p)(int, int) = td)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        hf(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        Swap(arr[0], arr[i]);
        hf(arr, i, 0);
    }
}
// ShellSort
void shs(int arr[], int n, bool (*p)(int, int) = td)
{
    int kc = n / 2;
    while (kc > 0)
    {
        for (int i = kc; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= kc && arr[j - kc] > temp)
            {
                arr[j] = arr[j - kc];
                j -= kc;
            }
            arr[j] = temp;
        }
        kc /= 2;
    }
}
// RadixSort
int countDigits(int n)
{
    int dem = 0;
    while (n > 0)
    {
        dem++;
        n /= 10;
    }
    return dem;
}
int digitAt(int n, int k)
{
    int d = 0;
    for (int i = 0; i < k; i++)
    {
        d = n % 10;
        n /= 10;
    }
    return d;
}
void rs(int arr[], int n, bool (*p)(int, int) = td)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int d = countDigits(arr[i]);
        if (d > max)
        {
            max = d;
        }
    }
    for (int k = 1; k <= max; k++)
    {
        int temp[n];
        int index = 0;
        for (int d = 0; d <= 9; d++)
        {
            for (int i = 0; i < n; i++)
            {
                if (digitAt(arr[i], k) == d)
                {
                    temp[index] = arr[i];
                    index++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
    }
}

// TK tuần tự
int tt(int arr[], int n, int x, bool (*p)(int, int) = td)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// TK nhị phân
int np(int a[], int n, int x, bool (*p)(int, int) = td)
{
    int d = 0;
    int c = n - 1;
    int g;
    do
    {
        g = (d + c) / 2;
        if (x == *(a + g))
            return g;
        else if (!p(x, *(a + g)))
            c = g - 1;
        else
            d = g + 1;
    } while (d <= c);
    return -1;
}

// TK nội suy
int ns(int arr[], int n, int x, bool (*p)(int, int) = td)
{
    int l = 0;
    int r = n - 1;
    while (l <= r && x >= arr[l] && x <= arr[r])
    {
        if (l == r)
        {
            if (arr[l] == x)
                return l;
            return -1;
        }
        int g = l + (r - l) * (x - arr[l]) / (arr[r] - arr[l]);
        if (arr[g] == x)
            return g;
        if (arr[g] > x)
            r = g - 1;
        if (arr[g] < x)
            l = g + 1;
    }
    return -1;
}
int main()
{
    int *a, n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    a = new int[n];
    nhap(a, n);
    cout << "Mang vua nhap: ";
    xuat(a, n);

    lpt(a, n);
    cout << "\nSap xep kieu chon truc tiep:  ";
    sort(chon, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu chen truc tiep:  ";
    sort(chen, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu BubbleSort:  ";
    sort(bbs, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu QuickSort:  ";
    sort(qsu, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu HeapSort:  ";
    sort(hs, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu ShellSort:  ";
    sort(shs, a, n);
    xuat(a, n);
    cout << "\nSap xep kieu RadixSort:  ";
    sort(rs, a, n);
    xuat(a, n);

    cout << "\nNhap phan tu muon tim: ";
    cin >> x;
    cout << "Tim kiem tuan tu: ";
    cout << tt(a, n, x, td);
    cout << "\nTim kiem nhi phan: ";
    cout << np(a, n, x, td);
    cout << "\nTim kiem noi suy: ";
    cout << ns(a, n, x, td);
    return 0;
}
