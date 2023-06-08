#include<bits/stdc++.h>
using namespace std;


int main()
{
   int n1,n2;
   cin>>n1;
   set<int>a;
   set<int>b;
   for(int i=0;i<n1;i++)
   {
       int inp;
       cin>>inp;
       a.insert(inp);
   }
   cin>>n2;
    for(int i=0;i<n2;i++)
   {
       int inp;
       cin>>inp;
       b.insert(inp);
   }
   set<int>un;
   for(auto it:a)
   {
      un.insert(it);
   }
   for(auto it:b)
   {
       un.insert(it);
   }
   for(auto it:un)
   {
       cout<<it<<" ";
   }

    return 0;
}
