/*
Graph Representation
====================
Topic: Adjacency Matrix ->2d array

0----1
    /  \
    2---3
#total nodes=4
#total edges=4
#undirected+unweighted

#matrix-> no of nodes* no of nodes
        ->4*4
matrix[i][j]=1
    if and only if (i->j) single edge
0->1
1->0
1->2
2->1
2->3
3->2
3->1
1->3
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes=4;


    int matrix[nodes][nodes]; //O(n^2)
     for(int i=0; i<nodes; i++)
    {
        for(int j=0;j<nodes;j++)
        {
           matrix[i][j]=0;
        }
        cout<<endl;
    }

    for(int i=0; i<nodes; i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
