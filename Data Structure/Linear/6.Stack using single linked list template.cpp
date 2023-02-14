#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node* next;
};

template<class T>
class Stack
{
private:
    Node<T>* top;
public:
    Stack()
    {
        top = nullptr;
    }
    ~Stack()
    {
        while (top != nullptr)
        {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T data)
    {
        Node<T>* newNode = new Node<T>();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (top == nullptr)
        {
            cout<<"Stack is empty!"<<"\n";
            return -1;
        }
        T data = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    T getTopValue()
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
    Stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.getTopValue() << "\n";
    s.pop();
    cout << s.getTopValue() << "\n";
    return 0;
}
