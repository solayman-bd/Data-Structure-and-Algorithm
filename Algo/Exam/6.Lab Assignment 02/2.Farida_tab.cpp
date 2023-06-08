#include<bits/stdc++.h>

using namespace std;

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int testCase = 1; testCase <= numTestCases; testCase++) {
        int numMonsters;
        cin >> numMonsters;
        
        vector<int> monsterCoins(numMonsters);
        for (int i = 0; i < numMonsters; i++) {
            cin >> monsterCoins[i];
        }
        
        if (numMonsters == 0) {
            cout << "Case " << testCase << ": 0" << endl;
            continue;
        }
        
        vector<long long> dp(numMonsters);
        dp[0] = monsterCoins[0];
        
        if (numMonsters >= 2) {
            dp[1] = max(monsterCoins[0], monsterCoins[1]);
        }
        
        for (int i = 2; i < numMonsters; i++) {
            dp[i] = max(monsterCoins[i] + dp[i - 2], dp[i - 1]);
        }
        
        cout << "Case " << testCase << ": " << dp[numMonsters - 1] << endl;
    }
    
    return 0;
}