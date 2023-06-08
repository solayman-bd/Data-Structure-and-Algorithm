
#include <bits/stdc++.h>
using namespace std;
const int N = 2002;

int maze[N][N] = {};
int visited[N][N];
int level[N][N];
pair<int, int> parent[N][N];
int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1)
    {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src)
{

    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                parent[new_x][new_y] = {x, y};
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    pair<int, int> src, dst;
    dst = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            level[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == '#')
            {
                maze[i][j] = -1;
            }
            else if (input[j] == 'A')
            {
                src = {i, j};
            }
        }
    }

    // for(int i = 0 ; i < n ; i++) {
    //     for(int j = 0; j < m ; j++) {
    //         cout<<maze[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    bfs(src);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && maze[i][j] == 0 && visited[i][j] == 1)
            {
                dst = {i, j};
            }
        }
    }

    if (dst.first != -1 && dst.second != -1)
    {

        if (level[dst.first][dst.second] == -1)
        {
            cout << "NO" << endl;
        }
        else
        {

            cout << "YES" << endl;
            cout << level[dst.first][dst.second] << endl;
        }
        vector<pair<int, int>> path;
        pair<int, int> selected_node = dst;
        while (true)
        {
            path.push_back(selected_node);
            if (selected_node == src)
            {
                break;
            }
            selected_node = parent[selected_node.first][selected_node.second];
        }
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); i++)
        {
            int curr_x = path[i].first;
            int curr_y = path[i].second;
            int prev_x = path[i - 1].first;
            int prev_y = path[i - 1].second;

            if (curr_x < prev_x)
            {
                cout << "U";
            }
            else if (curr_x > prev_x)
            {
                cout << "D";
            }
            else if (curr_y < prev_y)
            {
                cout << "L";
            }
            else if (curr_y > prev_y)
            {
                cout << "R";
            }
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
