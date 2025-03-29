class Solution {
public:
    bool isValidString(int idx, int open, string s, vector<vector<int>>& dp) {
        if(idx == s.size()) return (open == 0);
        if(dp[idx][open] != -1) return dp[idx][open];
        bool res = false;
        if(s[idx] == '*') {
            res = res | isValidString(idx+1, open+1, s, dp);
            if(open) res = res | isValidString(idx+1, open-1, s, dp);
            res = res | isValidString(idx+1, open, s, dp);
        } else if(s[idx] == '(') {
            res = isValidString(idx+1, open+1, s, dp);
        } else if(open) {
            res = isValidString(idx+1, open-1, s, dp);
        }
        return (dp[idx][open] = res);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return isValidString(0, 0, s, dp);
    }
};