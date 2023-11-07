#include <iostream>

using namespace std;

// Định nghĩa struct Node để biểu diễn mỗi phần tử trong danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Định nghĩa struct SET để biểu diễn tập hợp
struct SET {
    Node* head;

    // Khởi tạo một tập hợp rỗng
    SET() {
        head = nullptr;
    }

    // Thêm một phần tử vào tập hợp
    void them(int giaTri) {
        Node* newNode = new Node();
        newNode->data = giaTri;
        newNode->next = head;
        head = newNode;
    }

    // Xóa một phần tử khỏi tập hợp
    void xoa(int giaTri) {
        Node* hienTai = head;
        Node* truoc = nullptr;

        while (hienTai != nullptr) {
            if (hienTai->data == giaTri) {
                if (truoc == nullptr) {
                    head = hienTai->next;
                } else {
                    truoc->next = hienTai->next;
                }
                delete hienTai;
                return;
            }
            truoc = hienTai;
            hienTai = hienTai->next;
        }
    }

    // Kiểm tra xem một phần tử có thuộc tập hợp hay không
    bool chua(int giaTri) {
        Node* hienTai = head;
        while (hienTai != nullptr) {
            if (hienTai->data == giaTri) {
                return true;
            }
            hienTai = hienTai->next;
        }
        return false;
    }

    // Truy cập một phần tử tại vị trí i trong tập hợp
    int operator[](int i) {
        Node* hienTai = head;
        int dem = 0;
        while (hienTai != nullptr) {
            if (dem == i) {
                return hienTai->data;
            }
            dem++;
            hienTai = hienTai->next;
        }
        throw out_of_range("Vị trí ngoài phạm vi");
    }

    // Phép gán
    SET& operator=(const SET& khac) {
        if (this == &khac) {
            return *this;
        }

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* hienTai = khac.head;
        while (hienTai != nullptr) {
            them(hienTai->data);
            hienTai = hienTai->next;
        }

        return *this;
    }
};

// Nạp chồng phép << để in nội dung của tập hợp
ostream& operator<<(ostream& os, const SET& tapHop) {
    Node* hienTai = tapHop.head;
    while (hienTai != nullptr) {
        os << hienTai->data << " ";
        hienTai = hienTai->next;
    }
    return os;
}

int main() {
    SET tapHop1;
    tapHop1.them(1);
    tapHop1.them(2);
    tapHop1.them(3);

    SET tapHop2;
    tapHop2.them(2);
    tapHop2.them(3);
    tapHop2.them(4);

    cout << "Tập hợp 1: " << tapHop1 << endl;

    tapHop1.them(5);
    cout << "Tập hợp 1 sau khi thêm 5: " << tapHop1 << endl;

    int viTri;
    cout << "Nhập vị trí cần kiểm tra trong tập hợp 1: ";
    cin >> viTri;
    bool coChua = tapHop1.chua(viTri);
    cout << "Tập hợp 1 có chứa " << viTri << ": " << coChua << endl;

    cout << "Nhập vị trí cần xóa khỏi tập hợp 1: ";
    cin >> viTri;
    tapHop1.xoa(viTri);
    cout << "Tập hợp 1 sau khi xóa " << viTri << ": " << tapHop1 << endl;

    cout << "Nhập vị trí cần truy cập trong tập hợp 1: ";
    cin >> viTri;
    try {
        int phanTu = tapHop1[viTri];
        cout << "Phần tử tại vị trí " << viTri << " trong tập hợp 1: " << phanTu << endl;
    } catch (out_of_range& e) {
        cout << "Lỗi: " << e.what() << endl;
    }

    SET tapHopHop, tapHopHieu, tapHopGiao;

    for (int i = 0; i < 3; i++) {
        tapHopHop.them(tapHop1[i]);
        tapHopHieu.them(tapHop1[i]);
        tapHopGiao.them(tapHop1[i]);
    }

    for (int i = 0; i < 3; i++) {
        tapHopHop.them(tapHop2[i]);
        tapHopHieu.xoa(tapHop2[i]);
        if (!tapHop2.chua(tapHop1[i])) {
            tapHopGiao.xoa(tapHop1[i]);
        }
    }

    cout << "Hợp của tập hợp 1 và tập hợp 2: " << tapHopHop << endl;
    cout << "Hiệu của tập hợp 1 và tập hợp 2: " << tapHopHieu << endl;
    cout << "Giao của tập hợp 1 và tập hợp 2: " << tapHopGiao << endl;

    return 0;
}
