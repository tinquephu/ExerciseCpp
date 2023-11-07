#include <iostream>
#include <string>
using namespace std;
class Stack {
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    Stack(const Stack& other) {
        capacity = other.capacity;
        data = new int[capacity];
        top = other.top;
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return data[top--];
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }
};

string decimalToHex(int decimal) {
    Stack hexStack(32);

    while (decimal > 0) {
        int remainder = decimal % 16;
        hexStack.push(remainder);
        decimal /= 16;
    }

    string hexValue = "";
    while (!hexStack.isEmpty()) {
        int digit = hexStack.pop();
        if (digit < 10) {
            hexValue += to_string(digit);
        } else {
            char hexDigit = 'A' + (digit - 10);
            hexValue += hexDigit;
        }
    }

    return hexValue;
}

int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    string hexValue = decimalToHex(decimalNumber);

    cout << "Hexadecimal value: 0x" << hexValue << endl;

    return 0;
}
