// problem:https://cses.fi/problemset/task/1667
// Example

// Input:
// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4

// Output:
// 3
// 1 4 5


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int level[N];
int parent[N];
vector<int> adj_list[N];

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    parent[src] = -1;
    level[src] = 1; // new line
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                parent[adj_node] = head;
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1; // new line
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src_node = 1;
    bfs(src_node);
    int dest_node = n;
    if (visited[dest_node] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << level[dest_node] << "\n";
    vector<int> path;
    int selected_node = dest_node;

    while (true)
    {
        path.push_back(selected_node);
        if (selected_node == src_node)
        {
            break;
        }
        selected_node = parent[selected_node];
    }
    reverse(path.begin(), path.end());

    for(int node:path)
    {
        cout<< node<<" ";

    }
    cout<<"\n";


    return 0;
}