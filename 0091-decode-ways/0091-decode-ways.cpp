class Solution {
public:
    int helper(vector<int>& dp, string s, int idx) {
        int n = s.size(), res;
        if(dp[idx] != -1) return dp[idx];
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;
        if(idx == n - 1) return 1;
        res = helper(dp, s, idx+1);
        if(stoi(s.substr(idx, 2)) <= 26) {
            res += helper(dp, s, idx+2);
        }
        return (dp[idx] = res);
    }
    int numDecodings(string s) {
        int n = s.size(), i;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = (s[0] != '0');
        for(i = 2; i < n+1; i++) {
            if(s[i-1] != '0') dp[i] = dp[i-1];
            int two_digits = stoi(s.substr(i-2, 2));
            if(two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};