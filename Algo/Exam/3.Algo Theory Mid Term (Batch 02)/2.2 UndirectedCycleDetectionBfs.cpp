#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int parent[N]={-1};
vector<int> adj_list[N];

bool bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]) {
            if (visited[adj_node] == 0) {
                visited[adj_node] = 1;
                parent[adj_node] = head;
                q.push(adj_node);
            } else if (adj_node != parent[head]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0;i < edges;i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 1;

    if (bfs(src)) {
        cout << "Cycle Exist" << endl;
    } else {
        cout << "No Cycle" << endl;
    }
    return 0;
}
