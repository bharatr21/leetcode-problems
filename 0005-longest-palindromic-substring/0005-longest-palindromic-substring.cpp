class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), st = 0, mx = 1, i, j, len;
        string res = "";
        res += s[0];
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(i = 0; i < n; i++) dp[i][i] = true;
        for(i = 0; i < n - 1; i++) 
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                st = i;
                mx = 2;
            }
        }
        for(len = 2; len < n; len++)
        {
            for(i = 0; i < n - len; i++)
            {
                j = i + len;
                if(s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    st = i;
                    mx = len + 1;
                }
            }
        }
        return s.substr(st, mx);
    }
};