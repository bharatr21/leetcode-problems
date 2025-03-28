class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i = 0; i < k; i++) {
            dp[0][i] = costs[0][i];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < k; j++) {
                dp[i][j] = costs[i][j];
                int mn = 2001;
                for(int p = 0; p < k; p++) {
                    if(p != j) mn = min(mn, dp[i-1][p]);
                }
                dp[i][j] += mn;
            }
        }
        int res = 2001;
        for(int i = 0; i < k; i++) res = min(res, dp[n-1][i]);
        return res;
    }
};