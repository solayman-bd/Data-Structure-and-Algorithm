#include <iostream>

class Stack {
private:
    int* data;
    int top;
    int capacity;

    void increaseSize() {
        int* newData = new int[capacity * 2];
        for (int i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= 2;
    }

public:
    Stack() {
        capacity = 10;
        data = new int[capacity];
        top = -1;
    }
    ~Stack() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    bool push(int value) {
        if (top >= capacity - 1) {
            increaseSize();
        }
        data[++top] = value;
        return true;
    }

    int pop() {
        if (top < 0) {
            return -1;
        }
        return data[top--];
    }

    int getTop() {
        if (top < 0) {
            return -1;
        }
        return data[top];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    std::cout << s.getTop() << std::endl; // Outputs 2
    s.pop();
    std::cout << s.getTop() << std::endl; // Outputs 1
    return 0;
}
