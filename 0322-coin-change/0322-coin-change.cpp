class Solution {
public:
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