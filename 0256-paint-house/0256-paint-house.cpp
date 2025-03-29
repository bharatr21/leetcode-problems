class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        for(int i = 0; i < 3; i++) dp[0][i] = costs[0][i];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                int res = 2001;
                for(int k = 0; k < 3; k++) {
                    if(j != k) res = min(res, dp[i-1][k]);
                }
                dp[i][j] = costs[i][j] + res;
            }
        }
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};