class Solution {
public:
    bool solve(vector<vector<int>>& dp, string s1, int idx1, string s2, int idx2, string s3, int idx3) {
        int m = s1.size(), n = s2.size(), t = s3.size();
        if(m + n != t) return false;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(idx3 == t && idx1 == m && idx2 == n) return true;
        if(idx1 == m) return s2.substr(idx2) == s3.substr(idx3);
        if(idx2 == n) return s1.substr(idx1) == s3.substr(idx3);
        bool res = false;
        res |= ((s3[idx3] == s1[idx1]) && solve(dp, s1, idx1 + 1, s2, idx2, s3, idx3 + 1));
        res |= ((s3[idx3] == s2[idx2]) && solve(dp, s1, idx1, s2, idx2 + 1, s3, idx3 + 1));
        return (dp[idx1][idx2] = res);
    }
    bool isInterleave(string s1, string s2, string s3) {
        string tmp;
        int m = s1.size(), n = s2.size(), t = s3.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(dp, s1, 0, s2, 0, s3, 0);
    }
};