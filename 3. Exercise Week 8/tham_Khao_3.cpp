#include <iostream>

using namespace std;

// Hàm trợ giúp: In mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort
void selectionSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; ++i) {
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            if ((ascending && arr[j] < arr[index]) || (!ascending && arr[j] > arr[index])) {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, bool ascending) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while ((ascending && j >= 0 && arr[j] > key) || (!ascending && j >= 0 && arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n, bool ascending) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Quick Sort
int partition(int arr[], int low, int high, bool ascending) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, bool ascending) {
    if (low < high) {
        int pi = partition(arr, low, high, ascending);
        quickSort(arr, low, pi - 1, ascending);
        quickSort(arr, pi + 1, high, ascending);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i, bool ascending) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((ascending && arr[left] > arr[largest]) || (!ascending && arr[left] < arr[largest])))
        largest = left;

    if (right < n && ((ascending && arr[right] > arr[largest]) || (!ascending && arr[right] < arr[largest])))
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, ascending);
    }
}

void heapSort(int arr[], int n, bool ascending) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}

// Shell Sort
void shellSort(int arr[], int n, bool ascending) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; (ascending && j >= gap && arr[j - gap] > temp) || (!ascending && j >= gap && arr[j - gap] < temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int exp, bool ascending) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, bool ascending) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp, ascending);
}

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right && key >= arr[left] && key <= arr[right]) {
        if (left == right) {
            if (arr[left] == key) return left;
            return -1;
        }
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (key - arr[left]));
        if (arr[pos] == key) return pos;
        if (arr[pos] < key) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    int choice;
    cout << "Chon cach sap xep (1: Tang dan, 2: Giam dan): ";
    cin >> choice;

    bool ascending = true;
    if (choice == 2) {
        ascending = false;
    }

    cout << "Mang truoc khi sap xep: ";
    printArray(arr, n);

    int sortMethod;
    cout << "Chon phuong phap sap xep (1: Selection, 2: Insertion, 3: Bubble, 4: Quick, 5: Heap, 6: Shell, 7: Radix): ";
    cin >> sortMethod;

    switch (sortMethod) {
        case 1:
            selectionSort(arr, n, ascending);
            break;
        case 2:
            insertionSort(arr, n, ascending);
            break;
        case 3:
            bubbleSort(arr, n, ascending);
            break;
        case 4:
            quickSort(arr, 0, n - 1, ascending);
            break;
        case 5:
            heapSort(arr, n, ascending);
            break;
        case 6:
            shellSort(arr, n, ascending);
            break;
        case 7:
            radixSort(arr, n, ascending);
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            return 1;
    }

    cout << "Mang da sap xep: ";
    printArray(arr, n);

    int searchMethod;
    cout << "Chon phuong phap tim kiem (1: Tuần tự, 2: Nhị phân, 3: Nội suy): ";
    cin >> searchMethod;

    int key;
    cout << "Nhap gia tri can tim: ";
    cin >> key;

    int index;
    switch (searchMethod) {
        case 1:
            index = linearSearch(arr, n, key);
            break;
        case 2:
            index = binarySearch(arr, n, key);
            break;
        case 3:
            index = interpolationSearch(arr, n, key);
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            return 1;
    }

    if (index != -1) {
        cout << "Phan tu " << key << " duoc tim thay tai vi tri " << index << endl;
    } else {
        cout << "Phan tu " << key << " khong tim thay trong mang." << endl;
    }

    return 0;
}
