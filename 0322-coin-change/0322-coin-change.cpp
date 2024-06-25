class Solution {
public:
    // int solve(vector<int>& coins, int amount, vector<int>& dp) {
    //     int n = coins.size(), i, res = 10001;
    //     if(amount < 0) return 10001;
    //     else if(amount == 0) return 0;
    //     else if(dp[amount] != 10001) return dp[amount];
    //     else {
    //         for(i = 0; i < n; i++) {
    //             res = min(res, 1 + solve(coins, amount - coins[i], dp));
    //         }
    //         dp[amount] = res;
    //         return res;
    //     }
    // }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 5, amount + 1);
        int n = coins.size(), i, j;
        dp[0] = 0;
        for(i = 1; i <= amount; i++)
        {
            for(j = 0; j < n;j++)
            {
                if(coins[j] <= i)
                {
                    int rem = i - coins[j];
                    dp[i] = min(dp[i], 1 + dp[rem]);
                }
            }
        }
        return ((dp[amount] > amount) ? -1: dp[amount]);
    }
};