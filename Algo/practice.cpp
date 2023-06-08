#include<bits/stdc++.h>
using namespace std;


int count_digit(long long x) {
    int cnt = 0;
    while (x) {
        x = x / 10;
        cnt++;
    }
    return cnt;
}

int solve_with_bfs(long long n, long long x) {
    queue<long long> q;
    unordered_set<long long> ops;
    q.push(x);
    ops.insert(x);
    int operations = 0;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            long long current = q.front();
            q.pop();

            if (count_digit(current) == n) {
                return operations;
            }

            long long temp = current;
            while (temp) {
                int dig = temp % 10;
                temp = temp / 10;
                if (dig != 0 && ops.find(dig * current) == ops.end()) {
                    q.push(dig * current);
                    ops.insert(dig * current);
                }
            }
        }
        operations++;
    }

    return -1;
}

int main() {
    long long n, x;
    cin >> n >> x;
    int result = solve_with_bfs(n, x);
    cout << result << endl;
    return 0;
}
