#include<bits/stdc++.h>

using namespace std;
template<class T>
class node
{
public:
    T data;
    node *prev;
    node *nxt;
};


template<class T>
class Deque
{
public:
    node<T> * head;
    node<T> *tail;
    int sz;
    int rev;
    Deque()
    {
        head=nullptr;
        tail=nullptr;
        sz=0;
        rev=0;
    }
    node<T> *CreateNewNode(T val)
    {
        node<T> *newNode= new node<T>;
        newNode->data=val;
        newNode->nxt=nullptr;
        newNode->prev= nullptr;
        return newNode;
    }

    void insertAtHead(T val)
    {
        node<T>* newNode= CreateNewNode(val);
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
    void insertAtTail(T val)
    {
        node<T>* newNode= CreateNewNode(val);
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
    void push_front(T val)
    {
        if(rev==0)
        {
            insertAtHead(val);
        }
        else
        {
            insertAtTail(val);
        }
    }
    //pushback O(1)
    void push_back(T val)
    {
        if(rev==0)
        {
            insertAtTail(val);
        }
        else
        {
            insertAtHead(val);
        }

    }
    void deleteLast()
    {

        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head= nullptr;
            tail=nullptr;
            sz--;
            return;
        }
        node<T> * a= tail;
        tail=tail->prev;
        delete a;
        tail->nxt=nullptr;
        sz--;
    }
    void deleteFirst()
    {

        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head= nullptr;
            tail=nullptr;
            sz--;
            return;
        }
        node<T> *a= head;
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
           deleteFirst();
        }
    }
    void pop_front()
    {
        if(rev==0)
        {
            deleteFirst();

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
    int getSize()
    {
        return sz;
    }
};

int isPalindrome(string s)
{
    Deque<char> d;
    for(int i=0;i<s.size();i++)
    {
        d.push_back(s[i]);
    }
    while(d.getSize()>1)
    {
        if(d.front()!=d.back())
        {
            return 0;
        }
        d.pop_front();
        d.pop_back();
    }
    return 1;
}
int main()
{

    string s;
    cin>>s;
    int ans=isPalindrome(s);
    if(ans!=1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;

}


