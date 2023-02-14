#include<bits/stdc++.h>

//superset of queue and stack
//double ended queue

//o(n)->complexity for all operation
//Operations:
//push back
//push front
//pop back
//pop front
//front
//back
//size
//reverse


//Deque using double linked list. Not possible by single linked list
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *nxt;
};

class Deque
{
public:
    node * head;
    node *tail;
    int sz;
    int rev;
    Deque()
    {
        head=nullptr;
        tail=nullptr;
        sz=0;
        rev=0;
    }
    node *CreateNewNode(int val)
    {
        node *newNode= new node;
        newNode->data=val;
        newNode->nxt=nullptr;
        newNode->prev= nullptr;
        return newNode;
    }

    void inserAtHead(int val)
    {
        node* newNode= CreateNewNode(val);
        if(sz==0)
        {
            head=newNode;
            tail=newNode;
            sz++;
            return;
        }
        head->prev=newNode;
        newNode->nxt=head;
        head=newNode;
        sz++;
    }
    void insertAtTail(int val)
    {
        node* newNode= CreateNewNode(val);
        if(sz==0)
        {
            head=newNode;
            tail=newNode;
            sz++;
            return;
        }
        tail->nxt=newNode;
        newNode->prev=tail;
        tail=newNode;
        sz++;
    }
    //pushFront O(1)
    void push_front(int val)
    {
        if(rev==0)
        {
            inserAtHead(val);
        }
        else
        {
            insertAtTail(val);
        }
    }
    //pushback O(1)
    void push_back(int val)
    {
        if(rev==0)
        {
            insertAtTail(val);
        }
        else
        {
            inserAtHead(val);
        }

    }
    void deleteLast()
    {

        if(sz==0)
        {
            cout<<"Dequeu is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head= nullptr;
            tail=nullptr;
            sz--;
        }
        node * a= tail;
        tail=tail->prev;
        delete a;
        tail->nxt=nullptr;
        sz--;
    }
    void delete_first()
    {

        if(sz==0)
        {
            cout<<"Dequeu is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head= nullptr;
            tail=nullptr;
            sz--;
        }
        node *a= head;
        head=head->nxt;
        delete a;
        head->prev=nullptr;
        sz--;
    }
    void pop_back()
    {
        if(rev==0)
        {
            deleteLast();
        }
        else
        {
            delete_first();
        }
    }
    void pop_front()
    {
        if(rev==0)
        {
            delete_first();

        }
        else
        {
            deleteLast();
        }
    }
    int front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        if(rev==0)
        {
            return head->data;

        }
        else
        {
            return tail->data;
        }
    }
    int back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        if(rev==0)
        {
            return tail->data;

        }
        else
        {
            return head->data;
        }
    }
    void reverse_deq()
    {
        if(rev==0)
        {
            rev=1;
        }
        else
        {
            rev =0;
        }
    }
};
int main()
{
    Deque d;
    d.push_back(5);
    d.push_back(12);
    d.push_back(9);
    d.push_back(6);
    d.push_back(4);
    d.push_back(7);
    d.push_back(2);
    cout<<"Back :"<<d.back()<<" Front : "<<d.front()<<"\n";
    d.reverse_deq();
    cout<<"Back :"<<d.back()<<" Front : "<<d.front()<<"\n";
    return 0;

}


