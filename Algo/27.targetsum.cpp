//https://leetcode.com/problems/target-sum/
#include <bits/stdc++.h>
using namespace std;

const int max_n = 2 * 1e5 + 5;


int dp[max_n];

int find_pair(vector<int>& arr, int x, int idx) {
    if (idx < 0)
        return -1;

    if (dp[idx] != -1)
        return dp[idx];

    int complement = x - arr[idx];
    for (int i = 0; i < idx; i++) {
        if (arr[i] == complement)
            return dp[idx] = i;
    }

    return dp[idx] = find_pair(arr, x, idx - 1);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < max_n; i++) {
        dp[i] = -1;
    }

    int idx = find_pair(arr, x, n - 1);

    if (idx != -1) {
        cout << idx + 1 << " " << n << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
