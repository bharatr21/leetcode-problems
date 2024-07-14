class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 10005);
        int i;
        dp[0] = 0;
        for(i = 1; i <= amount; i++) {
            for(int coin: coins) {
                if(coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        return ((dp[amount] > amount) ? -1: dp[amount]);
    }
};