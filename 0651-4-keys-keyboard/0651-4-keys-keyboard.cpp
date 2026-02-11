class Solution {
public:
    int maxA(int n) {
        if(n <= 5) return n;
        vector<int> dp(n+1, 0);
        for(int i = 0; i <= 5; i++) dp[i] = i;
        for(int i = 6; i <= n; i++) {
            dp[i] = max(3 * dp[i-4], 4 * dp[i-5]);
        }
        return dp[n];
    }
};