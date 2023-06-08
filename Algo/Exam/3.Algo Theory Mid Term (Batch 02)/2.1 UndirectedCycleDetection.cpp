#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src,vector<vector<int>>&adj_list,vector<bool>&vis,int parents)
{
    vis[src]=true;
    vector<int>::iterator it;
    for(it=adj_list[src].begin(); it!=adj_list[src].end(); it++)
    {
        if(*it!=parents)
        {
            if(vis[*it])
                return true;
            if(!vis[*it] && isCycle(*it,adj_list,vis,src))
                return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj_list(n);
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    bool cycle=false;
    vector<bool>vis(n,false);
    for(int i=0; i<n; i++)
    {
        if(!vis[i] && isCycle(i,adj_list,vis,-1))
            cycle=true;
    }
    if(cycle)
        cout<<"Cycle Exist"<<endl;
    else
        cout<<"No Cycle"<<endl;
    return 0;
}