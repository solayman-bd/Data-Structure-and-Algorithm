#include <bits/stdc++.h>

using namespace std;

vector<long long> dp; 

long long getMaxCoins(vector<int>& coins, int n) {
    if (n < 0) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    long long takeCurrent = coins[n] + getMaxCoins(coins, n - 2);
    long long skipCurrent = getMaxCoins(coins, n - 1);
    dp[n] = max(takeCurrent, skipCurrent);
    return dp[n];
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        int n;
        cin >> n;
        
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        
        if (n == 0) {
            cout << "Case " << test << ": 0" << endl;
            continue;
        }
        
        dp.assign(n, -1); 
        
        long long maxCoins = getMaxCoins(coins, n - 1);
        
        cout << "Case " << test << ": " << maxCoins << endl;
    }
    
    return 0;
}
