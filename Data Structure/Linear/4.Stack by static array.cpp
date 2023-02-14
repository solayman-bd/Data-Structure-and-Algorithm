#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool push(int value)
    {
        if (top >= MAX_SIZE - 1)
        {
            return false;
        }
        data[++top] = value;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            return -1;
        }
        return data[top--];
    }

    int getTop()
    {
        if (top < 0)
        {
            return -1;
        }
        return data[top];
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.getTop() << endl; // Outputs 2
    s.pop();
    cout << s.getTop() << endl; // Outputs 1
    return 0;
}
