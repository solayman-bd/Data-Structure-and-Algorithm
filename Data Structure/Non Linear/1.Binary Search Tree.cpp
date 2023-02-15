#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node* left;
    node* right;
    node* parent;// not important for binary search tree
};

class BST
{
public:
    node* root;
    BST()
    {
        root=nullptr;
    }
    node* createNewNode(int val)
    {
        node* newNode= new node;
        newNode->val=val;
        newNode->left=nullptr;
        newNode->right=nullptr;
        return newNode;
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
                l=a->left->val;
                q.push(a->left);
            }
            if(a->right!=nullptr)
            {
                r=a->right->val;
                q.push(a->right);
            }

            cout<<"Node Value="<<a->val<<" Left Child = "<<l;
            cout<<" Right Child = "<<r<<"\n";
        }
    }
    void Insert( int val)
    {
        node* newNode= createNewNode(val);
        if(root==nullptr)
        {
            root=newNode;
            return;
        }
        node* cur= root;
        node* prv= nullptr;
        while(cur!= nullptr)
        {
            if(newNode->val>cur->val)
            {
                prv=cur;
                cur=cur->right;
            }
            else
            {
                prv=cur;
                cur=cur->left;
            }
        }
        if(newNode->val>prv->val)
        {
            prv->right=newNode;
        }
        else
        {
            prv->left=newNode;
        }
    }
    bool Search(int val)
    {
        node* cur = root;
        while(cur!= nullptr)
        {
            if(val>cur->val)
            {
                cur=cur->right;

            }
            else if(val<cur->val)
            {
                cur=cur->left;
            }
            else
            {
                return true;
            }
        }
        return false;
    }


    void Delete(int val)
    {
        node* cur= root;
        node* prv= nullptr;
        while(cur!=nullptr)
        {
            if(val>cur->val)
            {
                prv= cur;
                cur= cur->right;
            }
            else if(val<cur->val)
            {
                prv=cur;
                cur= cur->left;
            }
            else
            {
                break;
            }
        }
        if(cur==nullptr)
        {
            cout<<"Value not found\n";
        }
        //case 1: both child are null
        if(cur->left==nullptr && cur->right==nullptr)
        {
            if(prv->left!=nullptr&&prv->left->val==cur->val)
            {
                prv->left=nullptr;
            }
            else
            {
                prv->right= nullptr;
            }
            delete cur;
            return;
        }
        //case 2: Node has one child
        if(cur->left==nullptr && cur->right!=nullptr)
        {
            if(prv->left!=nullptr&&prv->left->val==cur->val)
            {
                prv->left=cur->right;
            }
            else
            {
                prv->right= cur->right;
            }
            delete cur;
            return;
        }
        if(cur->left!=nullptr && cur->right==nullptr)
        {
            if(prv->left!=nullptr&&prv->left->val==cur->val)
            {
                prv->left=cur->left;
            }
            else
            {
                prv->right= cur->left;
            }
            delete cur;
            return;
        }
        //case 3: node has two child
        node *tmp= cur->right;
        //finding the min value in the right
        while(tmp->left!=nullptr)
        {
            tmp=tmp->left;
        }
        int saved = tmp->val;
        Delete(saved);
        cur->val=saved;
    }
};


int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    //case 1
    //bst.Delete(8);
    // bst.BFS();
    //case 2
    //bst.Delete(7);
    //bst.BFS();
    //case 3
    bst.Delete(6);
    bst.BFS();

    return 0;
}
