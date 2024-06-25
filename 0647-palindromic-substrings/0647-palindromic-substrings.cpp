class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), i, j, res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(i = 0; i < n; i++) {dp[i][i] = true; res += dp[i][i];}
        for(i = 0; i < n-1; i++) {dp[i][i+1] = (s[i] == s[i+1]); res += dp[i][i+1];}
        for(int len = 3; len <= n; len++)
        {
            for(i = 0; i < n - len + 1; i++)
            {
                j = i + len - 1;
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                res += dp[i][j];
            }
        }
        return res;
    }
};