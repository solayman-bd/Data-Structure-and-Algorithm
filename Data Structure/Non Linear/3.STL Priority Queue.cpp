#include<bits/stdc++.h>
using namespace std;

int getDigit(int x)
{
    int c=0;
    while(x!=0)
    {
        x=x/10;
        c++;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    priority_queue<int>pq1;
    priority_queue<int>pq2;
    for(int i=0; i<n; i++)
    {
        pq2.push(b[i]);
        pq1.push(a[i]);
    }
    int ans=0;
    while(pq1.size()!=0)
    {
        int x= pq1.top();
        int y=pq2.top();
        if(x==y)
        {
            pq1.pop();
            pq2.pop();
            continue;
        }
        ans++;

        if(x>y)
        {
            pq1.pop();
            pq1.push(getDigit(x));

        }
        else
        {
            pq2.pop();
            pq2.push(getDigit(y));
        }

    }
    cout<<ans<<"\n";
    return 0;
}
