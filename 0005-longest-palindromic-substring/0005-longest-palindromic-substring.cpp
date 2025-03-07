class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), mx = 1, st = -1, en = -1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {dp[i][i] = true; st = i; en = i;}
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                mx = 2;
                st = i;
                en = i+1;
            }
        }
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j <= n - i; j++) {
                int k = j + i - 1;
                if(dp[j + 1][k - 1] && s[j] == s[k]) {
                    dp[j][k] = true;
                    if(mx < i) {
                        mx = i;
                        st = j;
                        en = k;
                    }
                }
            }
        }
        return s.substr(st, en - st + 1);
    }
};