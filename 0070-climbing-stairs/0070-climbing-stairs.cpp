class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> dp(n+1, 0);
        int i;
        dp[1] = 1;
        dp[2] = 2;
        for(i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};