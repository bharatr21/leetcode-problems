class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), i, j;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> ans = {0, 0};
        for(i = 0; i < n; i++) dp[i][i] = true;
        for(i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                ans[0] = i;
                ans[1] = i + 1;
            }
        }

        for(int len = 2; len < n; len++)
        {
            for(i = 0; i < n - len; i++)
            {
                j = i + len;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        i = ans[0]; j = ans[1];
        return s.substr(i, j - i + 1);
    }
};