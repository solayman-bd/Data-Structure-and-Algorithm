#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Queue
{
public:
    T *a;
    int array_cap;
    int l,r;
    int sz;
    Queue()
    {
        a= new T[1];
        array_cap=1;
        l=0;
        r=-1;
        sz=0;
    }
    void remove_circular()
    {
        if(l>r)
        {
            T *tmp= new T[sz];
            int indx=0;
            for(int i=l; i<array_cap; i++)
            {
                tmp[indx]=a[i];
                indx++;
            }
            for(int i=0; i<=r; i++)
            {
                tmp[indx]=a[i];
                indx++;
            }
            swap(tmp,a);
            l=0;
            r=sz-1;
            delete [] tmp;
        }
    }

    void increase_size()
    {
        remove_circular();
        T *tmp= new T[array_cap*2];
        for(int i=0; i<array_cap; i++)
        {
            tmp[i]=a[i];
        }
        swap(a,tmp);
        array_cap=array_cap*2;
        delete []tmp;
    }
    void enqueue(T val)
    {
        if(sz==array_cap)
        {
            increase_size();
        }
        r++;
        if(r==array_cap)
        {
            r=0;
        }

        a[r]=val;
        sz++;
    }
    void dequeue()
    {
        if(sz==0)
        {
            cout << "Queue is empty\n";
            return;
        }
        l++;
        if(l==array_cap)
        {
            l=0;
        }
        sz--;
    }
    T front()
    {
        if(sz==0)
        {
            cout << "Queue is empty\n";
            return T();
        }
        return a[l];
    }
    int size()
    {
        return sz;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout<<"Size:"<<q.size()<<"\n";
    cout<<"Front:"<<q.front()<<"\n";
    q.dequeue();
    cout<<"Front:"<<q.front()<<"\n";

}
