#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
class Queue
{
public:
    node *head;
    node *tail;
    int sz;

    Queue()
    {
        head= nullptr;
        tail= nullptr;
        sz=0;
    }
    node *      CreateNode( int val)
    {
        node * newNode= new node;
        newNode->data=val;
        newNode->next=nullptr;
    }
    void enqueue ( int val)
    {
        sz++;
        node *newNode= CreateNode(val);
        if(head==nullptr)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;//for interlinking
        tail=newNode;
    }
    void dequeue()
    {

        if(sz==0)
        {
            cout<<"Queue is empty\n";
            sz--;
            return;
        }
        if(sz==1)
        {
            delete head;
            head=nullptr;
            tail=nullptr;
            return;
        }
        node *a = head;
        head= head->next;
        sz--;
        delete a;
    }
    int front()
    {
        if(sz==0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return head->data;
    }
    int size()
    {
        return sz;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    cout<<"Front:"<<q1.front()<<"\n";
    q1.enqueue(20);
    cout<<"Front:"<<q1.front()<<"\n";
    q1.dequeue();
    q1.enqueue(5);
    cout<<"size:"<<q1.size()<<"\n";
    q1.enqueue(7);
    q1.enqueue(9);
    q1.enqueue(4);
    cout<<"size:"<<q1.size()<<"\n";
    return 0;
}
//o(1)
//enqueue
//dequeue
//front
//size
