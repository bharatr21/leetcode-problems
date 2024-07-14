class Solution {
public:
    int solve(vector<int>& dp, vector<int>& coins, int amount) {
        int res = 10005;
        if(amount == 0) return 0;
        else if(amount < 0) return 10005;
        else if(dp[amount] < 10005) return dp[amount];
        else {
            for(int coin: coins) {
                res = min(res, 1 + solve(dp, coins, amount - coin));
            }
        }
        return (dp[amount] = res);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 10005);
        dp[0] = 0;
        solve(dp, coins, amount);
        return ((dp[amount] > amount) ? -1: dp[amount]);
    }
};
