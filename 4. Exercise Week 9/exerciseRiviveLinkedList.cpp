#include <iostream>

using namespace std;

// Define a Node struct to represent each element in the linked list
struct Node {
    int data;
    Node* next;
};

// Define a SET struct to represent the set
struct SET {
    Node* head;

    // Initialize an empty set
    SET() {
        head = nullptr;
    }

    // Add an element to the set
    void add(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Remove an element from the set
    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Check if an element is in the set
    bool contains(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Access an element at index i in the set
    int operator[](int i) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == i) {
                return current->data;
            }
            count++;
            current = current->next;
        }
        throw out_of_range("Index out of range");
    }

    // Assignment operator
    SET& operator=(const SET& other) {
        if (this == &other) {
            return *this;
        }

        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = other.head;
        while (current != nullptr) {
            add(current->data);
            current = current->next;
        }

        return *this;
    }
};

// Overload the << operator to print the contents of the set
ostream& operator<<(ostream& os, const SET& set) {
    Node* current = set.head;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

int main() {
    SET set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    SET set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);

    cout << "Set 1: " << set1 << endl;

    set1.add(5);
    cout << "Set 1 after adding 5: " << set1 << endl;

    bool contains3 = set1.contains(3);
    cout << "Set 1 contains 3: " << contains3 << endl;

    set1.remove(2);
    cout << "Set 1 after removing 2: " << set1 << endl;

    int element = set1[1];
    cout << "Element at index 1 in set1: " << element << endl;

    SET unionSet, differenceSet, intersectionSet;

    for (int i = 0; i < 3; i++) {
        unionSet.add(set1[i]);
        differenceSet.add(set1[i]);
        intersectionSet.add(set1[i]);
    }

    for (int i = 0; i < 3; i++) {
        unionSet.add(set2[i]);
        differenceSet.remove(set2[i]);
        if (!set2.contains(set1[i])) {
            intersectionSet.remove(set1[i]);
        }
    }

    cout << "Union of set1 and set2: " << unionSet << endl;
    cout << "Difference of set1 and set2: " << differenceSet << endl;
    cout << "Intersection of set1 and set2: " << intersectionSet << endl;

    return 0;
}
