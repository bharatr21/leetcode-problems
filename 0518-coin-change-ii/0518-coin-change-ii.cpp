class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i = 1; i <= amount; i++) dp[n][i] = 0;
        dp[n][0] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                if(j < coins[i]) dp[i][j] = dp[i+1][j];
                else dp[i][j] = dp[i][j - coins[i]] + dp[i+1][j];
            }
        }
        return dp[0][amount];
    }
};