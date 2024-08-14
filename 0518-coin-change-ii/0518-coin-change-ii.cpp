class Solution {
public:
    int solve(vector<vector<int>>& dp, int amount, int idx, vector<int>& coins) {
        int n = coins.size();
        if(idx == n) {
            return ((amount == 0) ? 1 : 0);
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int res = 0;
        if(amount < coins[idx]) res = solve(dp, amount, idx+1, coins);
        else res = solve(dp, amount - coins[idx], idx, coins) + solve(dp, amount, idx+1, coins);
        return (dp[idx][amount] = res);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(dp, amount, 0, coins);
    }
};