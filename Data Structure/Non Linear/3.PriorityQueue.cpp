#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int>nodes;
    MaxHeap()
    {

    }
    //O(logn)
    void UpHeapify(int indx)
    {
        while (indx>0 && nodes[indx]>nodes[(indx-1)/2])
        {
            swap(nodes[indx],nodes[(indx-1)/2]);
            indx=(indx-1)/2;
        }
    }
    //O(1)
    void Insert(int x)
    {
        nodes.push_back(x);
        UpHeapify(nodes.size()-1);
    }
    //O(n)
    void PrintHeap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }
    void down_heapify(int indx)
    {
        while(1)
        {
            int largest= indx;
            int l=2*indx+1;
            int r=2*indx+2;
            if(l<nodes.size() && nodes[largest]<nodes[l])
            {
                largest=l;
            }
            if(r<nodes.size() && nodes[largest]<nodes[r])
            {
                largest=r;
            }
            if(largest==indx)
            {
                break;
            }
            swap(nodes[indx],nodes[largest]);
            indx=largest;
        }
    }
    void Delete (int indx)
    {
        if(indx>=nodes.size())
            return;
        swap(nodes[indx],nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(indx);
    }

    int GetMax()
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty..\n";
            return -1;
        }
        return nodes[0];
    }
    int ExtractMax() //return and delete max element. O(logn)
    {
        if(nodes.empty())
        {
            cout<<"Heap is empty..\n";
            return -1;
        }
        int ret=nodes[0];
        Delete(0);
        return ret;
    }

    void BuildFromArray(vector<int>&a)
    {
        nodes=a;
        int n= nodes.size();
        int last_non_leaf= n/2-1;
        for(int i=last_non_leaf; i>=0; i--)
        {
            down_heapify(i);
        }
    }
    int GetSize()
    {
        return nodes.size();
    }

};
vector<int> HeapSort(vector<int>a)
{
    MaxHeap h;
    h.BuildFromArray(a);
    vector<int> ans;
    for(int i=0; i<a.size(); i++)
    {
        ans.push_back(h.ExtractMax());
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


class PriorityQueue //Difference between queue and Priority Queue: served based on the most priority means max value holder will get service first
{
public:
    MaxHeap h;
    PriorityQueue()
    {

    }
    void Push(int x)
    {
        h.Insert(x);
    }
    void Pop()
    {
        h.Delete(0);
    }
    int Top()
    {
        return h.GetMax();
    }
    int Size()
    {
        return h.GetSize();
    }

};
int main()
{
    PriorityQueue pq;
    pq.Push(5);
    pq.Push(7);
    pq.Push(20);
    pq.Push(12);
    pq.Push(3);

    while(pq.Size()!=0)
    {
        cout<<pq.Top()<<" ";
        pq.Pop();
    }
    return 0;
}
