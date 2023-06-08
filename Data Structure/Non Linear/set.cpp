#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st;
    //insert O(logn)
    st.insert(5);
    st.insert(7);
    st.insert(4);
    st.insert(5);
    st.insert(9);
    cout<<"Printing set:\n";
    //Print O(n)
    for(auto i:st)
        cout<< i<<" ";
    cout<<"\n";
    cout<<"Size:\n";
    //size o(1)
    cout<< st.size();
    cout<<"\n";
    cout<<"Printing set:\n";
    for(auto it= st.begin(); it!=st.end(); it++)
    {
        cout << *it<<" ";
    }
    cout<<"\n";
    //erase o(logn)
    st.erase(5);

    //find O(logn)

    if(st.find(100)!=st.end()) //whether the value is present or not. Returns a iterator of the value that contains the location
    {
        cout<<"The val is found";
    }
    else

    {
        cout<< "Val not found";
    }
    return 0;
}
