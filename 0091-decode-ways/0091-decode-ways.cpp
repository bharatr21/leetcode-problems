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
        vector<int> dp(n+1, -1);
        return helper(dp, s, 0);
    }
};