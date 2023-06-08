#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<string> building;
vector<vector<bool>> visited;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int dfs(int x, int y) {
    if (visited[x][y]) return 0;
    visited[x][y] = true;
    int area = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny) && !visited[nx][ny] && building[nx][ny] == '.') {
            area += dfs(nx, ny);
        }
    }
    return area;
}
int main() {
    cin >> n >> m;
    building.resize(n);
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        cin >> building[i];
    }
    int rooms = 0;
    int longest_room = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && building[i][j] == '.') {
                int room_size = dfs(i, j);
                longest_room = max(longest_room, room_size);
                rooms++;
            }
        }
    }
    cout << "Rooms - " << rooms << endl;
    cout << "Length of the longest room - " << longest_room << endl;
    return 0;
}
