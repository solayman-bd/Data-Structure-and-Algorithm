// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     vector<vector<int>> adj_matrix(n, vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> adj_matrix[i][j];
//         }
//     }

//     // print the adjacency matrix
//     cout << "Adjacency matrix:" << endl;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cout << adj_matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//<-------------Alternate------------->

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> convertToAdjList(vector<vector<int>>& adj_matrix) {
    int n = adj_matrix.size();
    vector<vector<int>> adj_list(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(adj_matrix[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    return adj_list;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> adj_matrix;
    for(int i=0;i<n;i++) {
        vector<int> row;
        for(int j=0;j<n;j++) {
            int inp;
            cin >> inp;
            row.push_back(inp);
        }
        adj_matrix.push_back(row);
    }


    vector<vector<int>> adj_list = convertToAdjList(adj_matrix);

   
    for(int i=0;i<n;i++) {
        cout << i << ": ";
        for(int j=0;j<adj_list[i].size();j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

