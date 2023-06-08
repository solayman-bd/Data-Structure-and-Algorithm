#include<bits/stdc++.h>
using namespace std;

long long arr[101]={0};

long long fib(long long n)
{
    if(n<=2) return 1;
    //check if fib(n) is already calculated
    if(arr[n]!=0)
    {
        return arr[n];
    }
    arr[n]=fib(n-1)+fib(n-2);
    return arr[n];
}
int main()
{
    cout<<fib(1)<<"\n";
    cout<<fib(50)<<"\n";

    return 0;
}


// complexity: 2^n to n
