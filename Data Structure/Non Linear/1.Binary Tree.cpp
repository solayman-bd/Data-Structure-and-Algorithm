
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
    node *left;
    node *right;
    node *parent;
};

class BinaryTree
{
public:
    node *root;
    BinaryTree()
    {
        root = nullptr;
    }
    node * createNewNode(int id, int value)
    {
        node *newNode= new node;
        newNode->id=id;
        newNode->left= nullptr;
        newNode->right= nullptr;
        newNode->parent= nullptr;
        newNode->value=value;
        return newNode;

    }
    void insertion(int id, int value)
    {
        node * newNode= createNewNode(id, value);
        if(root==nullptr)
        {
            root=newNode;
            return;
        }

        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            node *a = q.front();
            q.pop();

            if(a->left!=nullptr)
            {
                q.push(a->left);
            }
            else
            {
                a->left=newNode;
                newNode->parent=a;
                return;
            }
            if(a->right!=nullptr)
            {
                q.push(a->right);
            }
            else
            {
                a->right= newNode;
                newNode->parent=a;
                return;
            }
        }
    }
    void BFS()
    {
        if(root==nullptr)
            return;
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            node *a = q.front();
            q.pop();
            int p=-1, l=-1,r=-1;
            if(a->left!=nullptr)
            {
                l=a->left->id;
                q.push(a->left);
            }
            if(a->right!=nullptr)
            {
                r=a->right->id;
                q.push(a->right);
            }
            if(a->parent!=nullptr)
            {
                p=a->parent->id;
            }
            cout<<"Node id="<<a->id<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<" Parent id= "<<p<<"\n";
        }
    }
    void DFSPreOrder(node *a)
    {
        if(a==nullptr)
        {
            return;
        }
        cout<<a->id<<" ";
        DFSPreOrder(a->left);
        DFSPreOrder(a->right);
    }
    void DFSInOrder(node *a)
    {
        if(a==nullptr)
        {
            return;
        }
        DFSInOrder(a->left);
        cout<<a->id<<" ";
        DFSInOrder(a->right);
    }
    void DFSInPostOrder(node *a)
    {
        if(a==nullptr)
        {
            return;
        }
        DFSInPostOrder(a->left);
        DFSInPostOrder(a->right);
        cout<<a->id<<" ";
    }
    //by dfs
    void search(node* a, int val)
    {
        if(a==nullptr)
        {
            return;
        }
        if(a->value==val)
        {
            cout<<a->id<<" ";
        }
        search(a->left,val);
        search(a->right, val);
    }
};
int main()
{
    BinaryTree bt;
    cout<<"Insertion: \n";
    bt.insertion(0,5);
    bt.insertion(1,10);
    bt.insertion(2,10);
    bt.insertion(3,9);
    bt.insertion(4,8);
    bt.insertion(5,5);
    bt.BFS();
    cout<<"Searching: \n";
    bt.search(bt.root,5);
     cout<<"\n";
    bt.search(bt.root,10);
    return 0;
}
