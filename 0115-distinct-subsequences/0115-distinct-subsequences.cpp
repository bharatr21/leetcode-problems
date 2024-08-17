class Solution {
public:
    int solve(vector<vector<int>>& dp, string s, int sidx, string t, int tidx) {
        int m = s.size(), n = t.size();
        if(sidx == m || tidx == n) {
            return ((tidx == n) ? 1 : 0);
        }
        if(dp[sidx][tidx] != -1) return dp[sidx][tidx];
        int res = 0;
        //Consider existing set as match + existing set as mismatch
        if(s[sidx] == t[tidx]) res += solve(dp, s, sidx + 1, t, tidx + 1);
        res += solve(dp, s, sidx + 1, t, tidx);
        return (dp[sidx][tidx] = res);
    }

    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(dp, s, 0, t, 0);
    }
};