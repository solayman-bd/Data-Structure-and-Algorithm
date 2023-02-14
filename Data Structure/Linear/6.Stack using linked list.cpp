
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;
public:
    Stack()
    {
        top = nullptr;
    }
    ~Stack()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int getTop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    cout<< s.getTop() <<"\n";
    s.pop();
    cout << s.getTop() <<"\n";
    return 0;
}
