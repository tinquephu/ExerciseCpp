#include <iostream>
#include <string>
using namespace std;
const int MAX = 10;

struct sinhVien {
    string hoten;
    float toan, ly, hoa;
    float dtb;
    sinhVien() {
        dtb = (toan + ly + hoa) / 3;
    }
};

istream &operator >>(istream& in, sinhVien &s)
{
    cout << "Ho va ten: "; cin.ignore(); getline(in, s.hoten);
    cout << "Diem toan: "; in >> s.toan;
    cout << "Diem ly: "; in >> s.ly;
    cout << "Diem hoa: "; in >> s.hoa;
    s.dtb = (s.toan + s.ly + s.hoa) / 3;
    return in;
}

ostream &operator <<(ostream& out,const sinhVien &s)
{
    cout << "Ho va ten: "; out << s.hoten << endl;
    cout << "Diem toan: "; out << s.toan << endl;
    cout << "Diem ly: "; out << s.ly << endl;
    cout << "Diem hoa: "; out << s.hoa << endl;
    cout << "Diem trung binh: "; out << s.dtb << endl;
    return out;
}

bool operator <(const sinhVien& s1, const sinhVien& s2)
{
    return s1.dtb < s2.dtb;
}

bool operator >(const sinhVien& s1, const sinhVien& s2)
{
    return s1.dtb > s1.dtb;
}

void sortStudents(sinhVien* students, int n, bool (*compare)(const sinhVien&, const sinhVien&)) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(students[j], students[j + 1]))
            {
                // Hoán đổi vị trí của hai sinh viên
                sinhVien temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

bool ascendingCompare(const sinhVien& s1, const sinhVien& s2) {
    return s1.dtb < s2.dtb;
}

bool descendingCompare(const sinhVien& s1, const sinhVien& s2) {
    return s1.dtb > s2.dtb;
}

int main()
{
    sinhVien *s = new sinhVien[MAX];
    int n;
    cout << "Nhap so luong sinh vien: "; cin >> n;
    for (int i = 0;i < n;i++)
    {
        cout << "Nhap thong tin sinh vien " << i+1 << ": " << endl;
        cin >> s[i];
    }
    cout << endl;
    
    int choice;
    cout << "Chon cach sap xep (1: Tang dan, 2: Giam dan): "; cin >> choice;

     if (choice == 1) {
        sortStudents(s, n, ascendingCompare); // Sắp xếp tăng dần
    } else if (choice == 2) {
        sortStudents(s, n, descendingCompare); // Sắp xếp giảm dần
    } else {
        cout << "Lua chon khong hop le." << endl;
    }

    cout << endl;
    if (choice == 1)
    {
        cout << "Danh sach sinh vien theo Tang dan diem trung binh" << endl;
    } else {
        cout << "Danh sach sinh vien theo Giam dan diem trung binh";
    }
    for (int i = 0; i < n;i++)
    {
        cout << "Sinh vien " << i+1<< endl;
        cout << s[i];
        cout << endl;
    }
    delete [] s;
}